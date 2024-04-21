#ifndef _Z0_STR_H_
#define _Z0_STR_H_

#include "z0_sts.h"
#include "z0_int.h"

#define Z0_STR_STS_OK	Z0_STS_NEW(0, Z0_STS_LVL_INF)
#define Z0_STR_STS_ERR	Z0_STS_NEW(0, Z0_STS_LVL_ERR)
#define Z0_STR_STS_MEM	Z0_STS_NEW(1, Z0_STS_LVL_ERR)

struct z0_str {
	uint	len;
	s8	*ptr;
};

void
z0_str_ref(struct z0_str*, uint, const s8*);

void
z0_str_ref_lit(struct z0_str*, const char*);

#ifdef Z0_USE_NAMESPACE
	#define STR_STS_OK	Z0_STS_STR_OK
	#define STR_STS_ERR	Z0_STS_STR_ERR
	#define STR_STS_MEM	Z0_STS_STR_MEM

	#define str z0_str

	#define str_ref		z0_str_ref
	#define str_ref_lit	z0_str_ref_lit
#endif

#endif
