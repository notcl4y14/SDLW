#include <SDL-Wrap/Texture.hpp>

#include <SDL-Wrap/Render.hpp>
#include <SDL-Wrap/Surface.hpp>

namespace SDLW {

	Texture::Texture () {
		this->sdlTexture = NULL;
	}

	Texture::Texture (Render* render,
	                  PixelFormat format,
	                  TextureAccess access,
	                  int w, int h) {
		this->sdlTexture = SDL_CreateTexture(render->sdlRender, format, access, w, h);
	}

	Texture::Texture (Render* render,
	                  Surface* surface) {
		this->sdlTexture = SDL_CreateTextureFromSurface(render->sdlRender, surface->sdlSurface);
	}

	Texture::~Texture () {
		SDL_DestroyTexture(this->sdlTexture);
	}

	void Texture::Create (Render* render,
	                      PixelFormat format,
	                      TextureAccess access,
	                      int w, int h) {
		this->sdlTexture = SDL_CreateTexture(render->sdlRender, format, access, w, h);
	}
	
	void Texture::Create (Render* render, Surface* surface) {
		this->sdlTexture = SDL_CreateTextureFromSurface(render->sdlRender, surface->sdlSurface);
	}

	void Texture::SetBlendMode (BlendMode mode) {
		SDL_SetTextureBlendMode(this->sdlTexture, mode);
	}

	void Texture::SetScaleMode (ScaleMode mode) {
		SDL_SetTextureScaleMode(this->sdlTexture, mode);
	}
	
}