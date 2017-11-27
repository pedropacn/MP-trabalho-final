#include <iostream>
#include <ncurses.h>

std::string getstring() {
    std::string input;

    // let the terminal do the line editing
    nocbreak();
    echo();

    // this reads from buffer after <ENTER>, not "raw" 
    // so any backspacing etc. has already been taken care of
    int ch = getch();

    while ( ch != '\n') {
        input.push_back( ch );
        ch = getch();
    }

    //restore your cbreak / echo settings here

    return input;
}
