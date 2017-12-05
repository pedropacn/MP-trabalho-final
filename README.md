# Projeto Final - Métodos de Programação

Este projeto consiste no trabalho final da matéria de Métodos de Programação ofertada pelo Departamento de Ciência da Computação e lecionada pelo professos Jan Correa. 

O seguinte projeto tem o objetivo de botar em prática os métodos ensinados na disciplina por meio do desenvolvimento de uma aplicação, implementada em C++ e seguindo o padrão de de codificação desenvolvido pela Google e descrito no CPPGuide.

## Funcionamento



## Descrição do aplicativo

O aplicativo permite que o usuário gerencie uma lista de compras que ele quer fazer em um estabelecimento qualquer. Supondo que o usuário queira fazer compras em um supermercado, pode começar fazendo uma lista de compras nova. O usuário pode usar uma lista de compras em branco onde pode adicionar e remover itens. Existem vários itens cadastrados e novos itens podem ser cadastrados. O sistema deve manter a consistência dos itens, verificando se diferentes nomes são na verdade o mesmo item (usando, por exemplo, o número do código de barras). O preenchimento da lista é  facilitado com um auto-completar ou outro recurso. O usuário também pode utilizar listas de compras anteriores que podem ser editadas. O aplicativo pode fazer recomendações de compras baseado nas listas anteriores ou em informações compartilhadas por outros usuários.

Uma vez que a lista de compras esta pronta, o aplicativo diz qual deve ser o preço esperado para os itens e o valor total da compra. Isto é feito baseado no valor das últimas compras do usuário bem como informações obtidas dos outros usuários do aplicativo. A seguir o aplicativo dá uma lista de supermercados que poder ser ordenado por preço, por distância ou ordenado por preço dentro de uma certa distância. O usuário vai ao supermercado para fazer as compras. No caso de um supermercado muito grande, existe a possibilidade do aplicativo dar informações da onde os produtos se encontram dentro do supermercado. Isto pode ser feito dizendo qual o número da estante, posição na estante ou algum mecanismo de localização como GPS. 

Na medida em o usuário vai pegando os itens, ele pode ver o que os outros usuários acham do produto. O usuário pode marcar o item como pego e ele entra informação sobre qual o preço do produto. Este preço pode ser colocado no aplicativo manualmente de forma fácil ou através de reconhecimento de imagens. O aplicativo diz então quanto o usuário já pagou pelo item em compras anteriores (se houver), qual o preço do produto em outros supermercados conforme compartilhado por outros usuários (se houver). Junto com estas informações deve ser mostrado se a informação é atualizada e a confiabilidade da informação. O aplicativo deve mostrar também o valor parcial da compra com os itens pegos. O usuário pode compartilhar as informações sobre preços de itens que ele tem. Pode ser compartilhada também a informação sobre em qual supermercado se obteve aquele preço. Este compartilhamento deve ter um mecanismo que incentive o compartilhamento destas informações.  

O usuário vai então efetuar a compra indo ao caixa. O aplicativo deve permitir que o usuário confira se o preço dos itens que aparecem no caixa são os mesmos que constam nas etiquetas nas estantes (ou outro lugar onde a informação sobre o preço foi dada). O aplicativo deve listar os itens que não foram comprados e deve existir a possibilidade de ver qual supermercado tem estes itens ou tem os itens com o menor preço. Esta lista pode ser editada também.  

## Desenvolvimento do código

O código acima foi organizado de forma modular desenvolvido orientado a testes, utilizando o framework GTest, de forma a garantir seu funcionamento de acordo com as especificações. Para se assegurar da cobertura que os testes tem do código, foi utilizado o verificador de cobertura gcov. Outra técnica usada para manter essa garantia foi a constante revisão do código pelo membros do grupo, da forma como foi ensinada em sala de aula.

O analisador estático escolhido para o programa foi o cppcheck e os erros apontados por esta feramenta foram resolvidos. Para detectar vazamentos de memória, foi utilizada a ferramenta valgrind.

O github foi a ferramenta de versionamento e acompanhamento do desenvolvimento orientado a testes do código.

Para faciliar o entendimento do código também foram contruídas assertivas de entrada e saída, além de comentários sobre o funcionamento das funções e sobre o motivo das escolhas na hora do desenvolvimento. Também foram explicadas, por meio de comentários, as interfaces ímplicitas e ímplicitas de cada função e quais são seus requesitos e hipóteses. Tudo isso foi aplicado utilizando as orientações ensinadas pelo professor.

A modelagem das estruturas de dados e do 'banco de dados' foram decicidas de forma unânime e em grupo, para que todos soubessem antes do desenvolvimento do código em si, o que devia ser implementado. 

## Gerenciamento da equipe

Para o gerenciamento da equipe e do projeto foram aplicados os conceitos de KanBan e do método de desenvolvimento ágil SCRUM, principalmente o conceito da sprint. Estes conceitos foram aplicados no Trello, ferramenta que se encaixou perfeitamente para esta aplicação.

A maior parte do desenvolvimento ocorreu em grupo, sendo os integrantes Jonas Prado e Felipe Ayres os maiores contribuidores.

As horas de trabalho foram estimadas pelo time de desenvolvimento.
