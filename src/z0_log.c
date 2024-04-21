#define Z0_USE_NAMESPACE
#include "z0_log.h"

#include <stdarg.h>
#include <stdio.h>

static struct z0_log_ctx {
	u8 lvl;
} g_log_ctx;

void
log_lvl(u8 lvl)
{
	if (lvl >= LOG_LVL_MAX)
		return;

	g_log_ctx.lvl = lvl;
}

void
z0_log_dbg(const char *fmt, ...)
{
	if (g_log_ctx.lvl > LOG_LVL_DBG)
		return;

	va_list args;
	va_start(args, fmt);

	printf(COL_BLU "DBG: " COL_NRM);
	vprintf(fmt, args);
	printf("\n");

	va_end(args);
}

void
z0_log_inf(const char *fmt, ...)
{
	if (g_log_ctx.lvl > LOG_LVL_INF)
		return;

	va_list args;
	va_start(args, fmt);

	printf(COL_CYN "INF: " COL_NRM);
	vprintf(fmt, args);
	printf("\n");

	va_end(args);
}

void
z0_log_wrn(const char *fmt, ...)
{
	if (g_log_ctx.lvl > LOG_LVL_WRN)
		return;

	va_list args;
	va_start(args, fmt);

	printf(COL_YEL "WRN: " COL_NRM);
	vprintf(fmt, args);
	printf("\n");

	va_end(args);
}

void
z0_log_err(const char *fmt, ...)
{
	if (g_log_ctx.lvl > LOG_LVL_ERR)
		return;

	va_list args;
	va_start(args, fmt);

	printf(COL_RED "ERR: " COL_NRM);
	vprintf(fmt, args);
	printf("\n");

	va_end(args);
}

void
z0_log_raw(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);
}
