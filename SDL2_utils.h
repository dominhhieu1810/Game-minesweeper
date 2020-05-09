#ifndef SDL_UTILS__H
#define SDL_UTILS__H

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
using namespace std;

bool init(SDL_Window* &Window,SDL_Renderer* &Renderer,int SCREEN_WIDTH,int SCREEN_HEIGHT,const string &WINDOW_TITLE);

bool loadMedia();

void close(SDL_Window* Window,SDL_Renderer* Renderer);

#endif // SDL_UTILS__H
