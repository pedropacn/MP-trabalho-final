/*Assinaturas do modulo*/

#ifndef _COMPRAS_H_
#define _COMPRAS_H_

#include "item.h"

void menu_cadastrar_item(); //usuário selecionou opção de Inserir item

item criaItem(); //inicializa item
bool insereItem(std::string name,std::string preco,std::string codBarras); //insere item no arquivo itens.txt
item pesquisaItemPorCodBarras(std::string codBarras); //retorna item caso o encontre no arquivo; retorna encontrado.codBarras = 0 em caso contrário
item pesquisaItemPorNome(std::string nomeItem); //retorna item caso o encontre no arquivo; retorna encontrado.codBarras = 0 em caso contrário

#endif
