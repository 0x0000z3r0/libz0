#ifndef _Z0_MSC_H_
#define _Z0_MSC_H_

#define Z0_CNT_OF(arr) (sizeof (arr) / sizeof (arr[0]))
#define Z0_OFF_OF(rec, fld) &(((rec*)0)->fld)

#ifdef Z0_USE_NAMESPACE
	#define CNT_OF Z0_CNT_OF
	#define OFF_OF Z0_OFF_OF
#endif

#endif
