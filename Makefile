SOURCE_FILES=main.cpp src/engine_window.cpp
SDL_FLAGS=-lSDL2 -lSDL2_ttf

all: linux

linux:
	g++ -Iinclude $(SOURCE_FILES) -o main $(SDL_FLAGS)

clear:
	rm main