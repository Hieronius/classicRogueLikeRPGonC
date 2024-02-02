#include "rogue.h"

void drawMap(void) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            mvaddch(y, x, (*(*(map + y) + x)).character);
        }
    }
}

void drawEntity(Entity *entity) {
    mvaddch(entity->position.y, entity->position.x, entity->character);
}

void drawEverything(void) {
    clear();
    drawMap();
    drawEntity(player);
}
