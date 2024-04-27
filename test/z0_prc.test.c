#define Z0_USE_NAMESPACE
#include "z0_test.h"
#include "z0_prc.h"

TEST(prc_all)
{
	usize sts;

	struct vec prcs;
	sts = vec_new(&prcs, sizeof (struct prc));
	TEST_EXIT_EQ("create the process vector", sts, VEC_STS_OK);

	sts = prc_all(&prcs);
	TEST_EXIT_EQ("check processes vector", sts, PRC_STS_OK);
	TEST_EQ("check vector length", prcs.len > 0, TRUE);

	struct prc prc;
	for (usize i = 0; i < prcs.len; ++i) {
		sts = vec_get(&prcs, i, &prc);
		if (STS_ERR(sts)) {
			goto TEST_EXIT_LABEL;
		}

		log_inf("%i: %.*s", prc.pid, (s32)prc.name.len, prc.name.ptr);

		str_del(&prc.name);
	}

TEST_EXIT_LABEL:
	vec_del(&prcs);
}
