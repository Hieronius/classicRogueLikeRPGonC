#ifndef rogue_h
#define rogue_h

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// color pairs
#define VISIBLE_COLOR 1 
#define SEEN_COLOR 2
#define PLAYER_COLOR 3
#define ENEMY_COLOR 4
#define ITEMS_COLOR 5

// MARK: - Structs

typedef struct Position {
    int y;
    int x;
} Position; // entity to represent hero's position

typedef struct Tile {
    char character; // character to represent a specific tiles on the map
    int color; // store a result of ncurses function COLOR_PAIR()
    bool walkable; // player can walk on floors but not  through the walls
    bool transparent;
    bool visible;
    bool seen;
} Tile; // represent toles of the map (should be represented by two dimensional-array)

typedef struct Room {
    int height;
    int width;
    Position position; // upper-left corner of the room
    Position center; // should be use to connect rooms with each other
    // Monster ** monsters;
    // Item ** items; // i should understand why we need **array here
} Room;

typedef struct  Hero {
    Position position; // current hero's position
    char character; // representation of the hero on screen
    int health;
    int attack;
    int color; // store a result of ncurses function COLOR_PAIR()
} Hero;

typedef struct Enemy {
    Position position;
    char character;
    int health;
    int attack;
    int color;
} Enemy;

// MARK: - Methods

// room.c functions
Room createRoom(int y, int x, int height, int width);
void addRoomToMap(Room room);
void connectRoomCenters(Position centerOne, Position centerTwo);

// fov.c functions
void makeFOV(Hero *player);
void clearFOV(Hero *player);
int getDistance(Position origin, Position target);
bool isInMap(int y, int x);
bool lineOfSight(Position origin, Position target);
int getSign(int a);

// draw.c functions
void drawMap(void);
void drawHero(Hero* hero);
void drawEverything(void);

// engine.c functions
bool cursesSetup(void);
void gameLoop(void);
void closeGame(void);

// map.c functions
Tile **createMapTiles(void);
Position setupMap(void);
void freeMap(void);

// player.c functions
Hero *createPlayer(Position startPosition);
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
extern Hero *player;


#endif /* rogue_h */
