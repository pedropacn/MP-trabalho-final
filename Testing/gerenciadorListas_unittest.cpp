#include "lista.h" //struct lista
#include "common.h" //funcoes genericas para todos os .cpp
#include "gerenciadorItens.h" //gerenciar itens da lista
#include <fstream> //manipular arquivos com getline
#include <ncurses.h> //interface grafica
#include <string.h> //tipo string
#include <stdlib.h> //atoi - converter string para inteiro

#include "gerenciadorListas.h" //gerenciar itens da lista
#include <gtest/gtest.h>
namespace {

TEST(gerenciadorListasTest, Negative) {
  EXPECT_EQ(0, recuperarListaPorCod("7698").codLista.compare("0000"));
  EXPECT_NE(0, recuperarListaPorCod("0000").codLista.compare("0000"));
}  

}