/* 
 * File:   LoadMap.h
 * Author: Dezio
 *
 * Created on 15 sierpień 2013, 13:05
 */

#ifndef LOADMAP_H
#define	LOADMAP_H
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"../libs/xmlParser.h"
using namespace std;
struct Elementy{
    string typ;
    string sprite_n;
    string nazwa;
    string flaga;
    string polozenie;
    int x;
    int y;
    int w;
    int h;
};
class LoadMap {
public:
    LoadMap(string nazwa);
    LoadMap(const LoadMap& orig);
    virtual ~LoadMap();
    vector<Elementy> dane();
    vector<Elementy> npc();
    bool jest;
private:
    ifstream plik;
    vector<Elementy> elem;
    vector<Elementy> npclist;
};
#endif	/* LOADMAP_H */

