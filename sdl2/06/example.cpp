	
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

using namespace std;

bool init();
void kill();
bool loop();

// Pointers to our window, renderer, texture, music, and sound
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* texture;
Mix_Music* music;
Mix_Chunk* sound;

int main(int argc, char** args) {

	if ( !init() ) {
		system("pause");
		return 1;
	}

	while ( loop() ) {
		// wait before processing the next frame
		SDL_Delay(10); 
	}

	kill();
	return 0;
}

bool loop() {

	static const unsigned char* keys = SDL_GetKeyboardState( NULL );

	SDL_Event e;
	SDL_Rect dest;

	// Clear the window to white
	SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
	SDL_RenderClear( renderer );

	// Event loop
	while ( SDL_PollEvent( &e ) != 0 ) {
		switch (e.type) {
			case SDL_QUIT:
				return false;
			case SDL_KEYDOWN:
				if ( e.key.keysym.sym == SDLK_SPACE ) {
					if ( Mix_PausedMusic() == 1 ) {
						Mix_ResumeMusic();
					} else {
						Mix_PauseMusic();
					}
				} else if ( e.key.keysym.sym == SDLK_ESCAPE ) {
					Mix_HaltMusic();
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				// Play sound once on any available channel
				Mix_PlayChannel( -1, sound, 1 );
				break;
		}
	}

	// Render texture
	SDL_RenderCopy(renderer, texture, NULL, NULL);

	// Update window
	SDL_RenderPresent( renderer );

	return true;
}

bool init() {
	if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
		cout << "Error initializing SDL: " << SDL_GetError() << endl;
		return false;
	} 

	// Initialize SDL_image with PNG loading subsystem
	if ( IMG_Init(IMG_INIT_PNG) < 0 ) {
		cout << "Error initializing SDL_image: " << IMG_GetError() << endl;
		system("pause");
		return false;
	}

	// Initialize SDL_mixer with our audio format
	if ( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 1024 ) < 0 ) {
		cout << "Error initializing SDL_mixer: " << Mix_GetError() << endl;
		return false;
	}

	window = SDL_CreateWindow( "Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN );
	if ( !window ) {
		cout << "Error creating window: " << SDL_GetError()  << endl;
		return false;
	}

	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	if ( !renderer ) {
		cout << "Error creating renderer: " << SDL_GetError() << endl;
		return false;
	}

	// Load image (PNG) into surface
	SDL_Surface* buffer = IMG_Load("test.png");
	if ( !buffer ) {
		cout << "Error loading image test.png: " << SDL_GetError() << endl;
		return false;
	}

	// Create texture
	texture = SDL_CreateTextureFromSurface( renderer, buffer );
	// Free surface as it's no longer needed
	SDL_FreeSurface( buffer );
	buffer = NULL;
	if ( !texture ) {
		cout << "Error creating texture: " << SDL_GetError() << endl;
		return false;
	}

	// Load music
	music = Mix_LoadMUS("music.wav");
	if ( !music ) {
		cout << "Error loading music: " << Mix_GetError() << endl;
		return false;
	}

	// Load sound
	sound = Mix_LoadWAV("scratch.wav");
	if ( !sound ) {
		cout << "Error loading sound: " << Mix_GetError() << endl;
		return false;
	}

	// Play music forever
	Mix_PlayMusic( music, -1 );

	return true;
}

void kill() {
	SDL_DestroyTexture( texture );
	Mix_FreeMusic( music );
	Mix_FreeChunk( sound );
	texture = NULL;
	music = NULL;
	sound = NULL;

	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	window = NULL;
	renderer = NULL;

	SDL_Quit();
	IMG_Quit();
	Mix_Quit();
}