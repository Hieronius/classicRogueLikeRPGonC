#include "rogue.h"

const int MAP_HEIGHT = 25;
const int MAP_WIDTH = 100;

Entity *player; // external variable from rogue.h
Tile **map;

int main(void) {
    
    Position startPosition;
    bool compatibleTerminal;
    
    compatibleTerminal = cursesSetup();
    
    if (compatibleTerminal) {
        
        srand(time(NULL)); // create a seed for rand function so each run of the programm we will get different random generation
        
        map = createMapTiles();
        startPosition = setupMap();
        player = createPlayer(startPosition);
        
        gameLoop();
        closeGame();
        
    } else {
        endwin();
    }
    
    return 0;
}
