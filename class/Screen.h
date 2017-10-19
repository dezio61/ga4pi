/* 
 * File:   Screen.h
 * Author: Dezio
 *
 * Created on 13 sierpień 2013, 13:03
 */

#ifndef SCREEN_H
#define	SCREEN_H
#include<cmath>
#include<iostream>
#include<vector>
#include<SDL/SDL.h>
#include"Sprite.h"
#include"Events.h"
#include"Collision.h"
#include"LoadMap.h"
#include"Animation.h"
#include<fstream>
struct spritelist{
    Sprite * obraz;
    string flag;
    string polozenie;
    string nazwa;
};
struct npc{
    Sprite * obraz;
    Animation * anim;
    Collision * kolizja;
    string nazwa;
    string flaga;
    Ruch kierunek;
};
class Screen {
public:
    Screen(int systemX,int systemY,string mapa_nazwa);
    Screen(const Screen& orig);
    virtual ~Screen();
    void rysuj(SDL_Surface * screen,int licznik);
    void czysc();
    void setcam();
    bool wczytaj();
    string mapa_nazwa_n;
    bool przeladuj;
    string lvlid;
private:
    Events * zdazenie;
    Collision * kolizja;
    Sprite * obrazek;
    LoadMap * mapa;
    int skok;
    int ile;
    int sysX,sysY,plX,plY;
    SDL_Rect cam;
    int lvlw;
    int lvlh;
    int licz2;
    bool b_kol;
    Animation * postac;
    vector<spritelist> sprity;
    vector<Elementy> elem;
    vector<Elementy> npctmp;
    vector<npc> npclist;
    
    bool colcheck(int x);
    bool colcheck(int x,Collision * kolizja);
    bool col_floor(int x,Collision * kolizjax);
    bool col_rect(Sprite * a,Sprite * b);
    bool colcheck2(int x);
    bool limitsk;
    int skok_l;
};

#endif	/* SCREEN_H */

