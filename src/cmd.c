/**
 * cmd.c - build and execute ls command
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

#include "cmd.h"

char *
cmd_build (int argc, char **argv)
{
  int   args_size  = 256;
  int   files_size = 256;
  int   i;
  char *cmd;
  char *args;
  char *files;

  args = malloc_string (args_size);
  files = malloc_string (files_size);

  for (i = 1; i < argc; i++)
    {
      if (argv[i][0] == '-')
        {
          args = check_mem (args, &args_size, strlen (argv[i]) + 1);
          strcat (args, " ");
          strcat (args, argv[i]);
        }
      else
        {
          files = check_mem (files, &files_size, strlen (argv[i]) + 1);
          strcat (files, " ");
          strcat (files, argv[i]);
        }
    }
  cmd = malloc_string (strlen (CMD_LS)
                       + strlen (args)
                       + strlen (CMD_LS_ARGS)
                       + strlen (files)
                       + 3 // spaces
                      );
  sprintf (cmd, "%s %s %s %s", CMD_LS, args, CMD_LS_ARGS, files);
  free (args);
  free (files);
  return cmd;
}

/* Execute cmd and returns the output. The argument ret will be
   modified with the exit value.  */

char *
cmd_exec (char *cmd, int *ret)
{
  FILE *pipein_fp;
  char  buffer[MAX_BUFFER];
  int   output_size = 1024;
  char *output = malloc_string (output_size);

  /* open pipe */
  pipein_fp = popen (cmd, "r");
  if (pipein_fp == NULL)
    {
      perror ("popen");
      exit (1);
    }

  /* fetch output */
  while (fgets (buffer, MAX_BUFFER, pipein_fp) != NULL) {
    output = check_mem (output, &output_size, strlen(buffer));
    strcat (output, buffer);
  }

  *ret = pclose (pipein_fp);

  return output;
}
