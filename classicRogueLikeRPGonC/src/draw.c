#include "rogue.h"

void drawMap(void) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            
            if ((*(*(map + y) + x)).visible) {
                mvaddch(y, x, (*(*(map + y) + x)).character | (*(*(map + y) + x)).color);
                
            } else if ((*(*(map + y) + x)).seen) {
                    mvaddch(y, x, (*(*(map + y) + x)).character | COLOR_PAIR(SEEN_COLOR));
                
            } else {
                mvaddch(y, x, ' ');
            }
        }
    }
}

void drawEntity(Hero *entity) {
    mvaddch(entity->position.y, entity->position.x, entity->character | entity->color); // returns the same character but with different color
}

void drawEverything(void) {
    clear();
    drawMap();
    drawEntity(player);
}
