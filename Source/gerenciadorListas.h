/*Assinaturas do modulo*/

#ifndef _LISTAS_H_
#define _LISTAS_H_

#include "lista.h"

void menu_lista(); //usuário selecionou opção de Criar/Editar Lista
void menu_compra();

void removeDaLista(std::string itemRemovido, lista listaCompras);
lista recuperarListaPorCod(int codListaRecuperada); //usuario inseriu Codigo da lista; retornar struct da lista
void exibirLista(lista listaExibida); //exibe 'listaAtual' na tela
void apagarLista(int codListaRecuperada);
void salvarLista(lista listaFinal);

#endif