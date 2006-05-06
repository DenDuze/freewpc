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

#ifndef _HIGHSCORE_H
#define _HIGHSCORE_H

#define HIGH_SCORE_WIDTH	4
#define HIGH_SCORE_NAMESZ	3
#define NUM_HIGH_SCORES		4

void high_score_amode_show (void);
void high_score_reset (void);
void high_score_init (void);
void high_score_reset_check (void);
void high_score_check (void);

#endif /* _HIGHSCORE_H */
