#pragma once
#include <stdio.h>
#include "Lib/SDL2-2.0.12/include/SDL.h"

class Display
{
private:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

private:
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Surface* helloWorldBitmap = NULL;

public:
	bool Init();
	bool LoadMedia();
	void Close();
	void Show();
};

