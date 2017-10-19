#include<SDL/SDL.h>
#include<string>
#include<sstream>
#include"class/Events.h"
#include"class/Screen.h"
using namespace std;
bool wyjdz=false;
Uint8 licznik=0;
Uint8 skok=3;
Screen * obraz1;
string mapbase="mapa";
enum poziom{
    menu=0,
    poziom1=1
};
int main( int argc, char* args[] )
{
    if(argc>1){
        mapbase=args[1];
    }
    Events zdazenie;
    SDL_Surface* screen = NULL;
    SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    const SDL_VideoInfo* videoInfo = SDL_GetVideoInfo ();
    int systemX = videoInfo->current_w ;
    int systemY = videoInfo->current_h ;
    Uint8 bpp = videoInfo->vfmt->BitsPerPixel ;
    screen = SDL_SetVideoMode( systemX, systemY, 16, SDL_SWSURFACE );
    SDL_ShowCursor(0);
    SDL_Rect r = {0,0,systemX,systemY};
    obraz1=new Screen(systemX,systemY,mapbase);
    while(!wyjdz){
        //SDL_Delay(30);
        //obraz1.mapa_nazwa="mapa";
        zdazenie.krotkie_gora();
        if(zdazenie.dzialanie_g==wyjscie){
            wyjdz=true;
        }
        
        SDL_FillRect(screen,&r, SDL_MapRGB(screen->format, 0,108,255));
        //obraz1->setcam();
        obraz1->rysuj(screen,licznik);
        SDL_Flip( screen );
        licznik++;
        if(licznik==101)
            licznik=0;
        if(obraz1->przeladuj){
            int mapid_t=atoi(obraz1->lvlid.c_str());
            mapid_t++;
            ostringstream ss;
            ss << mapid_t;
            string tmp=mapbase;
            tmp+=ss.str();
            obraz1=new Screen(systemX,systemY,tmp);
        }
        ofstream myfile;
        myfile.open ("example.txt");
        myfile << SDL_GetError()<<endl;
        myfile.close();
    }
    //cout<<SDL_GetError()<<endl;
    obraz1->czysc();
    SDL_Quit();
    return 0;
}

