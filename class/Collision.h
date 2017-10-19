/* 
 * File:   Collision.h
 * Author: Dezio
 *
 * Created on 8 sierpień 2013, 12:14
 */

#ifndef COLLISION_H
#define	COLLISION_H
#include"Events.h"
#include<SDL/SDL.h>
#include"Sprite.h"
#include<fstream>
class Collision {
public:
    Collision(int w, int h,SDL_Rect * dst_,SDL_Rect * src_);
    Collision(const Collision& orig);
    virtual ~Collision();
    bool sCol();
    bool eCol(Sprite * obiekt);
private:
    int szer;
    int wys;
    SDL_Rect * dst;
    SDL_Rect * src;
};

#endif	/* COLLISION_H */

