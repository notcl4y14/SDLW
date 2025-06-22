#include <SDL-Wrap/Color.hpp>

namespace SDLW {

	Color Color::BLACK  = Color(0,   0,   0,   255);
	Color Color::WHITE  = Color(255, 255, 255, 255);
	Color Color::RED    = Color(255, 0,   0,   255);
	Color Color::YELLOW = Color(255, 255, 0,   255);
	Color Color::PURPLE = Color(255, 0,   255, 255);
	Color Color::GREEN  = Color(0,   255, 0,   255);
	Color Color::CYAN   = Color(0,   255, 255, 255);
	Color Color::BLUE   = Color(0,   0,   255, 255);

	Color::Color (const unsigned char r,
	              const unsigned char g,
	              const unsigned char b,
	              const unsigned char a) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	Color Color::FromFloat (const float r,
	                  const float g,
	                  const float b,
	                  const float a) {
		return Color(
			(unsigned char)(255 * r),
			(unsigned char)(255 * g),
			(unsigned char)(255 * b),
			(unsigned char)(255 * a)
		);
	}

}