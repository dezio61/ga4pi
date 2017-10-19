/* 
 * File:   Graphics.h
 * Author: Dezio
 *
 * Created on 7 sierpień 2013, 12:01
 */

#ifndef GRAPHICS_H
#define	GRAPHICS_H
#include<SDL/SDL.h>
enum error{
    brak=0,
    init_screen=1
};
class Graphics {
public:
    Graphics();
    Graphics(const Graphics& orig);
    virtual ~Graphics();
    void odswiez();
    void zakoncz();
    error blad;
    void dodaj_sprite(SDL_Surface * obraz);
    void test();
    void rPixel();
    void rLinie();
    void rTrojkat();
    
private:
    SDL_Surface* screen;
};

#endif	/* GRAPHICS_H */

