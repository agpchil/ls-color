/**
 * date.h - calculate time between two dates
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

#ifndef DATE_H
#define DATE_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>

/* Remaining types.  */

enum rem_type
{
  REM_TYPE_SECONDS,
  REM_TYPE_MINUTES,
  REM_TYPE_HOURS,
  REM_TYPE_DAYS,
  REM_TYPE_MONTHS,
  REM_TYPE_YEARS,
};

/* Remaining time.  */

struct rem_time
{
  int value;
  enum rem_type type;
};

/* Function prototypes.  */

struct rem_time * date_diff (time_t d1, time_t d2);

#endif /* DATE_H  */
