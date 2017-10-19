/* 
 * File:   Events.cpp
 * Author: Dezio
 * 
 * Created on 7 sierpień 2013, 11:19
 */

#include "Events.h"

Events::Events() {
    keystate=SDL_GetKeyState( 0 );
}

Events::Events(const Events& orig) {
}

Events::~Events() {
}
void Events::krotkie_dol(){
    while(SDL_PollEvent(&zdarzenie)){
            if( zdarzenie.type == SDL_QUIT )
            {
                dzialanie=wyjscie;
            }
            if(zdarzenie.type==SDL_KEYDOWN){
                switch( zdarzenie.key.keysym.sym )
                {
                case SDLK_ESCAPE:
                    dzialanie=wyjscie;
                    break;
                case SDLK_UP:
                    dzialanie=gora;
                    break;    
                case SDLK_DOWN:
                    dzialanie=dol;
                    break;
                case SDLK_LEFT:
                    dzialanie=lewo;
                    break;
                case SDLK_RIGHT:
                    dzialanie=prawo;
                    break;
                }
            }
        }
}
void Events::krotkie_gora(){
    while(SDL_PollEvent(&zdarzenie)){
            if(zdarzenie.type==SDL_KEYUP){
                switch( zdarzenie.key.keysym.sym )
                {
                case SDLK_ESCAPE:
                    dzialanie_g=wyjscie;
                    break;
                case SDLK_UP:
                    dzialanie_g=gora;
                    break;    
                case SDLK_DOWN:
                    dzialanie_g=dol;
                    break;
                case SDLK_LEFT:
                    dzialanie_g=lewo;
                    break;
                case SDLK_RIGHT:
                    dzialanie_g=prawo;
                    break;
                }
            }
        }
}
bool Events::dlugie(akcja gdzie){
    if(gdzie==gora){
        if(keystate[SDLK_UP])
            return true;
    }
    else if(gdzie==dol){
        if(keystate[SDLK_DOWN])
            return true;
    }
    else if(gdzie==lewo){
        if(keystate[SDLK_LEFT])
            return true;
    }
    else if(gdzie==prawo){
        if(keystate[SDLK_RIGHT])
            return true;
    }
    else return false;
}

