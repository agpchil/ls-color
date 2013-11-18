/**
 * colorize.h - colorize data
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

#ifndef COLORIZE_H
#define COLORIZE_H

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>

#include "date.h"
#include "util.h"
#include "config.h"

/* Function prototypes.  */

char * colorize_perm (char *str);
char * colorize_date (char *str);
char * colorize_size (char *str);
char * colorize_sep (void);
char * colorize_line (char *line);
char * colorize (char *data);

#endif /* COLORIZE_H  */
