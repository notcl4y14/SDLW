#include <SDL-Wrap/Event.hpp>
#include <SDL-Wrap/SDL.hpp>

#include <SDL3/SDL.h>

namespace SDLW {

	void Init (SDL_InitFlags flags) {
		// TODO: Make this choosable
		SDL_Init(flags);
	}

	void Quit () {
		SDL_Quit();
	}

	void Delay (unsigned int ms) {
		SDL_Delay(ms);
	}

	bool PollEvent (Event* event) {
		return SDL_PollEvent(event);
	}
	
}