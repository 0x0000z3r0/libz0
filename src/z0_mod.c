#define Z0_USE_NAMESPACE
#include "z0_mod.h"
#include "z0_str.h"

#include <linux/module.h>
#include <linux/unistd.h>

#include <sys/syscall.h>
#include <sys/unistd.h>
#include <sys/fcntl.h>

#include <stdio.h>

usize
mod_init(void)
{
	extern const u8 __start_z0_mod[];
	extern const u8 __stop_z0_mod[];

	const usize len = __stop_z0_mod - __start_z0_mod;

	s32 res;
	res = syscall(SYS_init_module, __start_z0_mod, len, NULL);
	if (res == -1) {
		perror("");
		return MOD_STS_INIT;
	}

	return MOD_STS_OK;
}

usize
mod_chk(void)
{
	s32 file;
	file = open("/proc/modules", O_RDONLY);
	if (file == -1) {
		return MOD_STS_OPEN;
	}

	usize sts;

	i8 buf[1024];
	struct str_ref ref;
	str_ref(&ref, sizeof (buf), (const s8*)buf);

	s64 bytes;
	while (TRUE) {
		bytes = read(file, buf, sizeof (buf));
		if (bytes == -1) {
			close(file);
			return MOD_STS_READ;
		}

		if (bytes == 0) {
			break;
		}

		usize pos;
		sts = str_ref_pos_lit(&ref, &pos, MOD_DEV);
		if (sts == STR_STS_OK) {
			close(file);
			return STR_STS_OK;
		}
	}

	close(file);
	return MOD_STS_NF;
}
