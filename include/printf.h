/*
 * Copyright 2006 by Brian Dominy <brian@oddchange.com>
 *
 * This file is part of FreeWPC.
 *
 * FreeWPC is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * FreeWPC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with FreeWPC; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _PRINTF_H
#define _PRINTF_H


typedef U8 *va_list;

#define PRINTF_BUFFER_SIZE		48


#define va_start(va, fmt) \
do { \
	va = (va_list)((unsigned char *)&fmt + sizeof (fmt)); \
} while (0) \


#define va_arg(va, type)	((va += sizeof (type)), ((type *)va)[-1])

#define va_end(va)

extern char sprintf_buffer[PRINTF_BUFFER_SIZE];
U8 sprintf (const char *format, ...);

#ifdef CONFIG_PLATFORM_LINUX
#define sprintf(format,rest...) sprintf(sprintf_buffer, format, ## rest)
#endif

/** psprintf() is like sprintf() but it has TWO format control
 * strings.  The first is used when the value is singular, and
 * the second when it is plural.  You can only printf a single
 * value at a time this way. */
#define psprintf(fmt1, fmtn, val) \
do { \
	if (val == 1) \
		sprintf (fmt1, val); \
	else \
		sprintf (fmtn, val); \
} while (0)

#ifdef DEBUGGER
#define dbprintf(format, rest...) \
	do { \
		sprintf (format, ## rest ); \
		db_puts (sprintf_buffer); \
	} while (0)
#else
#define dbprintf(format, rest...)
#endif /* DEBUGGER */

#endif /* _PRINTF_H */
