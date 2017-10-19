/* 
 * File:   Animation.cpp
 * Author: Dezio
 * 
 * Created on 26 sierpień 2013, 12:29
 */

#include "Animation.h"

Animation::Animation(Sprite * postac_t) {
    postac=postac_t;
    x=0;
    for(int a=0;a<13;a++){
        porcje[a].x=40*a;
        porcje[a].y=0;
        porcje[a].w=40;
        porcje[a].h=80;
    }
    postac->dst.w=40;
    postac->dst.h=80;
}

Animation::Animation(const Animation& orig) {
}

Animation::~Animation() {
}
SDL_Rect Animation::akcja(Ruch ruch){
    x++;
    if(x==3) x=0;
    if(ruch==iddle){
        return porcje[x];
    }
    if(ruch==lewo_r){
        return porcje[x+3];
    }
    if(ruch==prawo_r){
        return porcje[x+7];
    }
    if(ruch==skok_r){
        return porcje[11];
    }
    if(ruch==kuc){
        return porcje[12];
    }
}
