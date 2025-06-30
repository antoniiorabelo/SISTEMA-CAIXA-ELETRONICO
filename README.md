# Trabalho-Prático - Sistema de Gerenciamento de Vendas

Pontifícia Universidade Católica de Minas Gerais  
Instituto de Ciências Exatas e Informática  
Curso de Engenharia de Software  
Disciplinas: Algoritmos e Estruturas de Dados I / Fundamentos de Engenharia de Software  
Professores: Carlos Ribas e Laerte  
Entrega: 15/12/2024  
Valor: 10 pontos  

### Integrantes:
- [Wesley Domingos](https://github.com/WesleySDz)  
- [Nicolas Kiffer](https://github.com/nicolasksoares)  
- [Luiz Moreira](https://github.com/LuizFMoreira)  
- [Matheus Malta](https://github.com/MatheusSMalta)  

---

# Objetivo:
O objetivo do Sistema de Gerenciamento de Vendas é automatizar o processo de controle de dados para uma empresa de vendas, substituindo os métodos manuais antigos. O software foi desenvolvido em C, com foco em fornecer uma interface intuitiva para gerenciar produtos, vendedores, compradores, vendas e outras funcionalidades essenciais.

# Video de Demonstração:
[![Demonstração](https://img.youtube.com/vi/X9ePBc_Ke90/0.jpg)](https://www.youtube.com/watch?v=X9ePBc_Ke90)

---

# Backlog do Produto:

## Fotos das Reuniões:
### Reunião 1
![Reunião 1](#)  
---
### Reunião 2
![Reunião 2](#)  
---
### Reunião 3
![Reunião 3](#)  
---
### Reunião 4
![Reunião 4](#)  
---

# Sprint 1:
Na primeira imagem, mostramos o quadro Kanban da primeira sprint.  
Entendemos os requisitos do trabalho, dividimos as tarefas entre os membros da equipe, e definimos os níveis de dificuldade, tempo estimado, tamanho e prioridade para cada tarefa.

![Sprint 1](#)  

---

# Sprint 2:
Na segunda imagem, mostramos o quadro Kanban da segunda sprint.  
Iniciamos o desenvolvimento do código, com foco em funcionalidades como cadastro de produtos, cadastro de vendedores, e controle de estoque.

![Sprint 2](#)  

---

# Sprint 3:
Na terceira imagem, mostramos o quadro Kanban da terceira sprint.  
Concluímos as funcionalidades de cadastro de produtos e vendedores e começamos os testes.

![Sprint 3](#)  

---

# Sprint 4:
Na quarta imagem, mostramos o quadro Kanban da quarta sprint.  
Finalizamos as primeiras funcionalidades e começamos a revisar e aprimorar o código. Iniciamos também as funcionalidades de busca e exclusão de produtos.

![Sprint 4](#)  

---

# Sprint 5:
Na quinta imagem, mostramos o quadro Kanban da quinta sprint.  
Testamos as funções realizadas na sprint anterior e começaram os trabalhos de documentação.

![Sprint 5](#)  

---

# Sprint 6:
Na sexta imagem, mostramos o quadro Kanban da sexta sprint.  
Realizamos a documentação de todas as funções de cadastro e vendas. Além disso, realizamos revisões de código e testes.

![Sprint 6](#)  

---

# Sprint 7:
Na sétima imagem, mostramos o quadro Kanban da sétima sprint.  
Finalizamos a documentação do sistema e iniciamos o processo de integração de código.

![Sprint 7](#)  

---

# Sprint 8:
Na oitava imagem, mostramos o quadro Kanban da oitava sprint.  
Finalizamos as revisões e integração de código, e preparamos o sistema para testes finais.

![Sprint 8](#)  

---

# Sprint 9:
Na nona imagem, mostramos o quadro Kanban da nona sprint.  
O sistema passou por testes finais e todas as funcionalidades foram validadas.

![Sprint 9](#)  

---

# Sprint 10:
Na décima imagem, mostramos o quadro Kanban da décima sprint.  
Finalizamos o projeto e começamos a entrega.

![Sprint 10](#)  

---

# Lista de Funções e Parâmetros

## 1. **int main()** - Menu de opções
Função que exibe o menu principal e solicita ao usuário que escolha a funcionalidade desejada. Dependendo da escolha, redireciona para o respectivo submenu.

## 2. **void cadastrar_produto()**
Função para cadastrar um novo produto no sistema. Solicita informações como nome, código, quantidade em estoque e preço de venda.

## 3. **void alterar_produto()**
Função que permite alterar os dados de um produto já cadastrado, como nome, preço, e estoque.

## 4. **void excluir_produto()**
Função para excluir um produto do sistema. Verifica se o produto não está vinculado a nenhuma venda antes de permitir a exclusão.

## 5. **void listar_produtos()**
Função que lista todos os produtos cadastrados no sistema, mostrando seu código, nome, estoque e preço de venda.

## 6. **void cadastrar_vendedor()**
Função que permite cadastrar um vendedor no sistema. Solicita informações como nome, número, salário fixo e percentual de comissão.

## 7. **void alterar_vendedor()**
Função que permite alterar os dados de um vendedor, como nome, salário e comissão.

## 8. **void excluir_vendedor()**
Função que permite excluir um vendedor do sistema, desde que ele não esteja vinculado a nenhuma venda.

## 9. **void listar_vendedores()**
Função que lista todos os vendedores cadastrados, mostrando seu número, nome, salário, comissão e comissões acumuladas.

## 10. **void cadastrar_comprador()**
Função para cadastrar um comprador no sistema. Solicita informações como nome, CPF, e-mail e endereço.

## 11. **void alterar_comprador()**
Função que permite alterar os dados de um comprador já cadastrado.

## 12. **void excluir_comprador()**
Função que exclui um comprador do sistema, caso ele não esteja vinculado a nenhuma venda.

## 13. **void listar_compradores()**
Função que lista todos os compradores cadastrados, mostrando seus dados principais (nome, CPF, e-mail e endereço).

## 14. **void realizar_venda()**
Função que permite realizar uma venda. Solicita o código da venda, número do vendedor, CPF do comprador e itens da venda. Calcula o total e atualiza o estoque.

## 15. **void alterar_venda()**
Função que permite alterar os dados de uma venda já realizada.

## 16. **void cancelar_venda()**
Função que cancela uma venda já registrada, liberando o estoque dos itens vendidos e ajustando as comissões do vendedor.

## 17. **void listar_vendas()**
Função que lista todas as vendas realizadas, com detalhes dos produtos vendidos e o valor total.

## 18. **void emitir_nota_fiscal()**
Função que emite uma nota fiscal para uma venda, mostrando todos os detalhes da transação, incluindo produtos, valores e dados do comprador.

---

# TESTES

## Menu:
| ENTRADAS | CLASSES VÁLIDAS | RESULTADO ESPERADO | CLASSES INVÁLIDAS | RESULTADO ESPERADO |
|----------|-----------------|-------------------|--------------------|-------------------|
| Números inteiros | Opção existente | Acessar funcionalidade | Números negativos, acima de 8 e nulos | Opção inválida |

## Espaços em Branco:
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Texto             | Texto válido             | Cadastrar informação       | Espaços em branco, tabulação e nova linha | Solicitar ao usuário escrever novamente |

## Adicionar Produtos:
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Texto e inteiros | Texto alfabético ou numérico | Produto cadastrado       | Fidelidade com qualquer valor diferente de "Sim" ou "Não" | Solicitar ao usuário novamente |

---

# Relatório de Execução de Testes

## Menu de opções:
### Teste 1: Menu de opções
| ENTRADAS     | RESULTADO | APROVADOS |
|--------------|----------|-----------|
| Valor: -5    | Opção inválida | Sim |
| Valor: 0     | Opção inválida | Sim |
| Valor: 1     | Cadastrar Produto | Sim |
| Valor: 2     | Cadastrar Vendedor | Sim |
| Valor: 3     | Cadastrar Comprador | Sim |
| Valor: 4     | Realizar Venda | Sim |
| Valor: 20    | Opção inválida | Sim |

---

## Adicionar Produto:
| ENTRADAS     | RESULTADO | APROVADOS |
|--------------|----------|-----------|
| Valor: "Produto A" | Produto cadastrado | Sim |
| Valor: "Produto B" | Produto cadastrado | Sim |

---

# Conclusão

Este relatório apresenta a execução de testes para todas as funcionalidades implementadas no sistema, com validação dos resultados e verificação de que todas as entradas e saídas funcionam corretamente de acordo com as regras de negócios definidas.

**Imagens adicionais podem ser inseridas aqui**.
