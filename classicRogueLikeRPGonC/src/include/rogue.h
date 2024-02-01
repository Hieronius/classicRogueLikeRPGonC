#ifndef rogue_h
#define rogue_h

#include <ncurses.h>
#include <stdlib.h>

typedef struct {
    int y;
    int x;
} Position; // entity to represent hero's position

typedef struct {
    char character; // character to represent a specific tiles on the map
    bool walkable; // player can walk on floors but not  through the walls
} Tile; // represent toles of the map (should be represented by two dimensional-array)

typedef struct {
    Position position; // current hero's position
    char character; // representation of the hero on screen
} Entity;

// engine.c functions
void cursesSetup(void);
void gameLoop(void);
void closeGame(void);

// map.c functions
Tile **createMapTiles(void);
void freeMap(void);

// player.c functions
Entity *createPlayer(Position startPosition);
void handleInput(int input);

// externals files between all users of <rogue.h>
extern const int MAP_HEIGHT;
extern const int MAP_WIDTH;
extern Tile **map; // two asterisks because our map should be represented by two-dimensional array;
extern Entity *player;


#endif /* rogue_h */
