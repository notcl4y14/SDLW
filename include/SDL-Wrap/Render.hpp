#ifndef SDL_WRAP_RENDER_H
#define SDL_WRAP_RENDER_H

#include <SDL-Wrap/Color.hpp>
#include <SDL-Wrap/Texture.hpp>
#include <SDL-Wrap/Types.hpp>

#include <SDL3/SDL.h>

namespace SDLW {

	class Window;

	class Render {
	friend Texture;
	private:
		Window* window;
		SDL_Renderer* sdlRender;
	
	public:
		Render ();
		Render (Window* window);
		~Render ();

		void Create (Window* window);

		void SetDrawColor (Color color);

		void Clear ();
		void Present ();

		void SetDrawBlendMode (BlendMode mode);

		void DrawRect (float x, float y, float w, float h);
		void FillRect (float x, float y, float w, float h);
		void DrawRectFixed (float x1, float y1, float x2, float y2);
		void FillRectFixed (float x1, float y1, float x2, float y2);
		void DrawLine (float x1, float y1, float x2, float y2);
		void DrawTexture (Texture* texture, const FRect* srcrect, const FRect* dstrect);
		void DrawTexture (Texture* texture, const FRect* dstrect);
		void DrawTexture (Texture* texture, float x, float y);
	};

}

#endif