//
//  rogue.h
//  classicRogueLikeRPGonC
//
//  Created by Арсентий Халимовский on 31.01.2024.
//

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


#endif /* rogue_h */
