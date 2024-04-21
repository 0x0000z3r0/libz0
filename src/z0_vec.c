#define Z0_USE_NAMESPACE
#include "z0_vec.h"

#include <malloc.h>
#include <string.h>

#define Z0_MALLOC	malloc
#define Z0_REALLOC 	realloc
#define Z0_FREE 	free

static usize
vec_chk(struct vec* vec)
{
	if (vec->len >= vec->cap) {
		vec->cap *= 2;

		void *data;
		data = Z0_REALLOC(vec->data, vec->size * vec->cap);
		if (data == NULL) {
			return VEC_STS_MEM;
		}

		vec->data = data;
	}

	return VEC_STS_OK;
}

usize
vec_new(struct vec *vec, usize size)
{
	vec->cap = 4;
	vec->len = 0;

	vec->size = size;

	vec->data = Z0_MALLOC(vec->size * vec->cap);
	if (vec->data == NULL) {
		return Z0_VEC_STS_MEM;
	}

	return VEC_STS_OK;
}

void
vec_del(struct vec *vec)
{
	Z0_FREE(vec->data);
}

usize
vec_add(struct vec *vec, void *ent)
{
	usize sts;
	sts = vec_chk(vec);
	if (Z0_STS_ERR(sts)) {
		return sts;
	}

	u8 *ptr;
	ptr = vec->data;

	memcpy(ptr + vec->len * vec->size, ent, vec->size);
	++vec->len;

	return VEC_STS_OK;
}

usize
vec_ref(struct vec *vec, usize idx, void **ent)
{
	if (idx >= vec->len) {
		return VEC_STS_NF;
	}

	u8 *ptr;
	ptr = vec->data;

	*ent = ptr + idx * vec->size;

	return VEC_STS_OK;
}

usize
vec_get(struct vec *vec, usize idx, void *ent)
{
	if (idx >= vec->len) {
		return VEC_STS_NF;
	}

	u8 *ptr;
	ptr = vec->data;

	memcpy(ent, ptr + idx * vec->size, vec->size);

	return VEC_STS_OK;
}
