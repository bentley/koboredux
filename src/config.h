/*(GPLv2)
------------------------------------------------------------
   Kobo Deluxe - An enhanced SDL port of XKobo
------------------------------------------------------------
 * Copyright 1995, 1996, Akira Higuchi
 * Copyright 2001-2003, 2009 David Olofson
 * Copyright 2008 Robert Schuster
 * Copyright 2015-2016 David Olofson (Kobo Redux)
 * 
 * This program  is free software; you can redistribute it and/or modify it
 * under the terms  of  the GNU General Public License  as published by the
 * Free Software Foundation;  either version 2 of the License,  or (at your
 * option) any later version.
 *
 * This program is  distributed  in  the hope that  it will be useful,  but
 * WITHOUT   ANY   WARRANTY;   without   even   the   implied  warranty  of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 *
 * You should have received  a copy of the GNU General Public License along
 * with this program; if not,  write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef _KOBO_CONFIG_H_
#define _KOBO_CONFIG_H_

#define	KOBO_COPYRIGHT	"Copyright 2016 Olofson Arcade. All rights reserved."
 
#include "buildconfig.h"

#ifndef DEBUG
#	undef	DBG
#	undef	DBG2
#	undef	DBG3
#	undef	DBG4
#	define	DBG(x)
#	define	DBG2(x)
#	define	DBG3(x)
#	define	DBG4(x)
#endif

#ifndef KOBO_HAVE_SNPRINTF
#ifndef KOBO_HAVE__SNPRINTF
#error	Must have snprintf() or _snprintf!
#endif
#define snprintf _snprintf
#endif

#ifndef KOBO_HAVE_VSNPRINTF
#ifndef KOBO_HAVE__VSNPRINTF
#error	Must have vsnprintf() or _vsnprintf!
#endif
#define vsnprintf _vsnprintf
#endif

// Default and fallback graphics themes
#define	KOBO_LOADER_GFX_THEME		"GFX>>loader"
#define	KOBO_FALLBACK_GFX_THEME		"GFX>>mono"
#define	KOBO_DEFAULT_GFX_THEME		"GFX>>redux"
#define	KOBO_DEFAULT_TOOLS_THEME	"GFX>>tools"

// Default and fallback sound themes
#define	KOBO_LOADER_SFX_THEME		"SFX>>loader"
#define	KOBO_FALLBACK_SFX_THEME		"SFX>>chip"
#define	KOBO_DEFAULT_SFX_THEME		"SFX>>redux"

// Sound banks to load the different sound themes into
enum KOBO_sound_banks {
	KOBO_SB_ALL = -1,
	KOBO_SB_LOADER = 0,
	KOBO_SB_FALLBACK,
	KOBO_SB_MAIN
};

/*
 * SDL2 pixel format for surface and textures.
 *
 * NOTE: The pix_t struct in sprite.h, and the color mapping methods of
 *       window_t need to match this!
 */
#define	KOBO_PIXELFORMAT	SDL_PIXELFORMAT_ARGB8888

/*
 * Fraction of the screen size in which clicks are not considered
 * clicks but movements in that direction (as regarded from the
 * center of the screen) or other special things (pause & exit).
 *
 * Used only in touchscreen mode.
 */
#define POINTER_MARGIN_PERCENT	10

/*
 * Fraction of the screen size in which clicks are not considered
 * clicks but movements in that direction (as regarded from the
 * center of the screen) or other special things (pause & exit).
 *
 * Used only in touchscreen mode.
 */
#define POINTER_MARGIN_PERCENT	10

/* Various size info (DO NOT EDIT!) */
#define TILE_SIZEX_LOG2		4
#define TILE_SIZEY_LOG2		4
#define MAP_SIZEX_LOG2		6
#define MAP_SIZEY_LOG2		7
#define WORLD_SIZEX_LOG2	(MAP_SIZEX_LOG2 + TILE_SIZEX_LOG2)
#define WORLD_SIZEY_LOG2	(MAP_SIZEY_LOG2 + TILE_SIZEY_LOG2)
#define NOISE_SIZEX_LOG2	8
#define TILE_SIZEX		(1 << TILE_SIZEX_LOG2)
#define TILE_SIZEY		(1 << TILE_SIZEY_LOG2)
#define MAP_SIZEX		(1 << MAP_SIZEX_LOG2)
#define MAP_SIZEY		(1 << MAP_SIZEY_LOG2)
#define WORLD_SIZEX		(1 << WORLD_SIZEX_LOG2)
#define WORLD_SIZEY		(1 << WORLD_SIZEY_LOG2)
#define NOISE_SIZEX		(1 << NOISE_SIZEX_LOG2)

