
#include <iostream>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>

using namespace std;

const int sprite_width = 128;
const int sprite_height = 128;
const float sprite_fps = 24.0f;

bool init();
void kill();
void loop();

struct spritesheet {
	SDL_Texture* texture;
	vector<SDL_Rect> sprites;
	Uint32 lastFrame, lastUpdate;
};

SDL_Window* window;
SDL_Renderer* renderer;
spritesheet ss;

int main(int argc, char** args) {
	if (!init()) {
		system("pause");
		return 1;
	}

	loop();

	kill();
	return 0;
}

void loop() {
	bool running = true;
	while (running) {

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		SDL_Event ev;
		while (SDL_PollEvent(&ev) != 0) {
			if (ev.type == SDL_QUIT) {
				running = false;
			}
		}

		Uint32 current = SDL_GetTicks();
		float dT = (current - ss.lastUpdate) / 1000.0f;

		int framesToUpdate = floor(dT / (1.0f / sprite_fps));
		if (framesToUpdate > 0) {
			ss.lastFrame += framesToUpdate;
			ss.lastFrame %= ss.sprites.size();
			ss.lastUpdate = current;
		}

		SDL_RenderCopy(renderer, ss.texture, &ss.sprites[ss.lastFrame], NULL);

		SDL_RenderPresent(renderer);
	}
}

bool init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Error initializing SDL: " << SDL_GetError() << endl;
		return false;
	}

	if (IMG_Init(IMG_INIT_JPG) < 0) {
		cout << "Error initializing SDL_image: " << IMG_GetError() << endl;
		return false;
	}

	window = SDL_CreateWindow("Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 512, 512, SDL_WINDOW_SHOWN);
	if (!window) {
		cout << "Error creating window: " << SDL_GetError() << endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		cout << "Error creating renderer: " << SDL_GetError() << endl;
		return false;
	}

	SDL_Surface* buffer = IMG_Load("sprites.png");
	if (!buffer) {
		cout << "Error loading image sprites.png: " << SDL_GetError() << endl;
		return false;
	}

	ss.lastFrame = 0;
	ss.lastUpdate = SDL_GetTicks();
	ss.texture = SDL_CreateTextureFromSurface(renderer, buffer);
	SDL_FreeSurface(buffer);
	buffer = NULL;
	if (!ss.texture) {
		cout << "Error creating texture: " << SDL_GetError() << endl;
		return false;
	}

	for (int j = 0; j < 16; j++) {
		for (int i = 0; i < 16; i++) {
			SDL_Rect r = { i * sprite_width, j * sprite_height, sprite_width, sprite_height };
			ss.sprites.push_back(r);
		}
	}

	return true;
}

void kill() {
	SDL_DestroyTexture(ss.texture);
	ss.texture = NULL;
	ss.sprites.clear();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	IMG_Quit();
	SDL_Quit();
}