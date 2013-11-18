/**
 * date.c - calculate time between two dates
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

#include "date.h"

/* Diff between two dates and returns remaining time struct.  */

struct rem_time *
date_diff (time_t d1, time_t d2)
{
  struct tm date1, date2;
  struct rem_time *dt = malloc (sizeof (struct rem_time));

  (void) localtime_r (&d1, &date1);
  (void) localtime_r (&d2, &date2);

  int types[6]        = { REM_TYPE_YEARS, REM_TYPE_MONTHS, REM_TYPE_DAYS,
                          REM_TYPE_HOURS, REM_TYPE_MINUTES, REM_TYPE_SECONDS };
  int date1_fields[6] = { date1.tm_year, date1.tm_mon, date1.tm_mday,
                          date1.tm_hour, date1.tm_min, date1.tm_sec };
  int date2_fields[6] = { date2.tm_year, date2.tm_mon, date2.tm_mday,
                          date2.tm_hour, date2.tm_min, date2.tm_sec };

  int *t   = &types[0];
  int *f1  = &date1_fields[0];
  int *f2  = &date2_fields[0];
  int  idx = sizeof (types) / sizeof (types[0]);

  do
    {
      dt->value = *f1 - *f2;
      dt->type = *t;
      t++; f1++; f2++;
    }
  while (dt->value == 0 && --idx > 0);

  return dt;
}
