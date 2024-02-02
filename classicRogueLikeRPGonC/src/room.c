#include "rogue.h"

Room createRoom(int y, int x, int height, int width) {
    Room newRoom;
    
    newRoom.position.y = y;
    newRoom.position.x = x;
    newRoom.height = height;
    newRoom.width = width;
    newRoom.center.y = y + (int)(height / 2); // without downcasting we can get float data type as result
    newRoom.center.x = x + (int)(width / 2);
    
    return newRoom;
}

void AddRoomToMap(Room room) {
    for (int y = room.position.y; y < room.position.y + room.height; y++) {
        for (int x = room.position.x; x < room.position.x + room.width; x++) {
            (*(*(map + y) + x)).character = '.';
            (*(*(map + y) + x)).walkable = true;
        }
    }
}
