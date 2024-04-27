#define Z0_USE_NAMESPACE
#include "z0_str.h"

#include <malloc.h>
#include <string.h>

#define Z0_MALLOC	malloc
#define Z0_REALLOC 	realloc
#define Z0_FREE 	free

void
str_ref(struct str_ref *str, usize len, const s8 *buf)
{
	str->len = len;
	str->ptr = (s8*)buf;
}

void
str_ref_lit(struct str_ref *str, const char *buf)
{
	str->len = strlen(buf);
	str->ptr = (s8*)buf;
}

void
str_ref_s32(struct str_ref *str, s32 *num)
{
	*num = 0;
	for (usize i = 0; i < str->len; ++i) {
		*num *= 10;
		*num += str->ptr[i] - '0';
	}
}

usize
str_new(struct str *str, usize len, const s8 *buf)
{
	str->cap = len;
	str->len = len;
	str->ptr = Z0_MALLOC(len);
	if (str->ptr == NULL) {
		return STR_STS_MEM;
	}

	memcpy(str->ptr, buf, len);

	return STR_STS_OK;
}

usize
str_new_lit(struct str *str, const i8 *buf)
{
	str->cap = strlen(buf);
	str->len = str->cap;
	str->ptr = Z0_MALLOC(str->cap);
	if (str->ptr == NULL) {
		return STR_STS_MEM;
	}

	memcpy(str->ptr, buf, str->len);

	return STR_STS_OK;
}

usize
str_new_cap(struct str *str, usize cap)
{
	str->cap = cap;
	str->len = 0;
	str->ptr = Z0_MALLOC(cap);
	if (str->ptr == NULL) {
		return STR_STS_MEM;
	}

	return STR_STS_OK;
}

void
str_del(struct str *str)
{
	Z0_FREE(str->ptr);
}

static usize
str_chk(struct str *str)
{
	usize len;
	len = str->len;

	while (len >= str->cap) {
		str->cap *= 3;
		str->cap /= 2;

		s8 *ptr;
		ptr = Z0_REALLOC(str->ptr, str->cap);
		if (ptr == NULL) {
			return STR_STS_MEM;
		}

		str->ptr = ptr;
	}

	return STR_STS_OK;
}

usize
str_cat(struct str *str, usize len, const s8 *buf)
{
	if (len == 0)
		return STR_STS_OK;

	usize len_old;
	len_old = str->len;

	usize sts;
	sts = str_len(str, str->len + len);
	if (STS_ERR(sts))
		return sts;

	memcpy(str->ptr + len_old, buf, len);
	return STR_STS_OK;
}

usize
str_pos(struct str *str, usize *pos, usize len, const s8 *buf)
{
	if (len > str->len)
		return STR_STS_NF;

	for (usize i = 0; i < (str->len - len); ++i) {
		if (memcmp(str->ptr + i, buf, len) == 0) {
			*pos = i;
			break;
		}
	}

	return STR_STS_OK;
}

usize
str_pos_off(struct str *str, usize *pos, usize off, usize len, const s8 *buf)
{
	if (len > (str->len - off))
		return STR_STS_NF;

	for (usize i = off; i < (str->len - len); ++i) {
		if (memcmp(str->ptr + i, buf, len) == 0) {
			*pos = i;
			break;
		}
	}

	return STR_STS_OK;
}

usize
str_len(struct str *str, usize len)
{
	str->len = len;

	usize sts;
	sts = str_chk(str);
	if (STS_ERR(sts)) {
		return sts;
	}

	return STR_STS_OK;
}

