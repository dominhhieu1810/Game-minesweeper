#include <iostream>
#include "SDL2_utils.h"
using namespace std;
bool init(SDL_Window* &Window,SDL_Renderer* &Renderer,int SCREEN_WIDTH,int SCREEN_HEIGHT,const string &WINDOW_TITLE)
{
	bool success = true;
	if( SDL_Init( SDL_INIT_VIDEO ) != 0 )
	{
		cout<< "SDL could not initialize! SDL Error: "<< SDL_GetError() ;
		success = false;
	}
	else
	{
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			cout<<"Warning: Linear texture filtering not enabled!" ;
		}
		Window = SDL_CreateWindow( WINDOW_TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( Window == NULL )
		{
			cout<<"Window could not be created! SDL Error: "<< SDL_GetError() ;
			success = false;
		}
		else
		{
			Renderer = SDL_CreateRenderer( Window, -1, SDL_RENDERER_ACCELERATED );
			if( Renderer == NULL )
			{
				cout<<"Renderer could not be created! SDL Error: "<< SDL_GetError() ;
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor( Renderer, 0, 0, 0, 1 );

			}
		}
	}

	return success;
}
bool loadMedia()
{
	bool success = true;
	return success;
}
void close(SDL_Window* Window,SDL_Renderer* Renderer)
{
	SDL_DestroyRenderer( Renderer );
	SDL_DestroyWindow( Window );
	Window = NULL;
	Renderer = NULL;

	SDL_Quit();
}
