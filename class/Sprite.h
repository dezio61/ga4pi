/* 
 * File:   Sprite.h
 * Author: Dezio
 *
 * Created on 7 sierpień 2013, 12:19
 */

#ifndef SPRITE_H
#define	SPRITE_H
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<iostream>
using namespace std;
class Sprite {
public:
    Sprite(const char * plik);
    Sprite(const Sprite& orig);
    virtual ~Sprite();
    SDL_Surface * obraz;
    SDL_Surface * obraz_raw;
    SDL_Rect src;
    SDL_Rect dst;
    void uwolnij();
    SDL_Rect  dane_src(int x,int y);
    SDL_Rect  dane_src(int x,int y,int w, int h);
    SDL_Rect  dane_dst(int x,int y);
    int klw;
    int klh;
private:

};

#endif	/* SPRITE_H */

