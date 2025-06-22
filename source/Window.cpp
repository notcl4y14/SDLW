#include <SDL-Wrap/Window.hpp>

namespace SDLW {

	Window::Window (const char* title,
	                const unsigned int width,
	                const unsigned int height) {
		this->window_handle =
			SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);
	}

	Window::Window (const unsigned int width,
	                const unsigned int height) {
		this->window_handle =
			SDL_CreateWindow("", width, height, SDL_WINDOW_RESIZABLE);
	}

	Window::~Window () {
		SDL_DestroyWindow(this->window_handle);
	}

}