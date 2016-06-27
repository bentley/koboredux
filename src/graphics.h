/*(GPLv2)
------------------------------------------------------------
   Kobo Deluxe - An enhanced SDL port of XKobo
------------------------------------------------------------
 * Copyright 2016 David Olofson (Kobo Redux)
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

#ifndef _KOBO_GRAPHICS_H_
#define _KOBO_GRAPHICS_H_

// Graphics banks
#define KOBO_ALLGFXBANKS			\
	KOBO_DEFS(NONE)				\
						\
	KOBO_DEFS(SPACE)			\
						\
	KOBO_DEFS(R1_TILES)			\
	KOBO_DEFS(R2_TILES)			\
	KOBO_DEFS(R3_TILES)			\
	KOBO_DEFS(R4_TILES)			\
	KOBO_DEFS(R5_TILES)			\
\
	KOBO_DEFS(R1_TILES_SMALL_SPACE)		\
	KOBO_DEFS(R2_TILES_SMALL_SPACE)		\
	KOBO_DEFS(R3_TILES_SMALL_SPACE)		\
	KOBO_DEFS(R4_TILES_SMALL_SPACE)		\
	KOBO_DEFS(R5_TILES_SMALL_SPACE)		\
\
	KOBO_DEFS(R1_TILES_TINY_SPACE)		\
	KOBO_DEFS(R2_TILES_TINY_SPACE)		\
	KOBO_DEFS(R3_TILES_TINY_SPACE)		\
	KOBO_DEFS(R4_TILES_TINY_SPACE)		\
	KOBO_DEFS(R5_TILES_TINY_SPACE)		\
\
	KOBO_DEFS(R1_TILES_TINY_INTERMEDIATE)	\
	KOBO_DEFS(R2_TILES_TINY_INTERMEDIATE)	\
	KOBO_DEFS(R3_TILES_TINY_INTERMEDIATE)	\
	KOBO_DEFS(R4_TILES_TINY_INTERMEDIATE)	\
	KOBO_DEFS(R5_TILES_TINY_INTERMEDIATE)	\
\
	KOBO_DEFS(R1_TILES_SMALL_GROUND)	\
	KOBO_DEFS(R2_TILES_SMALL_GROUND)	\
	KOBO_DEFS(R3_TILES_SMALL_GROUND)	\
	KOBO_DEFS(R4_TILES_SMALL_GROUND)	\
	KOBO_DEFS(R5_TILES_SMALL_GROUND)	\
\
	KOBO_DEFS(R1_TILES_TINY_GROUND)		\
	KOBO_DEFS(R2_TILES_TINY_GROUND)		\
	KOBO_DEFS(R3_TILES_TINY_GROUND)		\
	KOBO_DEFS(R4_TILES_TINY_GROUND)		\
	KOBO_DEFS(R5_TILES_TINY_GROUND)		\
\
	KOBO_DEFS(R1_PLANET)			\
	KOBO_DEFS(R2_PLANET)			\
	KOBO_DEFS(R3_PLANET)			\
	KOBO_DEFS(R4_PLANET)			\
	KOBO_DEFS(R5_PLANET)			\
\
	KOBO_DEFS(R1_CLOUDS)			\
	KOBO_DEFS(R2_CLOUDS)			\
	KOBO_DEFS(R3_CLOUDS)			\
	KOBO_DEFS(R4_CLOUDS)			\
	KOBO_DEFS(R5_CLOUDS)			\
\
	KOBO_DEFS(R1L8_GROUND)			\
	KOBO_DEFS(R2L8_GROUND)			\
	KOBO_DEFS(R3L8_GROUND)			\
	KOBO_DEFS(R4L8_GROUND)			\
	KOBO_DEFS(R5L8_GROUND)			\
\
	KOBO_DEFS(R1L9_GROUND)			\
	KOBO_DEFS(R2L9_GROUND)			\
	KOBO_DEFS(R3L9_GROUND)			\
	KOBO_DEFS(R4L9_GROUND)			\
	KOBO_DEFS(R5L9_GROUND)			\
\
	KOBO_DEFS(R1L10_GROUND)			\
	KOBO_DEFS(R2L10_GROUND)			\
	KOBO_DEFS(R3L10_GROUND)			\
	KOBO_DEFS(R4L10_GROUND)			\
	KOBO_DEFS(R5L10_GROUND)			\
\
	KOBO_DEFS(PLAYER)			\
	KOBO_DEFS(BLT_GREEN)			\
	KOBO_DEFS(BLT_RED)			\
	KOBO_DEFS(BLT_BLUE)			\
	KOBO_DEFS(BLTX_GREEN)			\
	KOBO_DEFS(BLTX_RED)			\
	KOBO_DEFS(BLTX_BLUE)			\
	KOBO_DEFS(RING)				\
	KOBO_DEFS(RINGEXPL)			\
	KOBO_DEFS(BOMB)				\
	KOBO_DEFS(BOMBDETO)			\
	KOBO_DEFS(BOLT)				\
	KOBO_DEFS(EXPLO1)			\
	KOBO_DEFS(EXPLO3)			\
	KOBO_DEFS(EXPLO4)			\
	KOBO_DEFS(EXPLO5)			\
	KOBO_DEFS(ROCK1)			\
	KOBO_DEFS(ROCK2)			\
	KOBO_DEFS(ROCK3)			\
	KOBO_DEFS(ROCKEXPL)			\
	KOBO_DEFS(BMR_GREEN)			\
	KOBO_DEFS(BMR_PURPLE)			\
	KOBO_DEFS(BMR_PINK)			\
	KOBO_DEFS(FIGHTER)			\
	KOBO_DEFS(MISSILE1)			\
	KOBO_DEFS(MISSILE2)			\
	KOBO_DEFS(MISSILE3)			\
	KOBO_DEFS(BIGSHIP)			\
\
	KOBO_DEFS(NOISE)			\
	KOBO_DEFS(HITNOISE)			\
	KOBO_DEFS(FOCUSFX)			\
	KOBO_DEFS(SHIELDFX)			\
\
	KOBO_DEFS(SCREEN)			\
	KOBO_DEFS(CROSSHAIR)			\
	KOBO_DEFS(HLEDS)			\
	KOBO_DEFS(VLEDS)			\
	KOBO_DEFS(BLEDS)			\
	KOBO_DEFS(LOGO)				\
\
	KOBO_DEFS(HIGH_BACK)			\
	KOBO_DEFS(SCORE_BACK)			\
	KOBO_DEFS(RADAR_BACK)			\
	KOBO_DEFS(SHIPS_BACK)			\
	KOBO_DEFS(STAGE_BACK)			\
\
	KOBO_DEFS(OALOGO)			\
	KOBO_DEFS(OAPLANET)			\
\
	KOBO_DEFS(LOADER_FONT)			\
	KOBO_DEFS(DEBUG_FONT)			\
	KOBO_DEFS(TOOL_FONT)			\
	KOBO_DEFS(SMALL_FONT)			\
	KOBO_DEFS(NORMAL_FONT)			\
	KOBO_DEFS(MEDIUM_FONT)			\
	KOBO_DEFS(BIG_FONT)			\
	KOBO_DEFS(COUNTER_FONT)			\
\
	KOBO_DEFS(SOUND_ICONS)


#define	KOBO_DEFS(x)	B_##x,
enum KOBO_gfxbanks
{
	KOBO_ALLGFXBANKS
	B__COUNT
};
#undef	KOBO_DEFS

extern const char *kobo_gfxbanknames[];


#define KOBO_ALLPALETTES		\
	KOBO_DEFS(LOADER)		\
	KOBO_DEFS(LOADER_NOISE)		\
	KOBO_DEFS(LOADER_STARS)		\
	KOBO_DEFS(PROGRESS_BAR)		\
	KOBO_DEFS(MAIN)			\
	KOBO_DEFS(MAIN_STARS)		\
	KOBO_DEFS(RADAR)		\
	KOBO_DEFS(PLANET_R1)		\
	KOBO_DEFS(PLANET_R2)		\
	KOBO_DEFS(PLANET_R3)		\
	KOBO_DEFS(PLANET_R4)		\
	KOBO_DEFS(PLANET_R5)

#define	KOBO_DEFS(x)	KOBO_P_##x,
enum KOBO_Palettes
{
	KOBO_ALLPALETTES
	KOBO_P__COUNT
};
#undef	KOBO_DEFS

extern const char *kobo_palettenames[];


enum KOBO_LogoEffects
{
	KOBO_LOGO_FX_SLIDE = 0,
	KOBO_LOGO_FX_FADE,
	KOBO_LOGO_FX_ZOOM
};


#define KOBO_ALLTDITEMS			\
	KOBO_DEFS(LOGO_EFFECT)		\
	KOBO_DEFS(BACKDROP_COLORMOD)	\
	KOBO_DEFS(PLANET_DITHERMODE)	\
	KOBO_DEFS(PLANET_COLORMOD)	\
	KOBO_DEFS(PLANET_BRIGHTNESS)	\
	KOBO_DEFS(PLANET_CONTRAST)	\
	KOBO_DEFS(BASES_COLORMOD)	\
	KOBO_DEFS(DASH_LOADER_PLANET)	\
	KOBO_DEFS(DASH_MAIN)		\
	KOBO_DEFS(DASH_CONSOLE)		\
	KOBO_DEFS(DASH_HEALTH)		\
	KOBO_DEFS(DASH_CHARGE)		\
	KOBO_DEFS(DASH_RADAR)		\
	KOBO_DEFS(DASH_TOPLEDS)		\
	KOBO_DEFS(DASH_BOTTOMLEDS)	\
	KOBO_DEFS(DASH_LEFTLEDS)	\
	KOBO_DEFS(DASH_RIGHTLEDS)

#define	KOBO_DEFS(x)	KOBO_D_##x,
enum KOBO_TD_Items
{
	KOBO_ALLTDITEMS
	KOBO_D__COUNT
};
#undef	KOBO_DEFS

extern const char *kobo_datanames[];


enum KOBO_GfxDescFlags
{
	// Clamping/wrapping options for filters
	KOBO_CLAMP =		0x0001,	// Clamp to frame edge pixels
	KOBO_CLAMP_OPAQUE =	0x0002,	// Clamp to black; not transparent
	KOBO_WRAP =		0x0004,	// Wrap around frame edges

	// Scaling filter options
	KOBO_ABSSCALE =		0x0010,	// Scale factor is absolute
	KOBO_NEAREST =		0x0020,	// Force NEAREST scale mode
	KOBO_BILINEAR =		0x0040,	// Force BILINEAR scale mode
	KOBO_SCALE2X =		0x0080,	// Force Scale2X scale mode

	// Other options
	KOBO_NOALPHA =		0x0100,	// Disable alpha channel
	KOBO_CENTER =		0x0200,	// Center hotspot in frames
	KOBO_NOBRIGHT =		0x0400,	// Disable brightness/contrast filter
	KOBO_FALLBACK =		0x1000,	// Disable "in use" overwrite warning
	KOBO_FUTURE =		0x2000	// Allow alias to (still) empty banks
};

#endif // _KOBO_GRAPHICS_H_
