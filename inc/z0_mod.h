#ifndef _Z0_MOD_H_
#define _Z0_MOD_H_

#include "z0_int.h"
#include "z0_sts.h"

#define Z0_MOD_DEV "z0_mod"

#define Z0_MOD_STS_OK	Z0_STS_NEW(0, Z0_STS_LVL_INF)
#define Z0_MOD_STS_NF	Z0_STS_NEW(1, Z0_STS_LVL_INF)
#define Z0_MOD_STS_INIT	Z0_STS_NEW(0, Z0_STS_LVL_ERR)
#define Z0_MOD_STS_OPEN	Z0_STS_NEW(1, Z0_STS_LVL_ERR)
#define Z0_MOD_STS_READ	Z0_STS_NEW(2, Z0_STS_LVL_ERR)

usize
z0_mod_init(void);

usize
z0_mod_chk(void);

#ifdef Z0_USE_NAMESPACE
	#define	MOD_DEV	Z0_MOD_DEV

	#define MOD_STS_OK	Z0_MOD_STS_OK
	#define MOD_STS_NF	Z0_MOD_STS_NF
	#define MOD_STS_INIT	Z0_MOD_STS_INIT
	#define MOD_STS_OPEN	Z0_MOD_STS_OPEN
	#define MOD_STS_READ	Z0_MOD_STS_READ

	#define mod_init	z0_mod_init
	#define mod_chk		z0_mod_chk
#endif

#endif
