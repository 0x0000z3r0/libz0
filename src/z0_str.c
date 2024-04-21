#define Z0_USE_NAMESPACE
#include "z0_str.h"

#include <malloc.h>
#include <string.h>

#define Z0_MALLOC	malloc
#define Z0_REALLOC 	realloc
#define Z0_FREE 	free

void
str_ref(struct str *str, uint len, const s8 *buf)
{
	str->len = len;
	str->ptr = (s8*)buf;
}

void
str_ref_lit(struct str *str, const char *buf)
{
	str->len = strlen(buf);
	str->ptr = (s8*)buf;
}
