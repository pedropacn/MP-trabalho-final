/** @file */
/** 
 * Arquivo com conjunto de headers para as funções comuns a todo o código
 */

#ifndef _COMMON_H_
#define _COMMON_H_

void stringToChar(char *cString, std::string str); ///< converte string para ponteiro de caracteres
void escreve(std::string texto); ///< printa na tela
void escreve (std::string texto1, std::string texto2);
void escreve (std::string texto1, std::string texto2, std::string texto3);
int length(const char *input); ///< tamanho da string

#endif