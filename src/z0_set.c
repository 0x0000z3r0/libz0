#define Z0_USE_NAMESPACE
#include "z0_set.h"

#include <stdlib.h>
#include <string.h>

#define Z0_MALLOC	malloc
#define Z0_REALLOC	realloc
#define Z0_FREE		free

usize
set_new(struct set *set, usize size)
{
	set->len = 0;
	set->cap = 4;

	set->size = size;
	set->data = Z0_MALLOC(set->cap * set->size);
	if (set->data == NULL) {
		return SET_STS_MEM;
	}

	return SET_STS_OK;
}

usize
set_chk(struct set *set, void *ent)
{
	for (usize i = 0; i < set->len; ++i) {
		if (memcmp(set->data + i * set->size, ent, set->size) == 0) {
			return SET_STS_OK;
		}
	}

	return SET_STS_NF;
}

usize
set_add(struct set *set, void *ent)
{
	usize sts;
	sts = set_chk(set, ent);
	if (sts == SET_STS_OK) {
		return SET_STS_EXS;
	}

	if (set->len >= set->cap) {
		set->cap *= 2;

		void *data;
		data = Z0_REALLOC(set->data, set->size * set->cap);
		if (data == NULL) {
			return SET_STS_MEM;
		}

		set->data = data;
	}

	memcpy(set->data + set->len * set->size, ent, set->size);
	++set->len;
	
	return SET_STS_OK;
}

void
set_del(struct set *set)
{
	Z0_FREE(set->data);
}
