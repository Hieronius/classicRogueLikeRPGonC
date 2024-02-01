#include "rogue.h"

const int MAP_HEIGHT = 25;
const int MAP_WIDTH = 100;

Entity *player; // external variable from rogue.h

int main(void) {
    cursesSetup();
    
    Position startPosition = {10,20};
    player = createPlayer(startPosition);
    
    gameLoop();
    closeGame();
    
    return 0;
}
