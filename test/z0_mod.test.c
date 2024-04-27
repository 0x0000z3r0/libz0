#define Z0_USE_NAMESPACE
#include "z0_test.h"
#include "z0_mod.h"

TEST(mod_init)
{
	usize sts;
	sts = mod_init();
	TEST_EQ("check module initialization", sts, MOD_STS_OK);
}
