#ifndef _Z0_STS_H_
#define _Z0_STS_H_

#define Z0_STS_LVL_DBG 0b00
#define Z0_STS_LVL_INF 0b10
#define Z0_STS_LVL_WRN 0b01
#define Z0_STS_LVL_ERR 0b11

#define Z0_STS_NEW(res, lvl) (((res) << 2) | (lvl))

#define Z0_STS_RES(sts) ((sts) >> 2)
#define Z0_STS_LVL(sts) ((sts) & 0x3)

#define Z0_STS_ERR(sts) ((sts) & 1)
#define Z0_STS_OK(sts)  (!Z0_STS_ERR(sts))

#ifdef Z0_USE_NAMESPACE
	#define STS_LVL_DBG Z0_STS_LVL_DBG
	#define STS_LVL_INF Z0_STS_LVL_INF
	#define STS_LVL_WRN Z0_STS_LVL_WRN
	#define STS_LVL_ERR Z0_STS_LVL_ERR

	#define STS_NEW Z0_STS_NEW

	#define STS_RES Z0_STS_RES
	#define STS_LVL Z0_STS_LVL

	#define STS_ERR Z0_STS_ERR
	#define STS_OK  Z0_STS_OK
#endif

#endif
