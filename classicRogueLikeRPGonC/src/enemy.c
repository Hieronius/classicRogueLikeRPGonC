#include "rogue.h"

Enemy *createEnemy(Position startPosition) {

    Enemy *newEnemy = calloc(1, sizeof(Enemy));

    newEnemy->position.y = startPosition.y += 1;
    newEnemy->position.x = startPosition.x += 1;
    newEnemy->character = 'O';
    newEnemy->health = 10;
    newEnemy->attack = 1;
    newEnemy->color = COLOR_PAIR(ENEMY_COLOR);

    return newEnemy;
}
