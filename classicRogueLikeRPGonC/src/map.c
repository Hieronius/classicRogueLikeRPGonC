#include "rogue.h"

Tile **createMapTiles(void) { // return two dimensional array of MapTiles
    
    // We wan't to allocate memory MAP_HEIGHT * MAP_WIDTH amount of tiles
    
    // probably allocates MAP_HEIGHT * size of one tile
    Tile **tiles = calloc(MAP_HEIGHT, sizeof(Tile*));
    
    // allocates MAP_WIDTH * size of one tile
    for (int y = 0; y < MAP_HEIGHT; y++) {
        *(tiles + y) = calloc(MAP_WIDTH, sizeof(Tile));
        
        // fill each of the tiles with values
        for (int x = 0; x < MAP_WIDTH; x++) {
            (*(*(tiles + y) + x)).character = '#';
            (*(*(tiles + y) + x)).walkable = false;
        }
    }
    
    return tiles;
}

void freeMap(void) {
    
    // free first row of the map tiles
    for (int y = 0; y < MAP_HEIGHT; y++) {
        free(*(map + y));
    }
    // free next row of the map tiles
    free(map);
}