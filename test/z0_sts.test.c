#define Z0_USE_NAMESPACE
#include "z0_test.h"
#include "z0_sts.h"

TEST(sts_level)
{
	usize sts;
	sts = STS_NEW(0, STS_LVL_DBG);

	TEST_EQ("check zero status", sts, 0);

	sts = STS_NEW(0, STS_LVL_INF);

	TEST_EQ("check info level status", STS_LVL(sts), STS_LVL_INF);
}
