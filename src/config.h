/**
 * config.h - configuration file
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

#ifndef CONFIG_H
#define CONFIG_H

#define COLOR_PERM_READ    "\x1b[0;32m"
#define COLOR_PERM_EXEC    "\x1b[0;35m"
#define COLOR_PERM_WRITE   "\x1b[0;33m"
#define COLOR_PERM_DIR     "\x1b[1;32m"
#define COLOR_PERM_NONE    "\x1b[0m"

#define COLOR_SIZE_VALUE   "\x1b[0m"
#define COLOR_SIZE_UNIT_B  "\x1b[0;32m"
#define COLOR_SIZE_UNIT_K  "\x1b[1;32m"
#define COLOR_SIZE_UNIT_M  "\x1b[1;33m"
#define COLOR_SIZE_UNIT_G  "\x1b[1;35m"
#define COLOR_SIZE_UNIT_T  "\x1b[1;36m"

#define COLOR_DATE_SEC     "\x1b[1;36m"
#define COLOR_DATE_MIN     "\x1b[1;36m"
#define COLOR_DATE_HOUR    "\x1b[0;37m"
#define COLOR_DATE_DAY     "\x1b[0;37m"
#define COLOR_DATE_MONTH   "\x1b[0;37m"
#define COLOR_DATE_YEAR    "\x1b[0;37m"

#define COLOR_RESET        "\x1b[0m"

#define COLOR_SEPARATOR    "\x1b[0m"
#define COLOR_TOTAL        "\x1b[0;31m"

#define UI_SEPARATOR       "│"
#define UI_TOTAL           "⇒"

#endif /* CONFIG_H  */
