#include "engine_window.h"

#include <iostream>
#include <string>


#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"


SDL_Renderer* Engine::renderer = nullptr;

void Engine::Start(){
    _closed = !init();
    while (true){
        this->clear();
    }
}

Engine::~Engine() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(_window);
	TTF_Quit();
	SDL_Quit();
}

bool Engine::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Error in SDL_Init: " << SDL_GetError() << std::endl;
		return false;
	}
	if (TTF_Init() != 0) {
		std::cerr << "Error in TTF_Init: " << SDL_GetError() << std::endl;
		return false;
	}

	_window = SDL_CreateWindow(appName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, appWidth, appHeight, 0);

	if (_window == nullptr) {
		std::cerr << "Error creating window: " << SDL_GetError() << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) {
		std::cerr << "Error creating renderer: " << SDL_GetError() << std::endl;
	}

	return true;
}

Engine::Engine(const std::string &title, int width, int height):
	appName(title),appWidth(width),appHeight(height) {
	
}

void Engine::pollEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT: {
				_closed = true;
				break;
			}
			case SDL_KEYDOWN: {
				switch (event.key.keysym.sym) {
				case SDLK_SPACE: {
					_key_value = 1;
					break;
				}
				default: {
					break;
				}
				}
				break;
			}
			default: {
				_key_value = -1;
				break;
			}
		}
	}
}

void Engine::clear() const {
	SDL_RenderPresent(renderer); // Lo actualiza en la pantalla
	SDL_SetRenderDrawColor(renderer, 10, 10, 100, 255); // Setea el color default de pantalla limpia para el render
	SDL_RenderClear(renderer); // Limpia el render
	
	
	
}