#include <stdio.h>
#include <ncurses.h>

int main() {
    
    initscr(); // starts up the ncurses system and allows us to call all other functions in our terminal
    
    noecho(); // will prevent ncurses from immediately drawing on the screen when we press any keys

    curs_set(0); // will make our cursor invisible
    
    while (getch() != 'q') { // getch() - will get single character from the keyboard and return it without pressing "Enter"
        
        // So, until user will press 'q' game will draw '@' each new button that has been pressed
        
        mvaddch(10, 20, '@'); // function to print (draw) element in (y, x) coordinates
    }
    
    endwin(); // ncurses function that closes ncurses in our terminal
    
    
    return 0;
}
