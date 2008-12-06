/*
 * Copyright 2008 by Brian Dominy <brian@oddchange.com>
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

#if (MACHINE_DMD == 1)

#include <sys/dmd.h>

#define DISPLAY_WIDTH           DMD_PIXEL_WIDTH
#define DISPLAY_HEIGHT          DMD_PIXEL_HEIGHT

/* Portable display functions */
#define display_init            dmd_init
#define display_alloc_low       dmd_alloc_low
#define display_alloc_high      dmd_alloc_high
#define display_alloc_low_high  dmd_alloc_low_high
#define display_map_low_high    dmd_map_low_high
#define display_show_low        dmd_show_low
#define display_show_high       dmd_show_high
#define display_show_other      dmd_show_other
#define display_flip_low_high   dmd_flip_low_high
#define display_clean_page      dmd_clean_page
#define display_memset          dmd_memset
#define display_clean_page_low  dmd_clean_page_low
#define display_clean_page_high dmd_clean_page_high
#define display_copy_page       dmd_copy_page
#define display_copy_low_to_high dmd_copy_low_to_high
#define display_alloc_low_clean dmd_alloc_low_clean
#define display_alloc_pair_clean dmd_alloc_pair_clean
#define display_sched_transition dmd_sched_transition

#else /* not DMD, using alphanumeric segment displays */

#include <sys/segment.h>

#define DISPLAY_WIDTH           SEG_WIDTH
#define DISPLAY_HEIGHT          SEG_HEIGHT

/* Portable display functions */
#define display_init            seg_init
#define display_alloc_low       seg_alloc_low
#define display_alloc_high      seg_alloc_high
#define display_alloc_low_high  seg_alloc_low_high
#define display_map_low_high    seg_map_low_high
#define display_show_low        seg_show_low
#define display_show_high       seg_show_high
#define display_show_other      seg_show_other
#define display_flip_low_high   seg_flip_low_high
#define display_clean_page      seg_clean_page
#define display_memset          seg_memset
#define display_clean_page_low  seg_clean_page_low
#define display_clean_page_high seg_clean_page_high
#define display_copy_page       seg_copy_page
#define display_copy_low_to_high seg_copy_low_to_high
#define display_alloc_low_clean seg_alloc_low_clean
#define display_alloc_pair_clean seg_alloc_pair_clean
#define display_sched_transition(x)

#define dmd_init(args...)
#define dmd_alloc_low(args...)
#define dmd_alloc_high(args...)
#define dmd_alloc_low_high(args...)
#define dmd_map_low_high(args...)
#define dmd_show_low(args...)
#define dmd_show_high(args...)
#define dmd_show_other(args...)
#define dmd_flip_low_high(args...)
#define dmd_clean_page(args...)
#define dmd_memset(args...)
#define dmd_clean_page_low(args...)
#define dmd_clean_page_high(args...)
#define dmd_copy_page(args...)
#define dmd_copy_low_to_high(args...)
#define dmd_alloc_low_clean(args...)
#define dmd_alloc_pair_clean(args...)
#define dmd_sched_transition(args...)
#define dmd_reset_transition(args...)
#define dmd_draw_border(args...)
#define dmd_draw_horiz_line(args...)
#define dmd_invert_page(args...)
#define dmd_show2(args...)

#define font_render_string_center(args...)
#define font_render_string_right(args...)
#define font_render_string_left(args...)
#define font_render_string(args...)

#endif

/* Derived definitions.  These are truly in common for all
display types. */

/* Display update options */

#define DIS_COLOR 0x1         /* Image uses 2-bits per pixel instead of one */
#define DIS_CLEAN 0x2         /* Display should be wiped clean to start */
#define DIS_DUP 0x4           /* Display should start from previous image */
#define DIS_DIM 0x8           /* Mono image should be shown at 33% intensity */
#define DIS_BRIGHT 0x10       /* Mono image should be shown at 100% intensity */
#define DIS_FLIP 0x20         /* Display will flip between two images */

/* Called at the beginning of a display update */
#define display_begin(flags) { const U8 __dflags = flags; __display_begin (flags);

/* Called at the end of a display update */
#define display_end() __display_end (flags); }

/* Called when page flipping is being done, to signal that the alternate
 * page(s) are about to be drawn */
#define display_flip()

/* Return the column value to be used when the display is to be
divided into T total vertical parts, and we want to address
the upper-left corner of the Nth part. */
#define display_col_val(n,t)   ((SEG_WIDTH / t) * n)

/* Return the row value to be used when the display is to be
divided into T total horizontal parts, and we want to address
the upper-left corner of the Nth part. */
#define display_row_val(n,t)   ((SEG_HEIGHT / t) * n)

#define REGION_ALL             0, 0, SEG_WIDTH, SEG_HEIGHT

#define REG_TOP_HALF(x1,y1,x2,y2) \
	x1, y1, x2, (y1 + (y2-y1)/2)

#define REGION_TOP_HALF \
	display_col_val(0,1), display_row_val(0,2), \
	display_col_val(0,1), display_row_val(1,2)-1

#define display_print(region, justification, string)


