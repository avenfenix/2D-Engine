#pragma once

#include <string>
#include <inttypes.h>
#include <vector>

#include "SDL.h"
#include "SDL_ttf.h"

using namespace std;

class Sprite {
public:
	Sprite();
	Sprite(uint32_t width, uint32_t height);
	~Sprite();
	uint32_t width;
	uint32_t height;
public:
	std::vector<SDL_Color> data;
public:
	SDL_Color getPixel(uint32_t x, uint32_t y);
	bool SetPixel(uint32_t x, uint32_t y, SDL_Color color);
private:
	SDL_Color COLOR_NULO = { 0,0,0,0 };
};

class Engine {
public:
	Engine();
	~Engine();

public:
	void Setting(const std::string& title, int width, int height);
	void Start();
	virtual void appUpdate() = 0;
	virtual void appCreate() = 0;

public:
	void clear() const;
	void pollEvents();
	inline bool isClosed() const { return _closed; }
	inline int getKeyValue() const { return _key_value; }

public:
	void DrawSprite(uint32_t x, uint32_t y, Sprite *sprite);
	void Draw(uint32_t x, uint32_t y, SDL_Color color);

public: // Texto
	TTF_Font* font;
	bool loadFont(const std::string& font_path, int size);
	void DrawString(uint32_t x, uint32_t y, const std::string& text, SDL_Color color);
public: // Atributos de la ventana
	std::string appName;
	uint32_t appWidth;
	uint32_t appHeight;

private:
	bool init();

private:
	int _key_value;

	SDL_Window* _window = nullptr;

	bool _closed;
public:
	static SDL_Renderer* renderer;
};




