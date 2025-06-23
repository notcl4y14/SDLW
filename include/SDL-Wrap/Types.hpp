#ifndef SDL_WRAP_TYPES_H
#define SDL_WRAP_TYPES_H

#include <SDL3/SDL.h>

namespace SDLW {

	typedef SDL_InitFlags InitFlags;

	typedef SDL_KeyboardID KeyboardID;
	typedef SDL_Keycode Keycode;
	typedef SDL_Keymod Keymod;

	typedef SDL_PixelFormat PixelFormat;
	typedef SDL_TextureAccess TextureAccess;
	typedef SDL_BlendMode BlendMode;
	typedef SDL_ScaleMode ScaleMode;

	typedef SDL_Rect Rect;
	typedef SDL_FRect FRect;

}

#endif