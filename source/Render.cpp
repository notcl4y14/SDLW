#include <SDL-Wrap/Render.hpp>

#include <SDL-Wrap/Window.hpp>

namespace SDLW {

	Render::Render () {
		this->window = NULL;
		this->sdlRender = NULL;
	}

	Render::Render (Window* window) {
		this->window = window;
		this->sdlRender = SDL_CreateRenderer(this->window->sdlWindow, NULL);
	}

	Render::~Render () {
		SDL_DestroyRenderer(this->sdlRender);
	}

	void Render::Create (Window* window) {
		this->window = window;
		this->sdlRender = SDL_CreateRenderer(this->window->sdlWindow, NULL);
	}

	void Render::SetDrawColor (Color color) {
		SDL_SetRenderDrawColor(
			this->sdlRender,
			color.r, color.g, color.b, color.a);
	}

	void Render::Clear () {
		SDL_RenderClear(this->sdlRender);
	}

	void Render::Present () {
		SDL_RenderPresent(this->sdlRender);
	}

	void Render::SetDrawBlendMode (BlendMode mode) {
		SDL_SetRenderDrawBlendMode(this->sdlRender, mode);
	}

	void Render::SetScale (float x, float y) {
		SDL_SetRenderScale(this->sdlRender, x, y);
	}

	void Render::GetScale (float* x, float* y) {
		SDL_GetRenderScale(this->sdlRender, x, y);
	}

	void Render::DrawRect (float x, float y, float w, float h) {
		const SDL_FRect frect = { x, y, w, h };
		SDL_RenderRect(this->sdlRender, &frect);
	}

	void Render::FillRect (float x, float y, float w, float h) {
		const SDL_FRect frect = { x, y, w, h };
		SDL_RenderFillRect(this->sdlRender, &frect);
	}

	void Render::DrawRectFixed (float x1, float y1, float x2, float y2) {
		const SDL_FRect frect = { x1, y1, x2 - x1, y2 - y1 };
		SDL_RenderRect(this->sdlRender, &frect);
	}

	void Render::FillRectFixed (float x1, float y1, float x2, float y2) {
		const SDL_FRect frect = { x1, y1, x2 - x1, y2 - y1 };
		SDL_RenderFillRect(this->sdlRender, &frect);
	}

	void Render::DrawLine (float x1, float y1, float x2, float y2) {
		SDL_RenderLine(this->sdlRender, x1, y1, x2, y2);
	}

	void Render::DrawTexture (Texture* texture, const FRect* srcrect, const FRect* dstrect) {
		SDL_RenderTexture(this->sdlRender, texture->sdlTexture, srcrect, dstrect);
	}

	void Render::DrawTexture (Texture* texture, const FRect* dstrect) {
		const FRect srcrect = {
			0, 0,
			(float) texture->sdlTexture->w,
			(float) texture->sdlTexture->h,
		};
		SDL_RenderTexture(this->sdlRender, texture->sdlTexture, &srcrect, dstrect);
	}

	void Render::DrawTexture (Texture* texture, float x, float y) {
		const FRect srcrect = {
			0, 0,
			(float) texture->sdlTexture->w,
			(float) texture->sdlTexture->h,
		};
		const FRect dstrect = {
			x, y,
			srcrect.w,
			srcrect.h,
		};
		SDL_RenderTexture(this->sdlRender, texture->sdlTexture, &srcrect, &dstrect);
	}

}