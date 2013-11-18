/**
 * cmd.h - build and execute ls command
 *
 * Copyright (C) 2013 Andreu Gil Pàmies <agpchil@gmail.com>
 *
 * This file is part of ls-color
 *
 * ls-color is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ls-color is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ls-color.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CMD_H
#define CMD_H

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>
#include "util.h"

/* Default buffer lenght.  */

#define MAX_BUFFER  1024

/* ls command to run.  */

#define CMD_LS      "ls"

/* Required ls arguments.  */

#define CMD_LS_ARGS "-hlv --group-directories-first " \
                    "--color=always --time=atime --time-style=+%s"

/* Function prototypes.  */

char * cmd_build (int argc, char **argv);
char * cmd_exec (char *cmd, int *ret);

#endif
