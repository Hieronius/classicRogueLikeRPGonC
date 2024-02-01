#include "rogue.h"

const int MAP_HEIGHT = 25;
const int MAP_WIDTH = 100;

Entity *player; // external variable from rogue.h
Tile **map;

int main(void) {
    cursesSetup();
    
    Position startPosition = {10,20};
    player = createPlayer(startPosition);
    map = createMapTiles();
    
    gameLoop();
    closeGame();
    
    return 0;
}
