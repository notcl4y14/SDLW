#ifndef SDL_WRAP_RENDER_H
#define SDL_WRAP_RENDER_H

#include <SDL-Wrap/Color.hpp>

#include <SDL3/SDL.h>

namespace SDLW {

	class Window;

	class Render {
	private:
		Window* window;
		SDL_Renderer* render_handle;
	
	public:
		Render ();
		Render (Window* window);
		~Render ();

		void SetDrawColor (Color color);

		void Clear ();
		void Present ();

		void DrawRect (float x, float y, float w, float h);
		void FillRect (float x, float y, float w, float h);
		void DrawRectFixed (float x1, float y1, float x2, float y2);
		void FillRectFixed (float x1, float y1, float x2, float y2);
		void DrawLine (float x1, float y1, float x2, float y2);
	};

}

#endif