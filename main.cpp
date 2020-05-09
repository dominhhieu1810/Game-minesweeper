#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <SDL_ttf.h>
#include <ctime>

#include "SDL2_utils.h"
#include "khoi_tao_game.h"
#include "xu_ly_game.h"
using namespace std;

const string WINDOW_TITLE="GAME DO MIN";

SDL_Window* Window = NULL;

SDL_Renderer* Renderer = NULL;

int main( int argc, char* args[] )
{

	if( !init(Window,Renderer,SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE) )
	{
		cout<<"Failed to initialize!" ;
	}
	else
	{
		if( !loadMedia() )
		{
			cout<<"Failed to load media!" ;
		}
		else
		{
			bool quit = false;

			SDL_Event e;
			TTF_Init();
			domin a;
			a.hang=8;a.cot=8;a.sobom=10;
            taogame(a,Renderer,SCREEN_WIDTH,SCREEN_HEIGHT);
			while( !quit )
			{

				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}
				run(a,e,Renderer);
                SDL_RenderPresent( Renderer );
			}

		}
	}

	close(Window,Renderer);

	return 0;
}
