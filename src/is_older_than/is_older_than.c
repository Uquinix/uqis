/*
 * Copyright (c) 2016 The OpenRC Authors.

 *
 * This file is part of the UQIS project. It is subject to the license terms in
 * the LICENSE file found in the top-level directory of this
 * distribution and at https://github.com/Uquinix/uqis/blob/main/LICENSE
 * This file may not be copied, modified, propagated, or distributed
 *    except according to the terms contained in the LICENSE file.

 */

#include <errno.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "rc.h"
#include "misc.h"

int main(int argc, char **argv)
{
	int i;

	if (argc < 3)
		return EXIT_FAILURE;

	/* This test is perverted - historically the baselayout function
	 * returns 0 on *failure*, which is plain wrong */
	for (i = 2; i < argc; ++i)
		if (!rc_newer_than(argv[1], argv[i], NULL, NULL))
			return EXIT_SUCCESS;

	return EXIT_FAILURE;
}