/* World to map coordinate translation */
#define	WORLD2MAPX(x)	(((x) & (WORLD_SIZEX - 1)) >> TILE_SIZEX_LOG2)
#define	WORLD2MAPY(y)	(((y) & (WORLD_SIZEY - 1)) >> TILE_SIZEY_LOG2)

static inline int kobo_wrapdist(int a, int b, int w)
{
	int d1 = (a - b) & (w - 1);
	int d2 = (b - a) & (w - 1);
	return d1 < d2 ? d1 : -d2;
}

#define	WRAPDISTX(x1, x2)	kobo_wrapdist(x1, x2, WORLD_SIZEX)
#define	WRAPDISTY(y1, y2)	kobo_wrapdist(y1, y2, WORLD_SIZEY)
#define	WRAPDISTXCS(x1, x2)	kobo_wrapdist(x1, x2, PIXEL2CS(WORLD_SIZEX))
#define	WRAPDISTYCS(y1, y2)	kobo_wrapdist(y1, y2, PIXEL2CS(WORLD_SIZEY))

/* Text scroller speed (pixels/second) */
#define	SCROLLER_SPEED		120

/* Raster noise burst effect duration (ms) */
#define	KOBO_NOISEBURST_DURATION	900

/* Intro loop timing */
#define	INTRO_BLANK_TIME	1000	/* Inter-page blanking */
#define	INTRO_TITLE_TIME	7000	/* "Real" title show time */
#define	INTRO_TITLE2_TIME	5500	/* Intermediate title show time */
#define	INTRO_INSTRUCTIONS_TIME	19700
#define	INTRO_HIGHSCORE_TIME	11700
#define	INTRO_CREDITS_TIME	13700

/* Level used as backdrop for the Options menus */
#define	KOBO_OPTIONS_BACKGROUND_LEVEL	6

/* Level used as backdrop for the title screen (used to be 16) */
#define	KOBO_TITLE_LEVEL		14

/*
 * This was originally 320x240. Kobo Redux changes the "native" resolution to
 * 640x360, while keeping the 16x16 tile size, so the view size is now 50%
 * larger than in XKobo and Kobo Deluxe.
 */
#define	SCREEN_WIDTH		640
#define	SCREEN_HEIGHT		360

/*
 * Map tile size in "native" 640x360 pixels. Until Kobo Redux, this was 32, but
 * indirectly derived from CHIP_SIZE*, rather than defined explicitly.
 */
#define	TILE_SIZE		16

/* Camera lead control */
#define	KOBO_CAM_LEAD		6	/* Player speed to lead factor */
#define	KOBO_CAM_LEAD_SPEED	256	/* Lead target slide speed */
#define	KOBO_CAM_LEAD_FILTER	32	/* Lead target IIR filter coeff. */

/* Ingame camera filter */
#define	KOBO_CAM_FILTER		4.0f

/* Number of parallax background map levels */
#define	KOBO_BG_MAP_LEVELS	2

/* Number of proximity warning LEDs along each edge of the main view window. */
#define	PROXY_LEDS		42

/* Proximity warning LED fade speed (units per logic frame; 16:16 fixp) */
#define	PROXY_LIGHTSPEED	16384
#define	PROXY_FADESPEED		8192

/* Proximity warning LED effects configuration */
#define	PROXY_SCAN_WIDTH	7
#define	PROXY_FLASH_PERIOD	30
#define	PROXY_FLASH_DURATION	20

/* Proximity indicator LED bars */
#define PROXY_LED_SIZE		8

/* Health/shield LED bar */
#define	SHIELD_GRADIENT_SIZE	4
#define	SHIELD_FILTER_COEFF	0.01f	// (per ms)
#undef	SHIELD_DITHER

#endif	/*_KOBO_CONFIG_H_*/
