#ifndef _Z0_SET_H_
#define _Z0_SET_H_

#include "z0_sts.h"
#include "z0_int.h"

struct z0_set {
	usize len;
	usize cap;
	usize size;
	void  *data;
};

#define Z0_SET_STS_OK	Z0_STS_NEW(0, Z0_STS_LVL_INF)
#define Z0_SET_STS_NF	Z0_STS_NEW(1, Z0_STS_LVL_INF)
#define Z0_SET_STS_EXS	Z0_STS_NEW(0, Z0_STS_LVL_WRN)
#define Z0_SET_STS_ERR	Z0_STS_NEW(0, Z0_STS_LVL_ERR)
#define Z0_SET_STS_MEM	Z0_STS_NEW(1, Z0_STS_LVL_ERR)

usize
z0_set_new(struct z0_set*, usize);

usize
z0_set_chk(struct z0_set*, void*);

usize
z0_set_add(struct z0_set*, void*);

void
z0_set_del(struct z0_set*);

#ifdef Z0_USE_NAMESPACE
	#define SET_STS_OK	Z0_SET_STS_OK
	#define SET_STS_NF	Z0_SET_STS_NF
	#define SET_STS_EXS	Z0_SET_STS_EXS
	#define SET_STS_ERR	Z0_SET_STS_ERR
	#define SET_STS_MEM	Z0_SET_STS_MEM

	#define set z0_set

	#define set_new z0_set_new
	#define set_del z0_set_del
#endif

#endif
