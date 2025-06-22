#ifndef SDL_WRAP_COLOR_H
#define SDL_WRAP_COLOR_H

#include <SDL3/SDL.h>

namespace SDLW {

	class Color {
	public:
		static Color BLACK;
		static Color WHITE;
		static Color RED;
		static Color YELLOW;
		static Color PURPLE;
		static Color GREEN;
		static Color CYAN;
		static Color BLUE;
		
		unsigned char r, g, b, a;

		Color (const unsigned char r,
		       const unsigned char g,
		       const unsigned char b,
		       const unsigned char a);

		static Color FromFloat (const float r,
		                        const float g,
		                        const float b,
		                        const float a);
	};

}

#endif