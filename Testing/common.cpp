#include <string> //classe string
#include <ncurses.h> //interface grafica
#include <iostream> //ler e escrever na tela
#include <string.h> //ler e escrever na tela

//copia a string para o char*
void stringToChar (char* cString, std::string str) {

    strcpy(cString, str.c_str());
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

int length(const char* input) { //retorna o tamanho de um const char*

    std::string auxString = input; //const char* to String
    return auxString.length(); //tamanho da string
}