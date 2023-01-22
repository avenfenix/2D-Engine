#include "Engine.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


class Test : public Engine {
	void appUpdate() override;
	void appCreate() override;


	void drawNoiseOrder();
	void drawRegisters();

	SDL_Color COLOR_WHITE = { 255,255,255,255 };
	SDL_Color COLOR_BLACK = { 0,0,0,255 };
	Sprite sprite = Sprite(256,240);
	uint32_t cycle = 0;
	uint32_t scanline = 0;
	bool draw = true;
	bool frame_complete = false;
};

void Test::drawNoiseOrder() {
	sprite.SetPixel(cycle - 1, scanline, (rand() % 2 ? COLOR_WHITE : COLOR_BLACK));
	cycle++;
	if (cycle >= 341) {
		cycle = 0;
		scanline++;
		if (scanline >= 261) {
			scanline = -1;
			frame_complete = true;
		}
	}
	
}

void Test::drawRegisters() {
	
}


void Test::appUpdate() {
	if (draw){
	do { drawNoiseOrder(); } while (!frame_complete);
	frame_complete = false;
	DrawSprite(25, 25, &sprite, 3);
	DrawSprite(300, 300, &sprite, 2);
	cycle = 0;
	scanline = 0;
	}
	
	if (getKeyPressed() == KEYS.SPACE) draw = !draw;
}

void Test::appCreate() {
	loadFont("C:\\Users\\juanp\\source\\repos\\2D-Engine-VS\\x64\\Debug\\fonts\\retro.ttf", 10);
}


int main(int argc, char* argv[]) {
	
	Test test;
	test.Setting("demo", 800,600);
	test.Start();

	return 0;
}