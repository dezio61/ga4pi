/* 
 * File:   menu.h
 * Author: Dezio
 *
 * Created on 14 sierpień 2013, 12:55
 */

#ifndef MENU_H
#define	MENU_H
#include"Sprite.h"
#include"Events.h"
class menu {
public:
    menu();
    menu(const menu& orig);
    menu(int systemX,int systemY);
    virtual ~menu();
    void rysuj(SDL_Surface * screen);
    void czysc();
private:

};

#endif	/* MENU_H */

