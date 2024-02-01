#include "rogue.h"

Entity *player; // external variable from rogue.h

int main(void) {
    cursesSetup();
    
    Position startPosition = {10,20};
    player = createPlayer(startPosition);
    
    gameLoop();
    closeGame();
    
    return 0;
}
