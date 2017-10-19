/* 
 * File:   Sprite.cpp
 * Author: Dezio
 * 
 * Created on 7 sierpień 2013, 12:19
 */

#include "Sprite.h"

Sprite::Sprite(const char * plik) {

    obraz_raw=IMG_Load(plik);
    if(obraz_raw==NULL) cout<<"Nie znaleziono pliku: "<<plik<<endl;
    obraz=SDL_DisplayFormat(obraz_raw);
    Uint32 colorkey = SDL_MapRGB( obraz->format, 0xFF, 0x00, 0xFF );
    SDL_SetColorKey( obraz, SDL_SRCCOLORKEY, colorkey );
    SDL_FreeSurface(obraz_raw);
    src.x = 0;
    src.y = 0;
    src.w = obraz->w;
    src.h = obraz->h;
    dst.x = 0;
    dst.y = 0;
}
Sprite::Sprite(const Sprite& orig) {
}

Sprite::~Sprite() {
}
void Sprite::uwolnij(){
    SDL_FreeSurface(obraz);
}
SDL_Rect  Sprite::dane_src(int x,int y){
    src.x=x;
    src.y=y;
    return  src;
}
SDL_Rect  Sprite::dane_src(int x,int y,int w, int h){
    src.x=x;
    src.y=y;
    src.w=w;
    src.h=h;
    return  src;
}
SDL_Rect  Sprite::dane_dst(int x, int y){
    dst.x=x;
    dst.y=y;
    return  dst;
}