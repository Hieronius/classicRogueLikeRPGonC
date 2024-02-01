#ifndef rogue_h
#define rogue_h

#include <ncurses.h>
#include <stdlib.h>

typedef struct {
    int y;
    int x;
} Position; // entity to represent hero's position

typedef struct {
    Position position; // current hero's position
    char character; // representation of the hero on screen
} Entity;

// player.c functions
Entity *createPlayer(Position startPosition);
void handleInput(int input);

// externals files between all users of <rogue.h>
extern Entity *player;


#endif /* rogue_h */
