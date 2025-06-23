#include <SDL-Wrap/Surface.hpp>

namespace SDLW {

	Surface::Surface () {
		this->sdlSurface = NULL;
	}

	Surface::Surface (int w, int h, PixelFormat format) {
		this->sdlSurface = SDL_CreateSurface(w, h, format);
	}

	Surface::Surface (int w, int h, PixelFormat format, void* pixels, int pitch) {
		this->sdlSurface = SDL_CreateSurfaceFrom(w, h, format, pixels, pitch);
	}

	Surface::~Surface () {
		SDL_DestroySurface(this->sdlSurface);
	}

	void Surface::Blit (const Rect* srcrect, Surface* surface, const Rect* dstrect) {
		SDL_BlitSurface(this->sdlSurface, srcrect, surface->sdlSurface, dstrect);
	}

	void Surface::Blit (Surface* surface, const Rect* dstrect) {
		const Rect srcrect = {
			0, 0,
			this->sdlSurface->w,
			this->sdlSurface->h,
		};
		SDL_BlitSurface(this->sdlSurface, &srcrect, surface->sdlSurface, dstrect);
	}

	void Surface::Blit (Surface* surface, int x, int y) {
		const Rect srcrect = {
			0, 0,
			this->sdlSurface->w,
			this->sdlSurface->h,
		};
		const Rect dstrect = {
			x, y,
			srcrect.w,
			srcrect.h,
		};
		SDL_BlitSurface(this->sdlSurface, &srcrect, surface->sdlSurface, &dstrect);
	}
}