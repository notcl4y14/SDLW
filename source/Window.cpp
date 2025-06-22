#include <SDL-Wrap/Window.hpp>

namespace SDLW {

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

}