#include <SDL-Wrap/SDL.hpp>

#include <SDL3/SDL.h>

#include <iostream>

class Crosshair {
	public:
	int x, y;

	void Update (int x, int y) {
		this->x = x;
		this->y = y;
	}

	void Render (SDLW::Render* render) {
		render->SetDrawColor(SDLW::Color::WHITE);
		render->DrawRectFixed(x - 10, y - 10, x + 10, y + 10);
		render->DrawLine(x - 15, y, x + 15, y);
		render->DrawLine(x, y - 15, x, y + 15);
	}
};

SDLW::Window window;
SDLW::Render render;

int main () {
	SDLW::Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	// SDLW::Window window = SDLW::Window("SDL-Wrap game", 800, 600);
	// SDLW::Render render = SDLW::Render(&window);
	window.Create("SDL-Wrap game", 800, 600);
	render.Create(&window);

	bool is_running = true;
	bool input_move_up = false;
	bool input_move_down = false;
	bool input_move_left = false;
	bool input_move_right = false;
	bool input_mouse_down = false;
	int mouse_x = 0;
	int mouse_y = 0;
	int player_x = 0;
	int player_y = 0;

	player_x = (800 / 2) - (25 / 2);
	player_y = (600 / 2) - (25 / 2);

	char pixels[8 * 8 * 4];

	for (int i = 0; i < 64; i++) {
		pixels[i * 4] = 255;
		pixels[i * 4 + 1] = (float) i / 64 * 255;
		pixels[i * 4 + 2] = (float) i / 32 * 255;
		pixels[i * 4 + 3] = (float) i / 16 * 255;
	}

	SDLW::Surface surface = SDLW::Surface(8, 8, SDL_PIXELFORMAT_RGBA8888, pixels, 8 * 4);
	SDLW::Texture texture = SDLW::Texture(&render, &surface);
	texture.SetBlendMode(SDL_BLENDMODE_BLEND);
	texture.SetScaleMode(SDL_SCALEMODE_NEAREST);

	Crosshair crosshair;

	while (is_running) {
		SDLW::Event e;
		SDLW::Keycode key;

		while (SDLW::PollEvent(&e)) {
			switch (e.type) {
			case SDL_EVENT_QUIT:
				is_running = false;
				break;
			
			case SDL_EVENT_KEY_DOWN:
				key = e.key.key;
				
				     if (key == SDLK_W) input_move_up = true;
				else if (key == SDLK_S) input_move_down = true;
				else if (key == SDLK_A) input_move_left = true;
				else if (key == SDLK_D) input_move_right = true;

				break;
			
			case SDL_EVENT_KEY_UP:
				key = e.key.key;
				
				     if (key == SDLK_W) input_move_up = false;
				else if (key == SDLK_S) input_move_down = false;
				else if (key == SDLK_A) input_move_left = false;
				else if (key == SDLK_D) input_move_right = false;
				
				break;
			
			case SDL_EVENT_MOUSE_MOTION:
				mouse_x = e.motion.x;
				mouse_y = e.motion.y;
				break;
			
			case SDL_EVENT_MOUSE_BUTTON_DOWN:
				input_mouse_down = true;
				window.SetRelativeMouseMode(true);
				window.SetMouseRect(800 / 2, 600 / 2, 1, 1);
				break;
			
			case SDL_EVENT_MOUSE_BUTTON_UP:
				input_mouse_down = false;
				window.SetRelativeMouseMode(false);
				window.SetMouseRect(0, 0, 0, 0);
				break;
			}
		}

		crosshair.Update(mouse_x, mouse_y);

		     if (input_move_up) player_y -= 2;
		else if (input_move_down) player_y += 2;
		     if (input_move_left) player_x -= 2;
		else if (input_move_right) player_x += 2;

		     if (player_x < -25) player_x = 800 + 25;
		else if (player_x >= 800 + 25) player_x = -25;
		     if (player_y < -25) player_y = 600 + 25;
		else if (player_y >= 600 + 25) player_y = -25;

		render.SetDrawColor(SDLW::Color(0, 128, 255, 255));
		render.Clear();

		render.SetDrawColor(SDLW::Color(0, 0, 0, 255));
		render.FillRectFixed(player_x - 2, player_y - 2, player_x + 25 + 2, player_y + 25 + 2);

		render.SetDrawColor(SDLW::Color(255, 255, 255, 255));
		render.FillRect(player_x, player_y, 25, 25);

		SDLW::FRect dstrect = { 10, 10, 50, 50 };
		render.DrawTexture(&texture, &dstrect);

		crosshair.Render(&render);

		render.Present();

		SDLW::Delay(1000 / 60);
	}

	SDLW::Quit();
	return 0;
}