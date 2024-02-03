#include "rogue.h"

void drawMap(void) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            mvaddch(y, x, (*(*(map + y) + x)).character | (*(*(map + y) + x)).color); // returns the same tile but with different color
        }
    }
}

void drawEntity(Entity *entity) {
    mvaddch(entity->position.y, entity->position.x, entity->character | entity->color); // returns the same character but with different color
}

void drawEverything(void) {
    clear();
    drawMap();
    drawEntity(player);
}
