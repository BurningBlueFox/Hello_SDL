#include "Display.h"



int main(int argc, char* args[])
{
	Display* display = new Display();
	if (!display->Init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if (!display->LoadMedia())
		{
			printf("Failed to load media\n");
		}
		else
		{
			display->Show();
		}
	}
	
	display->Close();

	return 0;
}