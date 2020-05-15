#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#include "SDL2_utils.h"
#include "khoi_tao_game.h"
#include "xu_ly_game.h"
using namespace std;
bool kiemtrabom(domin a,int u1,int v1){
	if(a.mang1[u1][v1]==1)return false;
	else return true;
}
int dembomxungquanh(domin a,int u1,int v1){
	int dem=0;
	for(int i=u1-1;i<=u1+1;i++){
		for(int j=v1-1;j<=v1+1;j++){
			if(i<0 || i>=a.hang || j<0 ||j>=a.cot || (i==u1 && j==v1)){
				continue;
			}
			if(a.mang1[i][j]==1){
				dem=dem+1;
			}
		}
	}
	return dem;
}

void loang(domin &a,int u1, int v1,SDL_Renderer* Renderer ){
    if(a.mang3[u1][v1]==0){
	if(a.mang2[u1][v1]==0){
        a.mang2[u1][v1]=1;
        if(dembomxungquanh(a,u1,v1)!=0){
            string text = ""+std::to_string(dembomxungquanh(a,u1,v1));

            SDL_Rect fillRect = { (SCREEN_WIDTH-a.cot*30)/2+30*u1, (SCREEN_HEIGHT-a.hang*30)/2+30*v1, 30, 30 };
            SDL_SetRenderDrawColor( Renderer, 255, 132, 138, 1 );
            SDL_RenderFillRect( Renderer, &fillRect );
            drawtext(text,(SCREEN_WIDTH-a.cot*30)/2+30*u1+10,(SCREEN_HEIGHT-a.hang*30)/2+30*v1+10,14,Renderer);
        }
	    else{

		    SDL_Rect fillRect = { (SCREEN_WIDTH-a.cot*30)/2+30*u1, (SCREEN_HEIGHT-a.hang*30)/2+30*v1, 30, 30 };
            SDL_SetRenderDrawColor( Renderer, 255, 132, 138, 1 );
            SDL_RenderFillRect( Renderer, &fillRect );
			for(int i=u1-1;i<=u1+1;i++){
		        for(int j=v1-1;j<=v1+1;j++){
			        if(i<0 || i>=a.hang || j<0 ||j>=a.cot || (i==u1 && j==v1)){
				        continue;
			        }
					loang(a,i,j,Renderer);
		        }
	        }
	    }
    }
    }
}

bool checkmouseinside(domin a,int u,int v){
    bool inside = true;
		if( u<(SCREEN_WIDTH-a.cot*30)/2 )
		{
			inside = false;
		}

		else if( u > (SCREEN_WIDTH-a.cot*30)/2+a.cot*30 )
		{
			inside = false;
		}

		else if( v < (SCREEN_HEIGHT-a.hang*30)/2 )
		{
			inside = false;
		}

		else if( v > (SCREEN_HEIGHT-a.hang*30)/2+a.hang*30 )
		{
			inside = false;
		}
    return inside;
}

