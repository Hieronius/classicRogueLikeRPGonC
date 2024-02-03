#ifndef rogue_h
#define rogue_h

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

// color pairs
#define VISIBLE_COLOR 1 
#define SEEN_COLOR 2

// MARK: - Structs

typedef struct {
    int y;
    int x;
} Position; // entity to represent hero's position

typedef struct {
    char character; // character to represent a specific tiles on the map
    int color; // store a result of ncurses function COLOR_PAIR()
    bool walkable; // player can walk on floors but not  through the walls
} Tile; // represent toles of the map (should be represented by two dimensional-array)

typedef struct {
    int height;
    int width;
    Position position; // upper-left corner of the room
    Position center; // should be use to connect rooms with each other
} Room;

typedef struct {
    Position position; // current hero's position
    char character; // representation of the hero on screen
    int color; // store a result of ncurses function COLOR_PAIR()
} Entity;

// MARK: - Methods

// room.c functions
Room createRoom(int y, int x, int height, int width);
void addRoomToMap(Room room);
void connectRoomCenters(Position centerOne, Position centerTwo);

// draw.c functions
void drawMap(void);
void drawEntity(Entity* entity);
void drawEverything(void);

// engine.c functions
void cursesSetup(void);
void gameLoop(void);
void closeGame(void);

// map.c functions
Tile **createMapTiles(void);
Position setupMap(void);
void freeMap(void);

// player.c functions
Entity *createPlayer(Position startPosition);
void handleInput(int input);
void movePlayer(Position newPosition);

// room.c functions
Room createRoom(int y, int x, int height, int width);
void addRoomToMap(Room room);

// MARK: - Externals

// externals files between all users of <rogue.h>
extern const int MAP_HEIGHT;
extern const int MAP_WIDTH;
extern Tile **map; // two asterisks because our map should be represented by two-dimensional array;
extern Entity *player;


#endif /* rogue_h */
