/** @file */
/** 
 * Arquivo com conjunto de headers para o modulo de gerenciamento de listas
 */

#ifndef _LISTAS_H_
#define _LISTAS_H_

#include "lista.h"

void menu_lista(); ///< usuário selecionou opção de Criar/Editar Lista.
void menu_compra();

void criaLista(item adicionado, lista listaCompras); ///< adiciona item na lista.
lista adicionaNaLista(item adicionado, lista listaCompras); ///< adiciona item na lista.
void removeDaLista(std::string itemRemovido, lista listaCompras); ///< remove item da lista.
lista recuperarListaPorCod(std::string codListaRecuperada); ///< usuario inseriu Codigo da lista; retornar struct da lista.
bool possuiAcessoLista(std::string codUsuario, lista listaCompras); ///< saber se o codUsuario eh dono da lista.

void exibirLista(lista listaExibida); ///< exibe 'listaAtual' na tela.
std::string apagarLista(std::string stringCodLista); ///< apaga a lista do arquivo e retorna sua sting correspondente.
void salvarLista(lista listaFinal);

#endif