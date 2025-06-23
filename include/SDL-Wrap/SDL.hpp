#ifndef SDL_WRAP_SDL_H
#define SDL_WRAP_SDL_H

#include <SDL-Wrap/Color.hpp>
#include <SDL-Wrap/Event.hpp>
#include <SDL-Wrap/Render.hpp>
#include <SDL-Wrap/Surface.hpp>
#include <SDL-Wrap/Texture.hpp>
#include <SDL-Wrap/Types.hpp>
#include <SDL-Wrap/Window.hpp>

#include <SDL3/SDL.h>

namespace SDLW {

	void Init (SDL_InitFlags flags);
	void Quit ();

	void Delay (unsigned int ms);

	bool PollEvent (Event* event);
	
}

#endif