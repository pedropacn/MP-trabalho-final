/** @file */
/**
 * Módulo de funções de uso comum ao todo o código.
 */

/**
 * Bibliotecas utilizadas do C e C++.
 */
#include <string>    ///< manipulação de strings.
#include <ncurses.h> ///< interface grafica.
#include <iostream>  ///< ler e escrever na tela para o C++.
#include <string.h>  ///< ler e escrever na tela para o C.

/**
 * @brief Copia a string do C++ para um ponteiro de char do C.
 * @params cString é o ponteiro para char com o tamanho suficiente para receber
 * os caracteres da string.
 * @params str é a string no formato de string do C++.
 * @return Void. Retorna o ponteiro pra char por referência.
 */
void stringToChar (char* cString, std::string str) {
    strcpy(cString, str.c_str());
}

/**
 * @brief Mostrar na tela a variavel inserida pelo usuario. A função foi criada
 * utilizando a técnica de sobreposição de argumentos da função. O sistema 
 * detecta com quantos argumentos a função foi chamada e escolhe a que se 
 * encaixa.
 * @params texto é a informação que se deseja printar na tela.
 * @return Void.
 */
void escreve (std::string texto) {
    const char* lineChar = texto.c_str();
    printw("%s", lineChar);
    return;
}

/**
 * @brief Mostra na tela duas variaveis inseridas pelo usuário.
 * @params texto1 é a primeira informação que se deseja printar na tela.
 * @params texto2 é a segunda informação que se deseja printar na tela.
 * @return Void.
 */
void escreve (std::string texto1, std::string texto2) {
    const char* lineChar1 = texto1.c_str();
    const char* lineChar2 = texto2.c_str();
    printw("%s", lineChar1);
    printw("%s", lineChar2);
    return;
}

/**
 * @brief Mostra na tela três variaveis inseridas pelo usuário.
 * @params texto1 é a primeira informação que se deseja printar na tela.
 * @params texto2 é a segunda informação que se deseja printar na tela.
 * @params texto3 é a terceira informação que se deseja printar na tela.
 * @return Void.
 */
void escreve (std::string texto1, std::string texto2, std::string texto3) {
    const char* lineChar1 = texto1.c_str();
    const char* lineChar2 = texto2.c_str();
    const char* lineChar3 = texto3.c_str();
    printw("%s", lineChar1);
    printw("%s", lineChar2);
    printw("%s", lineChar3);
    return;
}

/**
 * @brief Função para calcular tamanho de um string constante do C.
 * @params input é a string que se quer calcular o tamanho .
 * @return Tamanho da string.
 */
int length(const char* input) {

    std::string auxString = input; ///< const char* to String
    return auxString.length();     ///< tamanho da string
}