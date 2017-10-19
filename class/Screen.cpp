/* 
 * File:   Screen.cpp
 * Author: Dezio
 * 
 * Created on 13 sierpień 2013, 13:03
 */

#include "Screen.h"
Screen::Screen(int systemX,int systemY,string mapa_nazwa) {
    skok=2;
    skok_l=0;
    sysX=systemX;
    sysY=systemY;
    b_kol=false;
    limitsk=false;
    przeladuj=false;
    mapa_nazwa_n=mapa_nazwa;
    wczytaj();
    kolizja=new Collision(systemX,systemY,&(postac->postac->dst),&(postac->postac->src));
    zdazenie=new Events();
    cam.w=systemX;
    cam.h=systemY;
    cam.x=0;
    cam.y=0;
}

Screen::Screen(const Screen& orig) {
}

Screen::~Screen() {
    
}
void Screen::rysuj(SDL_Surface * screen,int licznik){
    int x=sprity.size();
    int y=npclist.size();
    Ruch ruch=iddle;
    bool dolb=zdazenie->dlugie(dol);
    if(zdazenie->dlugie(prawo)&&!dolb){
        postac->postac->dst.x+=skok;
        ruch=prawo_r;
        if(colcheck(x)) postac->postac->dst.x-=skok;
    }
    if(zdazenie->dlugie(lewo)&&!dolb){
        postac->postac->dst.x-=skok;
        ruch=lewo_r;
        if(colcheck(x)) postac->postac->dst.x+=skok;
    }
    if(zdazenie->dlugie(gora)&&!dolb&&!limitsk){
        postac->postac->dst.y-=skok;
        ruch=skok_r;
        skok_l++;
        if(skok_l==80){
            limitsk=true;
        }
        if(colcheck2(x)) postac->postac->dst.y+=skok;
    }
    else{
        limitsk=true;
        postac->postac->dst.y+=3;
        if(colcheck(x)){ 
            postac->postac->dst.y-=3;
            skok_l=0;
            limitsk=false;
        }
        else{
            //limitsk=false;
            //skok_l=0;
        }
        if(postac->postac->dst.y>sysY-20){
                postac->postac->dst.x=plX;
                postac->postac->dst.y=plY;
                limitsk=false;
                skok_l=0;
        }
    }
    if(postac->postac->dst.x>sysX)
        przeladuj=true;
    if(dolb){
        postac->postac->dst.y+=skok;
        ruch=kuc;
        if(colcheck(x)) postac->postac->dst.y-=skok;
    }
    for(int a=0;a<x;a++){
        if(sprity[a].polozenie=="z")
                SDL_BlitSurface(sprity[a].obraz->obraz,NULL,screen,&(sprity[a].obraz->dst));
    }
    SDL_Rect temp=postac->akcja(ruch);
    SDL_BlitSurface(postac->postac->obraz,&temp,screen,&(postac->postac->dst));
    
    for(int a=0;a<x;a++){
        if(sprity[a].polozenie=="p")
                SDL_BlitSurface(sprity[a].obraz->obraz,NULL,screen,&(sprity[a].obraz->dst));
    }
    if(y>0)
    for(int a=0;a<y;a++){
        SDL_Rect temp2=npclist[a].anim->akcja(npclist[a].kierunek);
        if(colcheck(x,npclist[a].kolizja)){
            if(npclist[a].kierunek==lewo_r){
                npclist[a].kierunek=prawo_r;
                npclist[a].obraz->dst.x+=2;
            }
            else if(npclist[a].kierunek==prawo_r){
                npclist[a].kierunek=lewo_r;
                npclist[a].obraz->dst.x-=2;
            }
        }
        if(col_rect(postac->postac,npclist[a].obraz)){
            postac->postac->dst.x=plX;
            postac->postac->dst.y=plY;
        }
        if(npclist[a].kierunek==lewo_r)
               npclist[a].obraz->dst.x--;
        if(npclist[a].kierunek==prawo_r)
               npclist[a].obraz->dst.x++;
        if(!col_floor(x,npclist[a].kolizja))
        npclist[a].obraz->dst.y++;
        SDL_BlitSurface(npclist[a].obraz->obraz,&temp2,screen,&(npclist[a].obraz->dst));
    }
}
void Screen::setcam(){
   // cam.x=(obrazek2->dst.x+obrazek2->src.w)-(sysX/2);
   // cam.y=(obrazek2->dst.y+obrazek2->src.h)-(sysY/2);
    if( cam.x < 0 )
    {
        cam.x = 0;    
    }
    if( cam.y < 0 )
    {
        cam.y = 0;    
    }
    if( cam.x > lvlw - cam.w )
    {
        cam.x = lvlw - cam.w;    
    }
    if( cam.y > lvlh - cam.h )
    {
        cam.y = lvlh - cam.h;    
    }   
}
bool Screen::colcheck(int x){
    for(int a=0;a<x;a++){
        if(sprity[a].flag=="c")
        if(kolizja->eCol(sprity[a].obraz)){
            return true;
        }
    }
    return false;
}
bool Screen::colcheck(int x,Collision * kolizjax){
    for(int a=0;a<x;a++){
        if(sprity[a].nazwa=="przeszkoda")
        if(kolizjax->eCol(sprity[a].obraz)){
            return true;
        }
    }
    return false;
}
bool Screen::col_floor(int x,Collision * kolizjax){
    for(int a=0;a<x;a++){
        if(sprity[a].flag=="c")
        if(kolizjax->eCol(sprity[a].obraz)){
            return true;
        }
    }
    return false;
}
bool Screen::col_rect(Sprite * A,Sprite * B){
    int leftA, leftB; 
    int rightA, rightB; 
    int topA, topB; 
    int bottomA, bottomB; 
    
    leftA = A->dst.x; 
    rightA = A->dst.x + A->dst.w; 
    topA = A->dst.y; 
    bottomA = A->dst.y + A->dst.h; 
    //Calculate the sides of rect B 
    leftB = B->dst.x; 
    rightB = B->dst.x + B->dst.w; 
    topB = B->dst.y; 
    bottomB = B->dst.y + B->dst.h;
    if( bottomA <= topB ) { return false; } 
    if( topA >= bottomB ) { return false; } 
    if( rightA <= leftB ) { return false; } 
    if( leftA >= rightB ) { return false; } 
    return true;
}
bool Screen::colcheck2(int x){
    for(int a=0;a<x;a++){
        if(sprity[a].flag=="c")
        if(kolizja->eCol(sprity[a].obraz)){
            limitsk=true;
            return true;
        }
    }
    return false;
}
bool Screen::wczytaj(){
    //mapa=new LoadMap("mapa");
    mapa=new LoadMap(mapa_nazwa_n);
    //if(!mapa->jest) return false;
    elem=mapa->dane();
    vector<Elementy> npctmp=mapa->npc();
    int x=elem.size();
    lvlid=elem[0].polozenie;
    string tmp="img/";
    spritelist tmp2;
    for(int a=0;a<x;a++){
        if(elem[a].typ=="elem"){
            tmp+=elem[a].sprite_n;
            tmp2.obraz=new Sprite(tmp.c_str());
            tmp2.flag=elem[a].flaga;
            tmp2.polozenie=elem[a].polozenie;
            tmp2.nazwa=elem[a].nazwa;
            sprity.push_back(tmp2);
            sprity[sprity.size()-1].obraz->dane_dst(elem[a].x,elem[a].y);
            tmp="img/";
        }
    }
    int y=npctmp.size();
    npc npct;
    for(int a=0;a<y;a++){
        tmp+=npctmp[a].sprite_n;
        
        /*npclist[a].nazwa=npctmp[a].nazwa;
        npclist[a].obraz=new Sprite(npctmp[a].sprite_n.c_str());
        npclist[a].anim=new Animation(npclist[a].obraz);
        npclist[a].kolizja=new Collision(sysX,sysY,&(npclist[a].anim->postac->dst),&(npclist[a].anim->postac->src));
        npclist[a].flaga=npctmp[a].flaga;*/
        
        npct.nazwa=npctmp[a].nazwa;
        npct.flaga=npctmp[a].flaga;
        npct.obraz=new Sprite(tmp.c_str());
        npct.obraz->dane_dst(npctmp[a].x,npctmp[a].y);
        npct.kierunek=prawo_r;
        npclist.push_back(npct);
        npclist[a].anim=new Animation(npclist[a].obraz);
        npclist[a].kolizja=new Collision(sysX,sysY,&(npclist[a].obraz->dst),&(npclist[a].obraz->src));
        
        
        tmp="img/";
    }
    string plik="img/";
    plik+=elem[1].sprite_n;
    postac=new Animation(new Sprite(plik.c_str()));
    postac->postac->dane_dst(elem[1].x,elem[1].y);
    plX=elem[1].x;
    plY=elem[1].y;
    postac->postac->klw=elem[1].w;
    postac->postac->klh=elem[1].h;
    return true;
}
void Screen::czysc(){
    //obrazek->uwolnij();
    //obrazek2->uwolnij();
    //drzewo->uwolnij();
    //ziemia1->uwolnij();
}