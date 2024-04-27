#define Z0_USE_NAMESPACE
#include "z0_test.h"
#include "z0_str.h"

TEST(str_new)
{
	usize sts;

	struct str str;
	sts = str_new(&str, 1, (void*)"a");

	TEST_EQ("check string creation", STS_OK(sts), 1);

	str_del(&str);
}
