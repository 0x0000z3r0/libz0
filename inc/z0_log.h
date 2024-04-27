#ifndef _Z0_LOG_H_
#define _Z0_LOG_H_

#include "z0_int.h"

enum {
	Z0_LOG_LVL_DBG = 0,
	Z0_LOG_LVL_INF,
	Z0_LOG_LVL_WRN,
	Z0_LOG_LVL_ERR,

	Z0_LOG_LVL_MAX
};

#define Z0_COL_NRM  "\x1B[0m"
#define Z0_COL_RED  "\x1B[31m"
#define Z0_COL_GRN  "\x1B[32m"
#define Z0_COL_YEL  "\x1B[33m"
#define Z0_COL_BLU  "\x1B[34m"
#define Z0_COL_MAG  "\x1B[35m"
#define Z0_COL_CYN  "\x1B[36m"
#define Z0_COL_WHT  "\x1B[37m"

#define Z0_TRM_UP "\x1B[A"

void
z0_log_lvl(u8);

void
z0_log_dbg(const char*, ...);

void
z0_log_inf(const char*, ...);

void
z0_log_wrn(const char*, ...);

void
z0_log_err(const char*, ...);

void
z0_log_raw(const char*, ...);

#ifdef Z0_USE_NAMESPACE
	#define LOG_LVL_DBG Z0_LOG_LVL_DBG
	#define LOG_LVL_INF Z0_LOG_LVL_INF
	#define LOG_LVL_WRN Z0_LOG_LVL_WRN
	#define LOG_LVL_ERR Z0_LOG_LVL_ERR
	#define LOG_LVL_MAX Z0_LOG_LVL_MAX

	#define COL_NRM Z0_COL_NRM
	#define COL_RED Z0_COL_RED
	#define COL_GRN Z0_COL_GRN
	#define COL_YEL Z0_COL_YEL
	#define COL_BLU Z0_COL_BLU
	#define COL_MAG Z0_COL_MAG
	#define COL_CYN Z0_COL_CYN
	#define COL_WHT Z0_COL_WHT

	#define TRM_UP	Z0_TRM_UP

	#define log_lvl z0_log_lvl

	#define log_dbg z0_log_dbg
	#define log_inf z0_log_inf
	#define log_wrn z0_log_wrn
	#define log_err z0_log_err
	#define log_raw z0_log_raw
#endif

#endif
