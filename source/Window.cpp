#include <SDL-Wrap/Window.hpp>

namespace SDLW {

	Window::Window () {
		this->sdlWindow = NULL;
	}

	Window::Window (const char* title,
	                const unsigned int width,
	                const unsigned int height) {
		this->sdlWindow =
			SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);
	}

	Window::Window (const unsigned int width,
	                const unsigned int height) {
		this->sdlWindow =
			SDL_CreateWindow("", width, height, SDL_WINDOW_RESIZABLE);
	}

	Window::~Window () {
		SDL_DestroyWindow(this->sdlWindow);
	}

	void Window::Create (const char* title,
					     const unsigned int width,
					     const unsigned int height) {
		this->sdlWindow =
			SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);
	}
		
	bool Window::SetRelativeMouseMode (bool enabled) {
		return SDL_SetWindowRelativeMouseMode(this->sdlWindow, enabled);
	}

	bool Window::SetMouseRect (int x, int y, int w, int h) {
		const SDL_Rect rect = { x, y, w, h };
		return SDL_SetWindowMouseRect(this->sdlWindow, &rect);
	}

}