/* 
 * File:   Graphics.cpp
 * Author: Dezio
 * 
 * Created on 7 sierpień 2013, 12:02
 */

#include "Graphics.h"

Graphics::Graphics() {
    //blad=brak;
    SDL_Init( SDL_INIT_AUDIO | SDL_INIT_VIDEO );
    screen = SDL_SetVideoMode( 800, 600, 32, SDL_SWSURFACE );
    if (!screen)
    {
       // blad=init_screen;
    }
}

Graphics::Graphics(const Graphics& orig) {
}

Graphics::~Graphics() {
}
void Graphics::odswiez(){
    SDL_Flip( screen );
}
void Graphics::zakoncz(){
    SDL_Quit();
}
void Graphics::dodaj_sprite(SDL_Surface* obraz){
    SDL_BlitSurface(screen,0,obraz,0);
}
void Graphics::test(){
    SDL_Rect r = {0,0,320,240};
    SDL_FillRect(screen,&r, SDL_MapRGB(screen->format, 200,200,0) );
    
}
