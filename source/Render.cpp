#include <SDL-Wrap/Render.hpp>

#include <SDL-Wrap/Window.hpp>

namespace SDLW {

	Render::Render (Window* window) {
		this->window = window;
		this->render_handle = SDL_CreateRenderer(this->window->window_handle, NULL);
	}

	Render::~Render () {
		SDL_DestroyRenderer(this->render_handle);
	}

	void Render::SetDrawColor (Color color) {
		SDL_SetRenderDrawColor(
			this->render_handle,
			color.r, color.g, color.b, color.a);
	}

	void Render::Clear () {
		SDL_RenderClear(this->render_handle);
	}

	void Render::Present () {
		SDL_RenderPresent(this->render_handle);
	}

	void Render::DrawRect (float x, float y, float w, float h) {
		const SDL_FRect frect = { x, y, w, h };
		SDL_RenderRect(this->render_handle, &frect);
	}

	void Render::FillRect (float x, float y, float w, float h) {
		const SDL_FRect frect = { x, y, w, h };
		SDL_RenderFillRect(this->render_handle, &frect);
	}

	void Render::DrawRectFixed (float x1, float y1, float x2, float y2) {
		const SDL_FRect frect = { x1, y1, x2 - x1, y2 - y1 };
		SDL_RenderRect(this->render_handle, &frect);
	}

	void Render::FillRectFixed (float x1, float y1, float x2, float y2) {
		const SDL_FRect frect = { x1, y1, x2 - x1, y2 - y1 };
		SDL_RenderFillRect(this->render_handle, &frect);
	}

	void Render::DrawLine (float x1, float y1, float x2, float y2) {
		SDL_RenderLine(this->render_handle, x1, y1, x2, y2);
	}

}