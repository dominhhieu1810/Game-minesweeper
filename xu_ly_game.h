#ifndef SDL_XU_LY_GAME__H
#define SDL_XU_LY_GAME__H

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#include "SDL2_utils.h"
#include "khoi_tao_game.h"
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

bool kiemtrabom(domin a,int u1,int v1);

int dembomxungquanh(domin a,int u1,int v1);

void loang(domin &a,int u1, int v1,SDL_Renderer* Renderer);

bool checkmouseinside(domin a,int u,int v);

void run(domin &a,SDL_Event e,SDL_Renderer* Renderer);

#endif // SDL_XU_LY_GAME__H
