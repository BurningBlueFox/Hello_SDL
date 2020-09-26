#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


bool Init();
bool LoadMedia();
void Close();

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* helloWorldBitmap = NULL;

bool Init()
{
	bool success = true;

	//InitializeSDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create Window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
								  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
		}
	}
	return success;
}

bool LoadMedia()
{
	bool success = true;

	helloWorldBitmap = SDL_LoadBMP("Assets/Graphics/hello_world.bmp");
	if (helloWorldBitmap == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "Assets/Graphics/hello_world.bmp", SDL_GetError());
		success = false;
	}
	return success;
}

void Close()
{
	SDL_FreeSurface(helloWorldBitmap);
	helloWorldBitmap = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}

int main(int argc, char* args[])
{

	if (!Init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if (!LoadMedia())
		{
			printf("Failed to load media\n");
		}
		else
		{
			SDL_BlitSurface(helloWorldBitmap, NULL, screenSurface, NULL);

			SDL_UpdateWindowSurface(window);

			SDL_Delay(5000);
		}
	}
	
	Close();

	return 0;
}