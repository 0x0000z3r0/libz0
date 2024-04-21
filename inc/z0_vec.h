#ifndef _Z0_VEC_H_
#define _Z0_VEC_H_

#include "z0_sts.h"
#include "z0_int.h"

struct z0_vec {
	uint len;
	uint cap;
	uint size;
	void *data;
};

#define Z0_VEC_STS_OK	Z0_STS_NEW(0, Z0_STS_LVL_INF)
#define Z0_VEC_STS_NF	Z0_STS_NEW(1, Z0_STS_LVL_INF)
#define Z0_VEC_STS_ERR	Z0_STS_NEW(0, Z0_STS_LVL_ERR)
#define Z0_VEC_STS_MEM	Z0_STS_NEW(1, Z0_STS_LVL_ERR)

uint
z0_vec_new(struct z0_vec*, uint);

void
z0_vec_del(struct z0_vec*);

uint
z0_vec_add(struct z0_vec*, void*);

uint
z0_vec_get(struct z0_vec*, uint, void**);

#ifdef Z0_USE_NAMESPACE
	#define VEC_STS_OK	Z0_VEC_STS_OK
	#define VEC_STS_NF	Z0_VEC_STS_NF
	#define VEC_STS_ERR	Z0_VEC_STS_ERR
	#define VEC_STS_MEM	Z0_VEC_STS_MEM

	#define vec z0_vec

	#define vec_new z0_vec_new
	#define vec_del z0_vec_del

	#define vec_add z0_vec_add
	#define vec_get z0_vec_get
#endif

#endif
