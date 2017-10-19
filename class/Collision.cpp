/* 
 * File:   Collision.cpp
 * Author: Dezio
 * 
 * Created on 8 sierpień 2013, 12:14
 */

#include "Collision.h"
#include "Sprite.h"

Collision::Collision(int w, int h,SDL_Rect * dst_,SDL_Rect * src_) {
    szer=w;
    wys=h;
    dst=dst_;
    src=src_;
}

Collision::Collision(const Collision& orig) {
}

Collision::~Collision() {
}
bool Collision::sCol(){
    //cout<<"x: "<<dst->x<<"\ny:"<<dst->y<<"\n"<<flush;
    /*if(dst->x<=0){
        return true;
    }
    if(dst->y<=0){
        return true;
    }*/
    if(dst->y>=wys-src->h){
        return true;
    }
    if(dst->x>=szer-src->w){
        return true;
    }
    return false;
}/*
bool Collision::eCol(akcja kierunek,SDL_Rect  edst,SDL_Rect  esrc){
    /*int ax=dstx;
    int ay=dst.y;
    int aw=src.w;
    int ah=src.h;
    int bx=edst.x;
    int by=edst.y;
    int bw=esrc.w;
    int bh=esrc.h;
    
    
    if(kierunek==prawo){   //obiekt ruchomy przykleja się do obiektu stałego
        if(ax<bx+bw)
            return false;
        else return true;
    }
    if(kierunek==lewo){
        if(ax+aw>bx)
            return false;
        else return true;
    }
    if(kierunek==gora){
        if(ay+ah>by)
            return false;
        else return true;
    }
    if(kierunek==dol){
        if(ay<by+bh)
            return false;
        else return true;
    }
    
}*/
bool Collision::eCol(Sprite * obiekt){
    int lewoa=dst->x;
    int prawoa=dst->x+dst->w;
    int goraa=dst->y;
    int dola=dst->y+dst->h;
    
    int lewob=obiekt->dst.x;
    int prawob=obiekt->dst.x+obiekt->src.w;
    int gorab=obiekt->dst.y;
    int dolb=obiekt->dst.y+obiekt->src.h;
    
    //cout<<"x: "<<dst->x<<"\ny:"<<dst->y<<"\n"<<flush;
    if(dola<=gorab)
        return false;
    if(goraa>=dolb)
        return false;
    if(lewoa>=prawob)
        return false;
    if(prawoa<=lewob)
        return false;
    return true;
}