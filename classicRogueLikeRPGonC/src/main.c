#include "rogue.h"

const int MAP_HEIGHT = 25;
const int MAP_WIDTH = 75;

// external variable from rogue.h
Hero *player;
 Enemy **enemiesArmy;
 Enemy *singleEnemy;
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
        singleEnemy = createEnemy(startPosition);
        
        gameLoop();
        closeGame();
        
    } else {
        endwin();
    }
    
    return 0;
}
