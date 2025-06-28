#ifndef SDL_WRAP_TEXTURE_H
#define SDL_WRAP_TEXTURE_H

#include <SDL-Wrap/Types.hpp>

#include <SDL3/SDL.h>

namespace SDLW {

	class Render;
	class Surface;

	class Texture {
	friend Render;
	private:
		SDL_Texture* sdlTexture;
	
	public:
		Texture ();
		Texture (Render* render,
		         PixelFormat format,
		         TextureAccess access,
		         int w, int h);
		Texture (Render* render, Surface* surface);
		~Texture ();

		void Create (Render* render,
		             PixelFormat format,
		             TextureAccess access,
		             int w, int h);
		void Create (Render* render, Surface* surface);

		void SetBlendMode (BlendMode mode);
		void SetScaleMode (ScaleMode mode);
	};

}

#endif