#include "rogue.h"

const int MAP_HEIGHT = 25;
const int MAP_WIDTH = 100;

Entity *player; // external variable from rogue.h
Tile **map;

int main(void) {
    
    Position startPosition;
    cursesSetup();
    
    map = createMapTiles();
    startPosition = setupMap();
    player = createPlayer(startPosition);
    
    gameLoop();
    closeGame();
    
    return 0;
}
