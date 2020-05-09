#include <iostream>
#include <ctime>

#include "SDL2_utils.h"
#include "khoi_tao_game.h"
using namespace std;

void taogame(domin &a,SDL_Renderer* &Renderer,int SCREEN_WIDTH,int SCREEN_HEIGHT){

	a.mang1=new int*[a.hang];
	a.mang2=new int*[a.hang];
	a.mang3=new int*[a.hang];
	for(int i=0;i<a.hang;i++){
	    a.mang1[i]=new int[a.cot];
	    a.mang2[i]=new int[a.cot];
	    a.mang3[i]=new int[a.cot];
    }
    for(int i=0;i<a.hang;i++){
        for(int j=0;j<a.cot;j++){
            a.mang1[i][j]=0;
            a.mang2[i][j]=0;
            a.mang3[i][j]=0;
        }
    }

    SDL_SetRenderDrawColor( Renderer, 0, 0, 0, 1 );
    SDL_RenderClear( Renderer );

    for(int i=0;i<a.hang;i++){
        for(int j=0;j<a.cot;j++){
            if((i+j)%2==0){
                SDL_Rect fillRect = { (SCREEN_WIDTH-a.cot*30)/2+30*i,(SCREEN_HEIGHT-a.hang*30)/2+30*j, 30, 30 };
                SDL_SetRenderDrawColor( Renderer, 232, 189, 127, 1 );
                SDL_RenderFillRect( Renderer, &fillRect );
            }
            else{
                SDL_Rect fillRect = { (SCREEN_WIDTH-a.cot*30)/2+30*i,(SCREEN_HEIGHT-a.hang*30)/2+30*j, 30, 30 };
                SDL_SetRenderDrawColor( Renderer, 255, 255, 255, 1 );
                SDL_RenderFillRect( Renderer, &fillRect );
                }
        }
    }
    srand(time(NULL));
	for(int i=0;i<a.sobom;i++){
		int x= rand()% (a.hang-1) +0;
		int y= rand()% (a.cot-1) +0;
		if(a.mang1[x][y]!=1){
			a.mang1[x][y]=1;
		}
		else{
			i--;
		}
	}
    SDL_Rect fillRect1 = { 0, 0, 100, 30 };
    SDL_SetRenderDrawColor( Renderer, 54, 249, 68, 1 );
    SDL_RenderFillRect( Renderer, &fillRect1 );
    drawtext("beginner",20,7,12,Renderer);

    SDL_Rect fillRect2 = { 0, 30, 100, 30 };
    SDL_SetRenderDrawColor( Renderer, 255, 255, 0, 1 );
    SDL_RenderFillRect( Renderer, &fillRect2 );
    drawtext("intermediate",5,37,12,Renderer);

    SDL_Rect fillRect3 = { 0, 60, 100, 30 };
    SDL_SetRenderDrawColor( Renderer, 255, 0, 0, 1 );
    SDL_RenderFillRect( Renderer, &fillRect3 );
    drawtext("expert",30,67,12,Renderer);


    SDL_Rect fillRect4 = { 700, 0, 100, 30 };
    SDL_SetRenderDrawColor( Renderer, 231, 255, 220, 1 );
    SDL_RenderFillRect( Renderer, &fillRect4 );
    string s="? = "+ to_string(a.sobom);
    drawtext(s,730,7,14,Renderer);

}

void drawtext(string s,int x,int y,int sizetext,SDL_Renderer* Renderer){
    TTF_Init() ;
    TTF_Font* font = NULL;

    SDL_Surface* surface = NULL;

    SDL_Texture* texture = NULL;
// TỪ DÒNG 86 ĐẾN 109 CÓ THAM KHẢO CODE TẠI https://www.stdio.vn/articles/draw-text-trong-sdl-308.
    font = TTF_OpenFont("VeraMoBd.ttf", sizetext );

    SDL_Color color = { 0 ,128, 128 };
    SDL_Rect srcRest;
    SDL_Rect desRect;

    string text = s;
    surface = TTF_RenderText_Solid(font, text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(Renderer, surface);
    SDL_FreeSurface(surface);

    TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h);

    srcRest.x = 0;
    srcRest.y = 0;

    desRect.x = x;
    desRect.y = y;

    desRect.w = srcRest.w;
    desRect.h = srcRest.h;

    SDL_RenderCopy(Renderer, texture, &srcRest, &desRect);
//
    TTF_CloseFont( font );
    font=NULL;
    SDL_DestroyTexture(texture);
    texture=NULL;
    TTF_Quit();
}
