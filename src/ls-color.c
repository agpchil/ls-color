/**
 * ls-color.c - Colorize ls output
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

#include "ls-color.h"

int main (int argc, char **argv)
{
  char *output;
  char *colorized_output;
  char *cmd;
  int   retval;

  cmd = cmd_build (argc, argv);

  output = cmd_exec (cmd, &retval);

  colorized_output = colorize (output);

  if (colorized_output != NULL)
    {
      printf ("%s", colorized_output);
    }

  free (colorized_output);
  free (output);
  free (cmd);

  return WEXITSTATUS (retval);
}
