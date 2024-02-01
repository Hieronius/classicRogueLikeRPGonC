#include "rogue.h"

Entity *player; // external variable from rogue.h

int main() {
    int character = 0; // variable to store user's input
    Position startPosition = {10, 20}; // hardcode starting point of the player
    
    initscr(); // starts up the ncurses system and allows us to call all other functions in our terminal
    
    noecho(); // will prevent ncurses from immediately drawing on the screen when we press any keys

    curs_set(0); // will make our cursor invisible
    
    player = createPlayer(startPosition);
    mvaddch(player->position.y, player->position.x, player->character); // function to print (draw) element in (y, x) coordinates
    
    while (character == getch()) { // getch() - will get single character from the keyboard and return it without pressing "Enter"
        
        // So, until user will press 'q' game will draw '@' each new button that has been pressed
        if (character == 'q') {
            break;
        }
        
        handleInput(character);
        clear();
        mvaddch(player->position.y, player->position.x, player->character);
    }
    
    endwin(); // ncurses function that closes ncurses in our terminal
    
    
    return 0;
}
