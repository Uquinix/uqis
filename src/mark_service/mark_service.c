/*
 * Copyright (c) 2007-2015 The OpenRC Authors.
 *
 * This file is part of the UQIS project. It is subject to the license terms in
 * the LICENSE file found in the top-level directory of this
 * distribution and at https://github.com/Uquinix/uqis/blob/main/LICENSE
 * This file may not be copied, modified, propagated, or distributed
 *    except according to the terms contained in the LICENSE file.
 */

#include <sys/types.h>
#include <sys/time.h>

#include <errno.h>
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <syslog.h>
#include <time.h>
#include <unistd.h>

#include "einfo.h"
#include "rc.h"
#include "misc.h"

const char *applet = NULL;

int main(int argc, char **argv)
{
	bool ok = false;
	char *svcname = getenv("RC_SVCNAME");
	char *service = NULL;
	char *uqis_pid;
	/* char *mtime; */
	pid_t pid;
	RC_SERVICE bit;
	/* size_t l; */

	applet = basename_c(argv[0]);
	if (argc > 1)
		service = argv[1];
	else
		service = svcname;

	if (service == NULL || *service == '\0')
		eerrorx("%s: no service specified", applet);

	if (!strncmp(applet, "mark_", 5) &&
	    (bit = lookup_service_state(applet + 5)))
		ok = rc_service_mark(service, bit);
	else
		eerrorx("%s: unknown applet", applet);

	/* If we're marking ourselves then we need to inform our parent
	   uqis-run process so they do not mark us based on our exit code */
	/*
	 * FIXME: svcname and service are almost always equal except called from a
	 * shell with just argv[1] - So that doesn't seem to do what Roy initially
	 * expected.
	 * See 20120424041423.GA23657@odin.qasl.de (Tue, 24 Apr 2012 06:14:23 +0200,
	 * uqis@gentoo.org).
	 */
	if (ok && svcname && strcmp(svcname, service) == 0) {
		uqis_pid = getenv("RC_UQIS_PID");
		if (uqis_pid && sscanf(uqis_pid, "%d", &pid) == 1)
			if (kill(pid, SIGHUP) != 0)
				eerror("%s: failed to signal parent %d: %s",
				       applet, pid, strerror(errno));

		/* Remove the exclusive time test. This ensures that it's not
		   in control as well */
		/*
		l = strlen(RC_SVCDIR "/exclusive") + strlen(svcname) +
		    strlen(uqis_pid) + 4;
		mtime = xmalloc(l);
		snprintf(mtime, l, RC_SVCDIR "/exclusive/%s.%s",
		    svcname, uqis_pid);
		if (exists(mtime) && unlink(mtime) != 0)
			eerror("%s: unlink: %s", applet, strerror(errno));
		free(mtime);
		*/
	}

	return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
