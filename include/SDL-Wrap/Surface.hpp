#ifndef SDL_WRAP_SURFACE_H
#define SDL_WRAP_SURFACE_H

#include <SDL-Wrap/Types.hpp>

#include <SDL3/SDL.h>

namespace SDLW {

	class Texture;

	class Surface {
	friend Texture;
	private:
		SDL_Surface* sdlSurface;
	
	public:
		Surface ();
		Surface (int w, int h, PixelFormat format);
		Surface (int w, int h, PixelFormat format, void* pixels, int pitch);
		~Surface ();

		void Blit (const Rect* srcrect, Surface* surface, const Rect* dstrect);
		void Blit (Surface* surface, const Rect* dstrect);
		void Blit (Surface* surface, int x, int y);
	};

}

#endif