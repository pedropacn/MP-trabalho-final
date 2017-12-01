/*Assinaturas do modulo*/

#ifndef _LISTAS_H_
#define _LISTAS_H_

#include "lista.h"

void menu_lista(); //usuário selecionou opção de Criar/Editar Lista
void menu_compra();

void criaLista(item adicionado, lista listaCompras); //adiciona item na lista
void adicionaNaLista(item adicionado, lista listaCompras); //adiciona item na lista
void removeDaLista(std::string itemRemovido, lista listaCompras); //remove item da lista
lista recuperarListaPorCod(std::string codListaRecuperada); //usuario inseriu Codigo da lista; retornar struct da lista
bool possuiAcessoLista(std::string codUsuario, lista listaCompras); //saber se o codUsuario eh dono da lista

void exibirLista(lista listaExibida); //exibe 'listaAtual' na tela
void apagarLista(std::string codListaRecuperada);
void salvarLista(lista listaFinal);

#endif