#include "rogue.h"

Room createRoom(int y, int x, int height, int width) {
    Room newRoom;
    
    // pass coordinates to the starting point of the room spawn
    newRoom.position.y = y;
    newRoom.position.x = x;
    newRoom.height = height;
    newRoom.width = width;
    newRoom.center.y = y + (int)(height / 2); // without downcasting we can get float data type as result
    newRoom.center.x = x + (int)(width / 2);
    
    return newRoom;
}

void connectRoomCenters(Position centerOne, Position centerTwo) {

    Position temp;
    temp.x = centerOne.x; // coordinates of the first room
    temp.y = centerOne.y; // to connect from

    // move temp position until it reach the coordinates of the center of second room and stop the loop.
    while (true) {

        // if centerOneX is bigger than centerTwoX let's decrement centerOne.x
        if (abs((temp.x - 1) - centerTwo.x) < abs(temp.x - centerTwo.x)) {
            temp.x--;
            
        // if centerOneX is smaller than centerTwoX let's increment centerOne.x
        } else if (abs((temp.x + 1) - centerTwo.x) < abs(temp.x - centerTwo.x)) {
            temp.x++;

        // if centerOneY if smaller than centerTwoY let's increment centerOne.y
        } else if (abs((temp.y + 1) - centerTwo.y) < abs(temp.y - centerTwo.y)) {
            temp.y++;
         
        // if centerOneY is bigger than centerTwoY let's decrement centerOne.y
        } else if (abs((temp.y - 1) - centerTwo.y) < abs(temp.y - centerTwo.y)) {
            temp.y--;
        
        // If centerOne = centerTwo let's brake the loop.
        } else {
            break;
        }
        
        // each iteration draw walkable tile of new coordinate we have reached to
        (*(*(map + temp.y) + temp.x)).character = '.';
        (*(*(map + temp.y) + temp.x)).walkable = true;
    }
}

void addRoomToMap(Room room) {
    for (int y = room.position.y; y < room.position.y + room.height; y++) {
        for (int x = room.position.x; x < room.position.x + room.width; x++) {
            (*(*(map + y) + x)).character = '.';
            (*(*(map + y) + x)).walkable = true;
        }
    }
}


