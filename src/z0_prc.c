#define Z0_USE_NAMESPACE
#include "z0_prc.h"
#include "z0_log.h"

#define __USE_LARGEFILE64

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/dir.h>
#include <sys/unistd.h>
#include <sys/fcntl.h>

struct dent {
	ino64_t	ino;
	off64_t	off;
	u16	len;
	u8	type;
	i8	name[];
};

usize
prc_all(struct vec *prcs)
{
	usize sts;

	static const i8 lit_proc[] = "/proc/";

	s32 dir;
	dir = open(lit_proc, O_RDONLY);
	if (dir == -1) {
		return PRC_STS_OPEN;
	}

	u8 buf[1024];
	struct dent *ent;

	i8 name[PATH_MAX];
		
	s64 res;
	while (TRUE) {
		res = syscall(SYS_getdents64, dir, buf, sizeof (buf));
		if (res == -1) {
			close(dir);
			return PRC_STS_DENT;
		}

		if (res == 0) {
			break;
		}

		s64 off;
		off = 0;
		while (off < res) {
			ent = (struct dent*)(buf + off);
			if (ent->name[0] >= '0' && ent->name[0] <= '9') {
				struct str_ref ref;
				str_ref_lit(&ref, ent->name);

				struct prc prc;
				str_ref_s32(&ref, &prc.pid);

				sts = vec_add(prcs, &prc);
				if (STS_ERR(sts)) {
					close(dir);
					return PRC_STS_ADD;
				}

				struct str str;
				sts = str_new_cap(&str, PATH_MAX);
				if (STS_ERR(sts)) {
					close(dir);
					return PRC_STS_ERR;
				}

				sts = str_cat(&str, sizeof (lit_proc) - 1, (const s8*)lit_proc);
				if (STS_ERR(sts)) {
					str_del(&str);
					close(dir);
					return PRC_STS_ERR;
				}

				sts = str_cat(&str, ref.len, ref.ptr);
				if (STS_ERR(sts)) {
					str_del(&str);
					close(dir);
					return PRC_STS_ERR;
				}

				static const i8 lit_comm[] = "/comm";
				sts = str_cat(&str, sizeof (lit_comm), (const s8*)lit_comm);
				if (STS_ERR(sts)) {
					str_del(&str);
					close(dir);
					return PRC_STS_ERR;
				}

				s32 file;
				file = open((const i8*)str.ptr, O_RDONLY);
				if (file == -1) {
					return PRC_STS_OPEN;
				}

				str_del(&str);

				s64 bytes;
				bytes = read(file, name, sizeof (name));
				if (bytes == -1) {
					close(file);
					close(dir);
					return PRC_STS_READ;
				}

				usize len;
				for (len = 0; name[len] != '\n'; ++len) {
				}

				sts = str_new(&prc.name, len, (const s8*)name);
				if (STS_ERR(sts)) {
					close(file);
					close(dir);
					return PRC_STS_ERR;
				}

				close(file);
			}

			off += ent->len;
		}
	}

	close(dir);
	return PRC_STS_OK;
}

