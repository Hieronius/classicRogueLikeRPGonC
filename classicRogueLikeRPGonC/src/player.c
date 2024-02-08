#include "rogue.h"

// function get's position and returns pointer to an Entity
// We create the player as a pointer to Entity in order to be able to modify his component variables in function calls
Hero *createPlayer(Position startPosition) {
    
    // declare the newPlayer variable and dynamically allocates the appropriate memory for that pointer
    // We use calloc instead of malloc because it's more flexiable.
    // malloc gives us a fixed block of code
    // calloc give us as many memory as need for an entity
    Hero *newPlayer = calloc(1, sizeof(Hero));
    
    newPlayer->position.y = startPosition.y;
    newPlayer->position.x = startPosition.x;
    newPlayer->character = '@';
    newPlayer->health = 100;
    newPlayer->attack = 10;
    newPlayer->color = COLOR_PAIR(VISIBLE_COLOR);
    
    return newPlayer;
}

void handleInput(int input) {
    
    // get current Player position
    Position newPosition = {player->position.y, player->position.x};
    
    // process the input
    switch(input) {
        case 'w': // move up
        case 'W':
            newPosition.y--;
            break;
        case 's': // move down
        case 'S':
            newPosition.y++;
            break;
        case 'a': // move left
        case 'A':
            newPosition.x--;
            break;
        case 'd': // move right
        case 'D':
            newPosition.x++;
            break;
        default:
            break;
    }
    
    // return new coordinates to the players if tile to step is walkable
    movePlayer(newPosition);
}

void movePlayer(Position newPosition) {
    if ((*(*(map + newPosition.y) + newPosition.x)).walkable) {
        clearFOV(player);
        player->position.y = newPosition.y;
        player->position.x = newPosition.x;
        makeFOV(player);
    }
}
