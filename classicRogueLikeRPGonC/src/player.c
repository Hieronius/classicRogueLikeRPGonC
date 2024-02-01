#include "rogue.h"

// function get's position and returns pointer to an Entity
// We create the player as a pointer to Entity in order to be able to modify his component variables in function calls
Entity *createPlayer(Position startPosition) {
    
    // declare the newPlayer variable and dynamically allocates the appropriate memory for that pointer
    // We use calloc instead of malloc because it's more flexiable.
    // malloc gives us a fixed block of code
    // calloc give us as many memory as need for an entity
    Entity *newPlayer = calloc(1, sizeof(Entity));
    
    newPlayer->position.y = startPosition.y;
    newPlayer->position.x = startPosition.x;
    newPlayer->character = '@';
    
    return newPlayer;
}

void handleInput(int input) {
    switch(input) {
        case 'w': // move up
            player->position.y -= 1;
            break;
        case 's': // move down
            player->position.y += 1;
            break;
        case 'a': // move left
            player->position.x -= 1;
            break;
        case 'd': // move right
            player->position.x += 1;
            break;
        default:
            break;
    }
}
