#include "Engine.h"
#include <iostream>
#include <stdlib.h>

using namespace std;




class Test : public Engine {
	void appUpdate() override;
	void appCreate() override;

	// Lineas

	void drawLineX(int x, int y, int largo);
	void drawLineY(int x, int y, int largo);

	void drawNoiseOrder();
	void drawRegisters();

	SDL_Color COLOR_WHITE = { 255,255,255,255 };
	SDL_Color COLOR_BLACK = { 0,0,0,255 };
	SDL_Rect rectangulo;
	Sprite sprite = Sprite(800, 600);
	Sprite box = Sprite(50, 50);
	uint32_t cycle = 0;
	uint32_t scanline = 0;
	bool draw = false;
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

void Test::drawLineX(int x, int y, int largo) {
	for (int i = 0; i < largo; i++) {
		sprite.SetPixel(x + i, y, COLOR_WHITE);
	}
}

void Test::drawLineY(int x, int y, int largo) {
	for (int i = 0; i < largo; i++) {
		sprite.SetPixel(x, y + i, COLOR_WHITE);
	}

}
void Test::drawRegisters() {

}


void Test::appUpdate() {
	if (draw) {
		do { drawNoiseOrder(); } while (!frame_complete);
		frame_complete = false;
		//DrawSprite(300, 300, &sprite, 2);
		cycle = 0;
		scanline = 0;
	}
	for (int j = 0; j < (600/50); j++) {
		drawLineX(0, j * 50, 800);
	}
	for (int i = 0; i < 800/50; i++) {
		drawLineY(i*50, 0, 800);
	}
	//drawLineX(0, 300, 800);
	//drawLineX(0, 350, 800);
	//drawLineY(400, 0, 800);
	DrawSprite(0, 0, &sprite);

	
	//DrawSprite(0, 0, &box);
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	//SDL_RenderDrawRect(renderer, &rectangulo);
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	SDL_RenderFillRect(renderer, &rectangulo);
	SDL_RenderPresent(renderer);



	if (getKeyPressed() == KEYS.SPACE) draw = !draw;


	if (getKeyPressed() == KEYS.A) {
		rectangulo.x -= rectangulo.w;
	}
	if (getKeyPressed() == KEYS.D) {
		rectangulo.x += rectangulo.w;
	}
	if (getKeyPressed() == KEYS.S) {
		rectangulo.y += rectangulo.h;
	}
	if (getKeyPressed() == KEYS.W) {
		rectangulo.y -= rectangulo.h;
	}
}

void Test::appCreate() {
	rectangulo.h = 50;
	rectangulo.w = 50;
	rectangulo.x = 600/2 + rectangulo.h;// -(rectangulo.w / 2);
	rectangulo.y = 800/2 - (2 * rectangulo.h);//(rectangulo.h / 2);
	

	loadFont("C:\\Users\\juanp\\source\\repos\\2D-Engine-VS\\x64\\Debug\\fonts\\retro.ttf", 10);
}


int main(int argc, char* argv[]) {

	Test test;
	test.Setting("demo", 800, 600);
	test.Start();

	return 0;
}
