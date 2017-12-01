/*Assinaturas do modulo*/

#ifndef _LISTAS_H_
#define _LISTAS_H_

#include "lista.h"

void menu_lista(); //usuário selecionou opção de Criar/Editar Lista
void menu_compra();

void adicionaNaLista(item adicionado, lista listaCompras); //adiciona item na lista
void removeDaLista(std::string itemRemovido, lista listaCompras); //remove item da lista
lista recuperarListaPorCod(string codListaRecuperada); //usuario inseriu Codigo da lista; retornar struct da lista
bool possuiAcessoLista(string codUsuario, lista listaCompras); //saber se o codUsuario eh dono da lista

void exibirLista(lista listaExibida); //exibe 'listaAtual' na tela
void apagarLista(string codListaRecuperada);
void salvarLista(lista listaFinal);

#endif