#include <string> //classe string
#include <ncurses.h> //interface grafica
#include <iostream> //ler e escrever na tela

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

/*funcao necessaria pra mostrar variavel inserida pelo usuario*/
void escreve (std::string texto) {
    const char* lineChar = texto.c_str();
    printw("%s", lineChar);
    return;
}

void escreve (std::string texto1, std::string texto2) {
    const char* lineChar1 = texto1.c_str();
    const char* lineChar2 = texto2.c_str();
    printw("%s", lineChar1);
    printw("%s", lineChar2);
    return;
}

void escreve (std::string texto1, std::string texto2, std::string texto3) {
    const char* lineChar1 = texto1.c_str();
    const char* lineChar2 = texto2.c_str();
    const char* lineChar3 = texto3.c_str();
    printw("%s", lineChar1);
    printw("%s", lineChar2);
    printw("%s", lineChar3);
    return;
}