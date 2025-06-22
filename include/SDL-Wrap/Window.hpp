#ifndef SDL_WRAP_WINDOW_H
#define SDL_WRAP_WINDOW_H

#include <SDL-Wrap/Render.hpp>

#include <SDL3/SDL.h>

namespace SDLW {

	class Window {
		friend Render;
	private:
		SDL_Window* sdlWindow;
	
	public:
		Window ();
		Window (const char* title,
		        const unsigned int width,
		        const unsigned int height);
		Window (const unsigned int width,
		        const unsigned int height);
		~Window ();
	};

}

#endif