/**
 * colorize.c - colorize data
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

#include "colorize.h"

char *
colorize_perm (char *str)
{
  int   i, max;
  char  c, tmp[128];
  char *color  = NULL;
  char *output = malloc_string (128);

  max = strlen (str);
  for (i = 0; i < max; i++)
    {
      c = str[i];
      switch (c)
        {
        case 'r':
          color = COLOR_PERM_READ;
          break;
        case 'w':
          color = COLOR_PERM_WRITE;
          break;
        case 'x':
          color = COLOR_PERM_EXEC;
          break;
        case 'd':
          color = COLOR_PERM_DIR;
          break;
        case '-':
          color = COLOR_PERM_NONE;
          break;
        default:
          color = COLOR_RESET;
        }
      sprintf (tmp, "%s%c%s", color, c, COLOR_RESET);
      strcat (output, tmp);
    }
  return output;
}

char *
colorize_date (char *str)
{
  char             value[32];
  int              now    = time (NULL);
  char            *output = malloc_string (128);
  struct rem_time *dt     = NULL;
  char            *color  = NULL;

  dt = date_diff (now, atoi(str));

  switch (dt->type)
    {
    case REM_TYPE_SECONDS:
      sprintf (value, "%-2d sec", dt->value);
      color = COLOR_DATE_SEC;
      break;
    case REM_TYPE_MINUTES:
      sprintf (value, "%-2d min", dt->value);
      color = COLOR_DATE_MIN;
      break;
    case REM_TYPE_HOURS:
      sprintf (value, "%-2d hou", dt->value);
      color = COLOR_DATE_HOUR;
      break;
    case REM_TYPE_DAYS:
      sprintf (value, "%-2d day", dt->value);
      color = COLOR_DATE_DAY;
      break;
    case REM_TYPE_MONTHS:
      sprintf (value, "%-2d mon", dt->value);
      color = COLOR_DATE_MONTH;
      break;
    case REM_TYPE_YEARS:
      sprintf (value, "%-2d yea", dt->value);
      color = COLOR_DATE_YEAR;
      break;
    default:
      printf ("Unrecognized type\n");
      break;
    }

  sprintf (output, "%s%s%s", color, value, COLOR_RESET);
  free (dt);

  return output;
}

char *
colorize_size (char *str)
{
  char *output = malloc_string (128);
  char  unit   = str[strlen (str) - 1];
  char *size   = strdup (str);
  char *color  = NULL;

  switch (unit)
    {
    case 'K':
      size[strlen (size) - 1] = '\0';
      color = COLOR_SIZE_UNIT_K;
      break;
    case 'M':
      size[strlen (size) - 1] = '\0';
      color = COLOR_SIZE_UNIT_M;
      break;
    case 'G':
      size[strlen (size) - 1] = '\0';
      color = COLOR_SIZE_UNIT_G;
      break;
    case 'T':
      size[strlen (size) - 1] = '\0';
      color = COLOR_SIZE_UNIT_T;
      break;
    default:
      unit='B';
      color = COLOR_SIZE_UNIT_B;
    }
  sprintf (output, "%s%4s%s%c%s", COLOR_SIZE_VALUE, size, color,
           unit, COLOR_RESET);
  free (size);
  return output;
}

char *
colorize_sep (void)
{
  char *output = malloc_string(32);

  sprintf (output,"%s%s%s",COLOR_SEPARATOR, UI_SEPARATOR, COLOR_RESET);
  return output;
}

char *
colorize_total (char *str)
{
  char *output = malloc_string (32);
  char total[32];
  char *ctotal;

  if (sscanf (str, "total %[^\n]", total) == 1)
    {
      ctotal = colorize_size (total);
      sprintf (output,"  %s%s%s%s\n", COLOR_TOTAL, UI_TOTAL, ctotal,
               COLOR_RESET);
      free (ctotal);
    }

  return output;
}


char *
colorize_line (char *line)
{
  char  perm[64];
  char  links[32];
  char  owner[32];
  char  group[32];
  char  size[32];
  char  date[32];
  char  name[1024];
  char *tmp[4];
  char *output = NULL;
  int   n;

  n = sscanf (line, "%s %s %s %s %s %s %[^\n]", perm, links, owner, group,
              size, date, name);
  if (n == 7)
    {
      output = malloc_string (1024);

      tmp[0] = colorize_perm (perm);
      tmp[1] = colorize_date (date);
      tmp[2] = colorize_size (size);
      tmp[3] = colorize_sep ();
      sprintf (output, " %s%10s%s%8s%s%5s%s%s\n",
               tmp[3], tmp[0],
               tmp[3], tmp[1],
               tmp[3], tmp[2],
               tmp[3], name);
      free (tmp[0]);
      free (tmp[1]);
      free (tmp[2]);
      free (tmp[3]);
    }

  return output;
}

char *
colorize (char *data)
{
  char  line[1024];
  char *str = data;
  int   offset = 0;
  int   read_char_count;
  char *colorized = NULL;
  char *output = malloc_string (strlen(data) * 2);
  int   n;

  while (sscanf (str + offset, "%[^\n]%*c%n", line, &read_char_count) == 1)
    {
      offset += read_char_count;
      colorized = colorize_line (line);

      if (colorized != NULL)
        {
          strcat (output, colorized);
          free (colorized);
        }
      else
        {
          if (strncmp (line, "total", 5) == 0)
            {
              colorized = colorize_total (line);
              strcat (output, colorized);
              free (colorized);
            }
          else
            {
              strcat (output, line);
              strcat (output, "\n");
            }
        }
    }

  if (strlen (output) == 0)
    {
      free (output);
      output = NULL;
    }

  return output;
}
