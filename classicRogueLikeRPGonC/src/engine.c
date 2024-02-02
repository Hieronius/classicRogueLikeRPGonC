#include "rogue.h"

void cursesSetup(void) {
    initscr(); // starts up the ncurses system and allows us to call all other functions in our terminal
    
    noecho(); // will prevent ncurses from immediately drawing on the screen when we press any keys
    
    curs_set(0); // will make our cursor invisible
}

void gameLoop(void) {
    int character; // variable to store user's input
    
    drawEverything(); // clean the screen, draw map and the player.
    
    while ((character = getch())) { // getch() - will get single character from the keyboard and return it without pressing "Enter"
        
        // We use one equation operator because otherwise loop will break after single button to press
        
        // So, until user will press 'q' game will draw '@' each new button that has been pressed
        if (character == 'q') {
            break;
        }
        
        handleInput(character);
        drawEverything();
    }
}

void closeGame(void) {
    endwin(); // ncurses function that closes ncurses in our terminal
    free(player); // been allocted with calloc()
}
