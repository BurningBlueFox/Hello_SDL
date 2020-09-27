#include "Display.h"
#if _DEBUG == 1
#define LOG_FORMAT(x, y) printf(x, y)
#define LOG(x) printf(x);
#else
#defihne LOG_FORMAT(x, y)
#define LOG(x)
#endif

bool Display::Init()
{
	bool success = true;

	//InitializeSDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		LOG_FORMAT("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		
		//Create Window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
								  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL)
		{
			LOG_FORMAT("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
		}
	}
	return success;
}

bool Display::LoadMedia()
{
	bool success = true;

	helloWorldBitmap = SDL_LoadBMP("Assets/Graphics/hello_world.bmp");
	if (helloWorldBitmap == NULL)
	{
		LOG_FORMAT("Unable to load image %s! SDL Error: %s\nAssets/Graphics/hello_world.bmp", SDL_GetError());
		success = false;
	}
	return success;
}

void Display::Close()
{
	SDL_FreeSurface(helloWorldBitmap);
	helloWorldBitmap = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}

void Display::Show()
{
	SDL_BlitSurface(helloWorldBitmap, NULL, screenSurface, NULL);

	SDL_UpdateWindowSurface(window);

	SDL_Delay(5000);
}
