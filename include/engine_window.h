#pragma once

#include <string>

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

class Engine {	
public:
	Engine(const std::string& title, int width, int height);
	~Engine();

public:
    void Start();

public:
	void clear() const;
	void pollEvents();
	inline bool isClosed() const { return _closed; }
	inline int getKeyValue() const { return _key_value; }
	
public: // Atributos de la ventana
    std::string appName;
    int appWidth;
	int appHeight;

private:
	bool init();

private:
	int _key_value;

	SDL_Window* _window = nullptr;
	
	bool _closed;
public:
	static SDL_Renderer* renderer;
};