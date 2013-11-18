/**
 * util.c - utilities
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

#include "util.h"

/* Check if data has enough memory available to store data2_size and
   realloc if needed.  DATA_SIZE is modified. */

void *
check_mem (char *data, int *data_size, int data2_size)
{
  int data_length  = strlen (data);
  int data_avail   = *data_size - data_length;
  int mem_avail    = data_avail - data2_size;

  if (mem_avail > 0)
    {
      return data;
    }
  else
    {
      *data_size = *data_size * 2;
      return realloc (data, *data_size);
    }
}

/* Allocate memory for strings */

void *
malloc_string (int size) {
  char *ptr = malloc (sizeof (char *) * size);
  if(ptr != NULL) { bzero (ptr, size); }
  return ptr;
}
