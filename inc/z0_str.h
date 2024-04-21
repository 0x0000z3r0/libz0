#ifndef _Z0_STR_H_
#define _Z0_STR_H_

#include "z0_sts.h"
#include "z0_int.h"

#define Z0_STR_STS_OK	Z0_STS_NEW(0, Z0_STS_LVL_INF)
#define Z0_STR_STS_NF	Z0_STS_NEW(1, Z0_STS_LVL_INF)
#define Z0_STR_STS_LEN	Z0_STS_NEW(0, Z0_STS_LVL_WRN)
#define Z0_STR_STS_ERR	Z0_STS_NEW(0, Z0_STS_LVL_ERR)
#define Z0_STR_STS_MEM	Z0_STS_NEW(1, Z0_STS_LVL_ERR)

struct z0_str_ref {
	usize	len;
	s8	*ptr;
};

void
z0_str_ref(struct z0_str_ref*, usize, const s8*);

void
z0_str_ref_lit(struct z0_str_ref*, const char*);

void
z0_str_ref_s32(struct z0_str_ref*, s32*);

struct z0_str {
	usize	cap;
	usize	len;
	s8	*ptr;
};

usize
z0_str_new(struct z0_str*, usize, const s8*);

usize
z0_str_new_cap(struct z0_str*, usize);

void
z0_str_del(struct z0_str*);

usize
z0_str_cat(struct z0_str*, usize, const s8*);

usize
z0_str_pos(struct z0_str*, usize*, usize, const s8*);

usize
z0_str_pos_off(struct z0_str*, usize*, usize, usize, const s8*);

usize
z0_str_len(struct z0_str*, usize);

#ifdef Z0_USE_NAMESPACE
	#define STR_STS_OK	Z0_STR_STS_OK
	#define STR_STS_NF	Z0_STR_STS_NF
	#define STR_STS_LEN	Z0_STR_STS_LEN
	#define STR_STS_ERR	Z0_STR_STS_ERR
	#define STR_STS_MEM	Z0_STR_STS_MEM

	#define str	z0_str
	#define str_ref	z0_str_ref

	#define str_ref		z0_str_ref
	#define str_ref_lit	z0_str_ref_lit
	#define str_ref_s32	z0_str_ref_s32

	#define str_new		z0_str_new
	#define str_new_cap	z0_str_new_cap
	#define str_del		z0_str_del
	#define str_cat		z0_str_cat
	#define str_pos		z0_str_pos
	#define str_pos_off	z0_str_pos_off
	#define str_len		z0_str_len
#endif

#endif
