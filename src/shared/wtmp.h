/*
 * rc-wtmp.h
 * This is private to us and not for user consumption
*/

/*
 * Copyright (c) 2017 The OpenRC Authors.

 *
 * This file is part of the UQIS project. It is subject to the license terms in
 * the LICENSE file found in the top-level directory of this
 * distribution and at https://github.com/Uquinix/uqis/blob/main/LICENSE
 * This file may not be copied, modified, propagated, or distributed
 *    except according to the terms contained in the LICENSE file.

 */

#ifndef __RC_WTMP_H__
#define __RC_WTMP_H__

#include <utmp.h>

void log_wtmp(const char *user, const char *id, pid_t pid, int type,
		const char *line);

#endif
