#include "rogue.h"

bool cursesSetup(void) {
    initscr(); // starts up the ncurses system and allows us to call all other functions in our terminal
    
    noecho(); // will prevent ncurses from immediately drawing on the screen when we press any keys
    
    curs_set(0); // will make our cursor invisible
    
    if (has_colors()) { // check whether the terminal supports colors
        
        start_color(); // if yes let's initialize ncurse's color system
        
        // first arg - ID, second - foreground color, third - background color
        init_pair(VISIBLE_COLOR, COLOR_WHITE, COLOR_BLACK);
         init_pair(SEEN_COLOR, COLOR_BLUE, COLOR_BLACK); // makes fog of war blue
        // init_pair(SEEN_COLOR, COLOR_BLACK, COLOR_BLACK); // removes fog of war entirely
        init_pair(PLAYER_COLOR, COLOR_GREEN, COLOR_BLACK);
        init_pair(ENEMY_COLOR, COLOR_RED, COLOR_BLACK);
        
        return true;
        
    } else {
        
        mvprintw(20, 50, "Your system dosn't support color. Can't start game!");
        getch();
        return false;
    }
}

void gameLoop(void) {
    int character; // variable to store user's input
    
    makeFOV(player);
    
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
