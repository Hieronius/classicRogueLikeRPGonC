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

void drawHero(Hero *hero) {
    mvaddch(hero->position.y, hero->position.x, hero->character | hero->color); // returns the same character but with different color
}

void drawEnemy(Enemy *enemy) {
    mvaddch(enemy->position.y, enemy->position.x, enemy->character | enemy->color);
}

void drawEverything(void) {
    clear();
    drawMap();
    drawHero(player);
    drawEnemy(singleEnemy);
}
