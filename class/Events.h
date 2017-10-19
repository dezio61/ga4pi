/* 
 * File:   Events.h
 * Author: Dezio
 *
 * Created on 7 sierpień 2013, 11:19
 */

#ifndef EVENTS_H
#define	EVENTS_H
#include<SDL/SDL.h>
enum akcja{
    wyjscie=0,
    gora=1,
    dol=2,
    lewo=3,
    prawo=4
};
class Events {
public:
    Events();
    Events(const Events& orig);
    virtual ~Events();
    void krotkie_dol();
    void krotkie_gora();
    bool dlugie(akcja gdzie);
    akcja dzialanie;
    akcja dzialanie_g;
private:
    SDL_Event zdarzenie;
    Uint8 * keystate;
};

#endif	/* EVENTS_H */