void run(domin &a,SDL_Event e,SDL_Renderer* Renderer){
    int u=0,v=0,u1,v1;
    int dem=0;int dembom=0;
    bool ketqua=false;
    if(e.type==SDL_MOUSEBUTTONDOWN){
        SDL_GetMouseState( &u, &v );
        if(checkmouseinside(a,u,v)==true){
            u1=(u-(SCREEN_WIDTH-a.cot*30)/2)/30;
            v1=(v-(SCREEN_HEIGHT-a.hang*30)/2)/30;

            if(e.button.button == SDL_BUTTON_LEFT){

                if(a.mang3[u1][v1]==0){
                if(kiemtrabom(a,u1,v1)==false){

                    for(int i=0;i<a.hang;i++){
                        for(int j=0;j<a.cot;j++){
                            if(a.mang1[i][j]==1){
                                SDL_Rect fillRect = { (SCREEN_WIDTH-a.cot*30)/2+30*i,(SCREEN_HEIGHT-a.hang*30)/2+30*j, 30, 30 };
                                SDL_SetRenderDrawColor( Renderer, 255, 132, 138, 1 );
                                SDL_RenderFillRect( Renderer, &fillRect );

                                drawtext("#",(SCREEN_WIDTH-a.cot*30)/2+30*i+10,(SCREEN_HEIGHT-a.hang*30)/2+30*j+10,14,Renderer);
                            }
                        }
                    }
                    drawtext("LOSE",330,0,60,Renderer);
                    SDL_RenderPresent( Renderer );
                    SDL_Delay(3000);
                    ketqua=true;
                }
                else{
                    loang(a,u1,v1,Renderer);
                    for(int i=0;i<a.hang;i++){
                        for(int j=0;j<a.cot;j++){

                            if(a.mang2[i][j]==1){
                                dem++;
                            }
                        }
                    }

                    if(dem==a.hang*a.cot-a.sobom){
                        drawtext("WIN",340,0,60,Renderer);
                        SDL_RenderPresent( Renderer );
                        SDL_Delay(3000);
                        ketqua=true;

                    }
                }
                if (ketqua==true){
                    e.type=SDL_MOUSEBUTTONUP;
                    delete a.mang1;delete a.mang2; delete a.mang3;
                    taogame(a,Renderer,SCREEN_WIDTH,SCREEN_HEIGHT);
                    run(a,e,Renderer);
                }
                }
            }
            else if(e.button.button == SDL_BUTTON_RIGHT){
                 if(e.button.clicks==1){
                    if(a.mang2[u1][v1]==0){
                    a.mang3[u1][v1]=1;

                    for(int i=0;i<a.hang;i++){
                        for(int j=0;j<a.cot;j++){
                            if(a.mang3[i][j]==1){
                                dembom++;
                            }
                        }
                    }
                    if(a.sobom-dembom>=0){
                        drawtext("?",(SCREEN_WIDTH-a.cot*30)/2+30*u1+10,(SCREEN_HEIGHT-a.hang*30)/2+30*v1+10,14,Renderer);
                        SDL_Rect fillRect4 = { 700, 0, 100, 30 };
                        SDL_SetRenderDrawColor( Renderer, 231, 255, 220, 1 );
                        SDL_RenderFillRect( Renderer, &fillRect4 );
                        string s="? = "+ to_string(a.sobom-dembom);
                        drawtext(s,730,7,14,Renderer);
                    }

                    }
                }
                else if(e.button.clicks==2){
                    if(a.mang3[u1][v1]==1){
                    a.mang3[u1][v1]=0;
                    if((u1+v1)%2==0){
                        SDL_Rect fillRect = { (SCREEN_WIDTH-a.cot*30)/2+30*u1,(SCREEN_HEIGHT-a.hang*30)/2+30*v1, 30, 30 };
                        SDL_SetRenderDrawColor( Renderer, 232, 189, 127, 1 );
				        SDL_RenderFillRect( Renderer, &fillRect );
                    }
                    else{
                        SDL_Rect fillRect = { (SCREEN_WIDTH-a.cot*30)/2+30*u1,(SCREEN_HEIGHT-a.hang*30)/2+30*v1, 30, 30 };
                        SDL_SetRenderDrawColor( Renderer, 255, 255, 255, 1 );
				        SDL_RenderFillRect( Renderer, &fillRect );
                    }
                    for(int i=0;i<a.hang;i++){
                        for(int j=0;j<a.cot;j++){
                            if(a.mang3[i][j]==1){
                                dembom++;
                            }
                        }
                    }
                    if(a.sobom-dembom>=0){
                        SDL_Rect fillRect = { 700, 0, 100, 30 };
                        SDL_SetRenderDrawColor( Renderer, 231, 255, 220, 1 );
                        SDL_RenderFillRect( Renderer, &fillRect );
                        string s="? = "+ to_string(a.sobom-dembom);
                        drawtext(s,730,7,14,Renderer);
                    }

                    }
                }
            }

        }
        else{
            if(u>0 && u<100 && v>0 && v<30){
                e.type=SDL_MOUSEBUTTONUP;
                a.hang=8;a.cot=8;a.sobom=10;
                delete a.mang1;delete a.mang2; delete a.mang3;
                taogame(a,Renderer,SCREEN_WIDTH,SCREEN_HEIGHT);
                run(a,e,Renderer);
            }
            if(u>0 && u<100 && v>30 && v<60){
                e.type=SDL_MOUSEBUTTONUP;
                a.hang=14;a.cot=14;a.sobom=30;
                delete a.mang1;delete a.mang2; delete a.mang3;
                taogame(a,Renderer,SCREEN_WIDTH,SCREEN_HEIGHT);
                run(a,e,Renderer);
            }
            if(u>0 && u<100 && v>60 && v<90){
                e.type=SDL_MOUSEBUTTONUP;
                a.hang=20;a.cot=20;a.sobom=70;
                delete a.mang1;delete a.mang2; delete a.mang3;
                taogame(a,Renderer,SCREEN_WIDTH,SCREEN_HEIGHT);
                run(a,e,Renderer);
            }
        }

    }
}
