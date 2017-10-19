/* 
 * File:   Animation.h
 * Author: Dezio
 *
 * Created on 26 sierpień 2013, 12:29
 */

#ifndef ANIMATION_H
#define	ANIMATION_H
#include"Sprite.h"
enum Ruch{
    iddle=0,
    lewo_r=1,
    prawo_r=2,
    skok_r=3,
    kuc=4
};
class Animation {
public:
    Animation(Sprite * postac_t);
    Animation(const Animation& orig);
    virtual ~Animation();
    SDL_Rect akcja(Ruch ruch);
    Sprite * postac;
private:
    int x;
    SDL_Rect porcje[13];
};

#endif	/* ANIMATION_H */

