CC=g++
CFLAGS=-lSDL -lSDL_image
DST=build/
CLASS=class/
LIBS=libs/
TMP=tmp/
FILE=Events.o Animation.o Collision.o libs/xmlParser.o LoadMap.o Sprite.o Screen.o main.o
#FILE=$(CLASS)Events.cpp $(CLASS)Collision.cpp $(CLASS)Sprite.cpp main.cpp
#main: $(FILE)
#	$(CC) $(CFLAGS) -o $(DST)main $(FILE)
all: $(FILE)
	$(CC) $(CFLAGS) $(FILE) -o $(DST)main
	
Events.o: $(CLASS)Events.cpp
	$(CC) -c $(CLASS)Events.cpp
	
Animation.o: $(CLASS)Animation.cpp
	$(CC) -c $(CLASS)Animation.cpp
	
Collision.o: $(CLASS)Collision.cpp
	$(CC) -c $(CLASS)Collision.cpp

xmlParser.o: $(LIBS)xmlParser.cpp
	$(CC) -c $(LIBS)xmlParser.cppp
	
LoadMap.o: $(CLASS)LoadMap.cpp
	$(CC) -c $(CLASS)LoadMap.cpp
	
Sprite.o: $(CLASS)Sprite.cpp
	$(CC) -c $(CLASS)Sprite.cpp
	
Screen.o: $(CLASS)Screen.cpp
	$(CC) -c -g $(CLASS)Screen.cpp

main.o: main.cpp
	$(CC) -c main.cpp

main: $(FILE)
	$(CC) $(CFLAGS) $(FILE) -o $(DST)main

