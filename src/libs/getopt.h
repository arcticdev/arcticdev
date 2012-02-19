/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#pragma once

/* getopt() wrapper */
#define arctic_no_argument            0
#define arctic_required_argument      1
#define arctic_optional_argument      2
struct arctic_option
{
	const char *name;
	int has_arg;
	int *flag;
	int val;
};
extern char arctic_optarg[514];
int arctic_getopt_long_only (int ___argc, char *const *___argv, const char *__shortopts, const struct arctic_option *__longopts, int *__longind);
