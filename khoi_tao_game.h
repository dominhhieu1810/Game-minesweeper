#ifndef SDL_KHOI_TAO_GAME__H
#define SDL_KHOI_TAO_GAME__H

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <ctime>

#include "SDL2_utils.h"
using namespace std;
struct domin
{
    int hang,cot,sobom;
    int **mang1; int **mang2;int**mang3;
};
void taogame(domin &a,SDL_Renderer* &Renderer,int SCREEN_WIDTH,int SCREEN_HEIGHT);

void drawtext(string s,int x,int y,int sizetext,SDL_Renderer* Renderer);

#endif // SDL_KHOI_TAO_GAME__H
