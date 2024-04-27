#ifndef _Z0_TEST_H_
#define _Z0_TEST_H_

#include "z0_log.h"

#define Z0_TEST(name)				\
	void __attribute__((constructor))	\
	_z0_test_##name(void)			\
			

#define Z0_TEST_EQ(name, val0, val1) \
	do { \
		static const char *text[] = { "FAILED", "PASSED" };		\
		static const char *color[] = { Z0_COL_RED, Z0_COL_GRN };	\
		\
		const usize res = (val0) == (val1); \
		z0_log_inf("test case " Z0_COL_MAG "[" name "]" Z0_COL_NRM ", in function " Z0_COL_MAG "[%s]" Z0_COL_NRM": %s%s"\
			, __func__, color[res], text[res]); \
		if (!res) { \
			z0_log_wrn("\t expected: " Z0_COL_GRN "%zu" Z0_COL_NRM ", got: " Z0_COL_RED "%zu" Z0_COL_NRM, val0, val1); \
		} \
	} while (0)

#define Z0_TEST_EXIT_LABEL _Z0_TEST_EXIT
#define Z0_TEST_EXIT_EQ(name, val0, val1)	\
	do {					\
		Z0_TEST_EQ(name, val0, val1);	\
		if ((val0) != (val1)) {		\
			goto Z0_TEST_EXIT_LABEL;\
		}				\
	} while (0)

#ifdef Z0_USE_NAMESPACE
	#define TEST Z0_TEST

	#define TEST_EQ		Z0_TEST_EQ
	#define TEST_EXIT_EQ	Z0_TEST_EXIT_EQ
	#define TEST_EXIT_LABEL	Z0_TEST_EXIT_LABEL
#endif

#endif
