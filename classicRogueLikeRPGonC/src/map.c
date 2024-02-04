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
            (*(*(tiles + y) + x)).color = COLOR_PAIR(VISIBLE_COLOR);
            (*(*(tiles + y) + x)).walkable = false;
            (*(*(tiles + y) + x)).transparent = false;
            (*(*(tiles + y) + x)).visible = false;
            (*(*(tiles + y) + x)).seen = false;
        }
    }
    
    return tiles;
}

Position setupMap(void) {
    
    int y;
    int x;
    int height;
    int width;
    int numberOfRooms;
    
    numberOfRooms = (rand() % 11) + 5; // random number from 5 to 15
    Room* rooms = calloc(numberOfRooms, sizeof(Room));
    
    Position startPosition;
    
    // pass height and width to each room
    for (int i = 0; i < numberOfRooms; i++) {
        
        y = (rand() % (MAP_HEIGHT - 10)) + 1;
        x = (rand() % (MAP_WIDTH - 20)) + 1;
        height = (rand() % 7) + 3;
        width = (rand() % 15) + 5;
        
        *(rooms + i) = createRoom(y, x, height, width);
        addRoomToMap(*(rooms + i));
        
        if (i > 0) { // i > 0 because we should wait for creation of first room to start monitoring all possible ways to connect second, third and so on rooms
            connectRoomCenters((*(rooms + i - 1)).center, (*(rooms + i)).center);
        }
    }
    
    startPosition.y = rooms->center.y; // coordinate to place player
    startPosition.x = rooms->center.x; // into the middle of the first room
    
    free(rooms); // rooms are already on the map so we can remove it from here
    
    return startPosition;
}

void freeMap(void) {
    
    // free first row of the map tiles
    for (int y = 0; y < MAP_HEIGHT; y++) {
        free(*(map + y));
    }
    // free next row of the map tiles
    free(map);
}
