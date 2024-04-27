#ifndef _Z0_PRC_H_
#define _Z0_PRC_H_

#include "z0_str.h"
#include "z0_vec.h"

struct z0_prc {
	s32 pid;

	struct z0_str name;
};

#define Z0_PRC_STS_OK	Z0_STS_NEW(0, Z0_STS_LVL_INF)
#define Z0_PRC_STS_ERR	Z0_STS_NEW(0, Z0_STS_LVL_ERR)
#define Z0_PRC_STS_OPEN	Z0_STS_NEW(1, Z0_STS_LVL_ERR)
#define Z0_PRC_STS_DENT	Z0_STS_NEW(2, Z0_STS_LVL_ERR)
#define Z0_PRC_STS_ADD	Z0_STS_NEW(3, Z0_STS_LVL_ERR)
#define Z0_PRC_STS_READ	Z0_STS_NEW(4, Z0_STS_LVL_ERR)

usize
z0_prc_all(struct z0_vec*);

#ifdef Z0_USE_NAMESPACE
	#define PRC_STS_OK	Z0_PRC_STS_OK
	#define PRC_STS_ERR	Z0_PRC_STS_ERR
	#define PRC_STS_OPEN	Z0_PRC_STS_OPEN
	#define PRC_STS_DENT	Z0_PRC_STS_DENT
	#define PRC_STS_ADD	Z0_PRC_STS_ADD
	#define PRC_STS_READ	Z0_PRC_STS_READ

	#define prc z0_prc

	#define prc_all z0_prc_all
#endif

#endif
