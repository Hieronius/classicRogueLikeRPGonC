#include "rogue.h"

// Field Of View about
void makeFOV(Entity *player) {
    int y;
    int x;
    int distance;
    int RADIUS = 15;
    Position target;
    
    (*(*(map + player->position.y) + player->position.x)).visible = true;
    (*(*(map + player->position.y) + player->position.x)).seen = true;
    
    for (y = player->position.y - RADIUS; y < player->position.y + RADIUS; y++) {
        
        for (x = player->position.x - RADIUS; x < player->position.x + RADIUS; x++) {
            
            target.y = y;
            target.x = x;
            distance = getDistance(player->position, target);
            
            if (distance < RADIUS) {
                
                if (isInMap(y,x) && lineOfSight(player->position, target)) {
                    
                    (*(*(map + y) + x)).visible = true;
                    (*(*(map + y) + x)).seen = true;
                }
            }
        }
    }
}

void clearFOV(Entity *player) {
    int y;
    int x;
    int RADIUS = 15;
    
    for (y = player->position.y - RADIUS; y < player->position.y + RADIUS; y++) {
        
        for (x = player->position.x - RADIUS; x < player->position.x + RADIUS; x++) {
            
            if (isInMap(y,x)) {
                (*(*(map + y) + x)).visible = false;
            }
        }
    }
}

// calculates distance with hypotenuse formula
int getDistance(Position origin, Position target) {
    double dy;
    double dx;
    int distance;
    dx = target.x - origin.x;
    dy = target.y - origin.y;
    distance = floor(sqrt((dx * dx) + (dy * dy)));
    
    return distance;
}

bool isInMap(int y, int x) {
    if ((0 < y && y < MAP_HEIGHT - 1) && (0 < x && x < MAP_WIDTH - 1)) {
        return true;
    }
    return false;
}

bool lineOfSight(Position origin, Position target) {
    // origin - our hero
    // target - object on his Field Of View
    
    int t;
    int x;
    int y;
    int abs_delta_x;
    int abs_delta_y;
    int sign_x;
    int sign_y;
    int delta_x;
    int delta_y;
    
    // we should calculate a difference between origin and target in coordinates
    delta_x = origin.x - target.x;
    delta_y = origin.y - target.y;
    
    abs_delta_x = abs(delta_x);
    abs_delta_y = abs(delta_y);
    
    sign_x = getSign(delta_x);
    sign_y = getSign(delta_y);
    
    y = target.x;
    y = target.y;
    
    if (abs_delta_x > abs_delta_y) {
        t = abs_delta_y * 2 - abs_delta_x;
        
        do {
            
            if (t >= 0) {
                y += sign_y;
                t -= abs_delta_x * 2;
            }
            
            x += sign_x;
            t += abs_delta_y * 2;
            
            if (x == origin.x && y == origin.y) {
                return true;
            }
        }
        
        while ((*(*(map + y) + x)).transparent);
        
        return false;
        
    } else {
        t = abs_delta_x * 2 - abs_delta_y;
        
        do {
            
            if (t >= 0) {
                x += sign_x;
                t -= abs_delta_y * 2;
            }
            
            y += sign_y;
            t += abs_delta_x * 2;
            
            if (x == origin.x && y == origin.y) {
                return true;
            }
        }
        while ((*(*(map + y) + x)).transparent);
        
        return false;
    }
}

int getSign(int a) {
    return (a < 0) ? -1 : 1;
}
