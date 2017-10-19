/* 
 * File:   LoadMap.cpp
 * Author: Dezio
 * 
 * Created on 15 sierpień 2013, 13:05
 */

#include "LoadMap.h"

LoadMap::LoadMap(string nazwa){
    string plik_n="maps/";
    plik_n+=nazwa;
    plik_n+=".xml";
    XMLNode map=XMLNode::openFileHelper(plik_n.c_str(),"map");
    
    XMLNode lvlinfo=map.getChildNode("lvlinfo");
    int ile=atoi(lvlinfo.getAttribute("lelem"));
    int szer=atoi(lvlinfo.getAttribute("width"));
    int wys=atoi(lvlinfo.getAttribute("height"));
    Elementy tmp2;
    tmp2.nazwa="lvlinfo";
    tmp2.typ="lvlinfo";
    tmp2.w=szer;
    tmp2.h=wys;
    tmp2.polozenie=lvlinfo.getAttribute("lvlid");
    elem.push_back(tmp2);
    
    XMLNode postac=lvlinfo.getChildNode("postac");
    tmp2.nazwa=postac.getAttribute("name");
    tmp2.sprite_n=postac.getAttribute("sprite");
    tmp2.flaga="m";
    tmp2.x=atoi(postac.getAttribute("posX"));
    tmp2.y=atoi(postac.getAttribute("posY"));
    tmp2.w=atoi(postac.getAttribute("w"));
    tmp2.h=atoi(postac.getAttribute("h"));
    elem.push_back(tmp2);
    XMLNode tmp;
    
    int lnpc=lvlinfo.nChildNode("enemy");
    for(int a=0;a<lnpc;a++){
        tmp=lvlinfo.getChildNode("enemy",a);
        tmp2.nazwa==tmp.getAttribute("name");
        tmp2.sprite_n=tmp.getAttribute("sprite");
        tmp2.flaga=tmp.getAttribute("flag");
        tmp2.x=atoi(tmp.getAttribute("posX"));
        tmp2.y=atoi(tmp.getAttribute("posY"));
        tmp2.w=atoi(tmp.getAttribute("w"));
        tmp2.h=atoi(tmp.getAttribute("h"));
        npclist.push_back(tmp2);
    }
    
    XMLNode elemlist=map.getChildNode("elemlist");
    
    for(int a=2;a<ile;a++){
        tmp=elemlist.getChildNode("elem",a-2);
        tmp2.typ="elem";
        tmp2.sprite_n=tmp.getAttribute("sprite");
        tmp2.nazwa=tmp.getAttribute("name");
        tmp2.flaga=tmp.getAttribute("flag");
        tmp2.x=atoi(tmp.getAttribute("posX"));
        tmp2.y=atoi(tmp.getAttribute("posY"));
        tmp2.polozenie=tmp.getAttribute("z-index");
        elem.push_back(tmp2);
    }
}
LoadMap::LoadMap(const LoadMap& orig) {
}

LoadMap::~LoadMap() {
}
vector<Elementy> LoadMap::dane(){
    return elem;
}
vector<Elementy>LoadMap::npc(){
    return npclist;
}
