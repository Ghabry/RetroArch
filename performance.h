/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2014 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2015 - Daniel De Matteis
 * 
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _RARCH_PERF_H
#define _RARCH_PERF_H

#include <stdint.h>

#include <retro_inline.h>

#include "libretro.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#define PERF_LOG_FMT "[PERF]: Avg (%s): %I64u ticks, %I64u runs.\n"
#else
#define PERF_LOG_FMT "[PERF]: Avg (%s): %llu ticks, %llu runs.\n"
#endif

#ifndef MAX_COUNTERS
#define MAX_COUNTERS 64
#endif

extern const struct retro_perf_counter *perf_counters_rarch[MAX_COUNTERS];
extern const struct retro_perf_counter *perf_counters_libretro[MAX_COUNTERS];
extern unsigned perf_ptr_rarch;
extern unsigned perf_ptr_libretro;

/**
 * retro_get_perf_counter:
 *
 * Gets performance counter.
 *
 * Returns: performance counter.
 **/
retro_perf_tick_t retro_get_perf_counter(void);

/**
 * retro_get_time_usec:
 *
 * Gets time in microseconds.  *
 * Returns: time in microseconds.
 **/
retro_time_t retro_get_time_usec(void);

void retro_perf_register(struct retro_perf_counter *perf);

/* Same as retro_perf_register, just for libretro cores. */
void retro_perf_register(struct retro_perf_counter *perf);

void retro_perf_clear(void);

void retro_perf_log(void);

void rarch_perf_log(void);

int rarch_perf_init(struct retro_perf_counter *perf, const char *name);

/**
 * retro_perf_start:
 * @perf               : pointer to performance counter
 *
 * Start performance counter. 
 **/
void retro_perf_start(struct retro_perf_counter *perf);

/**
 * retro_perf_stop:
 * @perf               : pointer to performance counter
 *
 * Stop performance counter. 
 **/
void retro_perf_stop(struct retro_perf_counter *perf);

/**
 * retro_get_cpu_features:
 *
 * Gets CPU features..
 *
 * Returns: bitmask of all CPU features available.
 **/
uint64_t retro_get_cpu_features(void);

/**
 * retro_get_cpu_cores:
 *
 * Gets the amount of available CPU cores.
 *
 * Returns: amount of CPU cores available.
 **/
unsigned retro_get_cpu_cores(void);


#ifdef __cplusplus
}
#endif

#endif

