#include <SDL-Wrap/Render.hpp>

#include <SDL-Wrap/Window.hpp>

namespace SDLW {

	Render::Render (Window* window) {
		this->window = window;
		this->sdlRender = SDL_CreateRenderer(this->window->sdlWindow, NULL);
	}

	Render::~Render () {
		SDL_DestroyRenderer(this->sdlRender);
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

}