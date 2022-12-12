/*
 * Copyright (c) 2007-2015 The OpenRC Authors.
 *
 * This file is part of the UQIS project. It is subject to the license terms in
 * the LICENSE file found in the top-level directory of this
 * distribution and at https://github.com/Uquinix/uqis/blob/main/LICENSE
 * This file may not be copied, modified, propagated, or distributed
 *    except according to the terms contained in the LICENSE file.
 */

#ifndef RC_LOGGER_H
#define RC_LOGGER_H

extern pid_t rc_logger_pid;
extern int rc_logger_tty;
extern bool rc_in_logger;

void rc_logger_open(const char *runlevel);
void rc_logger_close(void);

#endif
