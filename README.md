# Trabalho-Prático - VendaFácil

Pontifícia Universidade Católica de Minas Gerais 

Instituto de Ciências Exatas e Informática  

Curso de Engenharia de Software  

Disciplinas: Algoritmos e Estruturas de Dados I / Fundamentos de Engenharia de Software 

Professores: Carlos Ribas e Laerte       Entrega: 02/07/2025  

Valor: 10 pontos  

### Integrantes:

- [Antonio Rabelo](https://github.com/antoniiorabelo)  
- [Pedro Lucas](https://github.com/pedrolsrt)  


## Objetivo do Projeto VendaFácil

O **VendaFácil** é um sistema de gerenciamento de vendas criado para simplificar e automatizar processos como cadastro de produtos, vendedores e compradores, controle de estoque e comissões. Com uma interface intuitiva, o sistema visa otimizar o tempo das equipes de vendas e melhorar a gestão de vendas, permitindo maior eficiência e precisão nas operações comerciais.


# Video de Demonstração:
[![Demonstração](https://img.youtube.com/vi/X9ePBc_Ke90/0.jpg)]([[https://www.youtube.com/watch?v=X9ePBc_Ke90](https://youtu.be/ZhgRpyunxF8)](https://youtu.be/fTxO6ZXFi2M?si=KlIuAzkQWGqqwj9V))

---

# Backlog do Produto

## Fotos das reuniões:

# Reunião 1
![Captura de tela 2025-06-25 221757](https://github.com/user-attachments/assets/b93add7d-9d62-49f4-8b64-0bf333ee8b45)

# Reunião 2
![Captura de tela 2025-06-25 223219](https://github.com/user-attachments/assets/ea5bb438-8b49-42c7-b788-4022813fa6da)

# Reunião 3 
![Captura de tela 2025-06-30 194312](https://github.com/user-attachments/assets/c023e0c6-7cf8-458e-a02c-ada29bdc511b)

# Reunião 4
![Captura de tela 2025-06-30 194312](https://github.com/user-attachments/assets/7bdbbb2b-b3f7-4b90-a20b-525a96051b8b)



# Documentação do Sistema de Vendas - **VendaFácil**

## Objetivo

O **VendaFácil** é um sistema de gerenciamento de vendas desenvolvido para otimizar e automatizar processos de vendas, incluindo o cadastro de produtos, vendedores e compradores, a realização de vendas, o cálculo de comissões, a emissão de notas fiscais, e a gestão de estoque. O sistema oferece uma interface intuitiva para que as equipes de vendas possam realizar suas tarefas com maior eficiência e sem erros manuais.

---

# Backlog do Produto

# Sprint 1: Planejamento Inicial
Na primeira sprint, realizamos a análise de requisitos e divisão de tarefas entre os membros da equipe. Definimos níveis de dificuldade, tempo estimado, tamanho e prioridade para cada tarefa.

![Captura de tela 2025-06-24 165148](https://github.com/user-attachments/assets/b2f16a28-4676-46da-881b-a10a9ac4b383)



---

# Sprint 2: Desenvolvimento das Funcionalidades Básicas
Iniciamos o desenvolvimento do código com as funcionalidades principais:
- Cadastro de produtos
- Cadastro de vendedores
- Realização de vendas básicas

![Captura de tela 2025-06-25 221757](https://github.com/user-attachments/assets/029235e1-ca50-45da-b1b1-89f5636b61ce)


---

# Sprint 3: Finalização das Funcionalidades Básicas
Completamos as funcionalidades iniciais e iniciamos os primeiros testes:
- Cadastro de compradores
- Sistema de estoque
- Cálculo de comissões

![Captura de tela 2025-07-01 001002](https://github.com/user-attachments/assets/e08323b1-d23a-4b3b-bee3-d0803904d2b7)


---

# Sprint 4: Desenvolvimento de Funcionalidades Avançadas
Iniciamos as funcionalidades mais complexas:
- Nota fiscal
- Relatórios de vendas
- Cancelamento de vendas

![image](https://github.com/user-attachments/assets/f4dc400c-161f-45eb-918d-4b2e36f6dea8)


---

# Sprint 5: Testes das Funcionalidades Avançadas
Realizamos testes abrangentes nas novas funcionalidades:
- Testes unitários
- Testes de integração
- Validação de regras de negócio

![image](https://github.com/user-attachments/assets/1f034b6a-f3c0-4b2e-b926-f94248974a75)


---

# Sprint 6: Documentação Inicial
Iniciamos o processo de documentação:
- Documentação de código
- Manual do usuário básico
- Revisão dos testes realizados

![image](https://github.com/user-attachments/assets/226776da-4954-48d6-a02a-ffd09eaa3651)


---

# Sprint 7: Refinamento e Otimização
Focamos em melhorias e ajustes:
- Otimização de performance
- Melhoria na interface
- Correção de bugs identificados

![image](https://github.com/user-attachments/assets/fe721120-2a21-4b62-97b8-8802b65115df)


---

# Sprint 8: Desenvolvimento do Menu Principal
Implementamos e testamos o sistema de menus:
- Menu principal
- Submenus
- Navegação entre funcionalidades

![image](https://github.com/user-attachments/assets/94f4bdd7-d057-47c9-8888-b2b396f37cc8)


---

# Sprint 9: Finalização da Documentação
Completamos toda a documentação:
- Documentação técnica
- Manual completo do usuário
- Guia de instalação

![image](https://github.com/user-attachments/assets/51c4e093-c4c5-4e94-9670-21e239df60bf)


---

# Sprint 10: Integração Final
Realizamos a integração completa do sistema:
- Testes finais
- Ajustes de integração
- Preparação para entrega
- Testes do codigo por inteeiro

![image](https://github.com/user-attachments/assets/360a6793-3c2d-4271-901e-8c5f4b4b3fe4)


---

#  Funções Auxiliares

| Função | O que faz |
|---|---|
| `int produto_existe(int codigo)` | Verifica se um produto com o código informado existe no vetor de produtos. Retorna o índice ou -1. |
| `int vendedor_existe(int numero)` | Verifica se um vendedor com o número informado existe no vetor de vendedores. Retorna o índice ou -1. |
| `int comprador_existe(char *cpf)` | Verifica se um comprador com o CPF informado existe no vetor de compradores. Retorna o índice ou -1. |
| `int venda_existe(int codigo)` | Verifica se uma venda com o código informado já existe. Retorna o índice ou -1. |
| `void limpar_buffer()` | Limpa o buffer do `stdin` após uma leitura para evitar problemas de entrada de dados. |
| `int validar_cep(char *cep)` | Valida se o CEP contém exatamente 8 dígitos no formato 12345678 ou 12345-678. Retorna 1 se válido, 0 se inválido. |
| `void formatar_cep(char *cep)` | Formata o CEP para o formato 12345-678. |

---

#  Funções para Produtos

| Função | O que faz |
|---|---|
| `void cadastrar_produto()` | Cadastra um novo produto, pedindo nome, código, estoque e preço. Verifica se o código já existe. |
| `void alterar_produto()` | Altera dados de um produto existente. Campos podem ser mantidos deixando em branco. |
| `void excluir_produto()` | Exclui um produto se ele não estiver vinculado a nenhuma venda. |
| `void listar_produtos()` | Lista todos os produtos cadastrados. |

---

#  Funções para Vendedores

| Função | O que faz |
|---|---|
| `void cadastrar_vendedor()` | Cadastra um novo vendedor, com nome, número, salário fixo e percentual de comissão. |
| `void alterar_vendedor()` | Altera nome e salário fixo de um vendedor. Percentual de comissão é mantido. |
| `void excluir_vendedor()` | Exclui um vendedor se ele não estiver vinculado a vendas. |
| `void listar_vendedores()` | Lista todos os vendedores com dados completos e comissões acumuladas. |

---

#  Funções para Compradores

| Função | O que faz |
|---|---|
| `void cadastrar_comprador()` | Cadastra um comprador, incluindo validação e formatação de CEP. |
| `void alterar_comprador()` | Altera dados do comprador e do endereço. |
| `void excluir_comprador()` | Exclui um comprador se ele não estiver vinculado a vendas. |
| `void listar_compradores()` | Lista todos os compradores com endereço completo. |

---

#  Funções para Vendas

| Função | O que faz |
|---|---|
| `void realizar_venda()` | Registra uma nova venda: escolhe vendedor, comprador e produtos, atualiza estoque e comissão. |
| `void alterar_venda()` | Exibe os dados de uma venda existente e orienta cancelar e recriar se necessário. |
| `void cancelar_venda()` | Cancela uma venda, devolve produtos ao estoque e retira comissão do vendedor. |
| `void listar_vendas()` | Lista todas as vendas com detalhes dos itens. |
| `void emitir_nota_fiscal()` | Emite uma nota fiscal detalhada, com cálculo de frete e resumo dos produtos vendidos. |

---

#  Menus de Navegação

| Função | O que faz |
|---|---|
| `void menu_produtos()` | Menu para cadastrar, alterar, excluir e listar produtos. |
| `void menu_vendedores()` | Menu para operações com vendedores. |
| `void menu_compradores()` | Menu para operações com compradores. |
| `void menu_vendas()` | Menu para operações com vendas e nota fiscal. |
| `void menu_principal()` | Menu principal do sistema para acessar todos os outros. |

---

#  Função Principal

| Função | O que faz |
|---|---|
| `int main()` | Inicia o programa, chamando `menu_principal()`. |


---




## Funcionalidades do Software

### 1. **Cadastro de Produtos**
- **Descrição**: Permite o cadastro de novos produtos, informando nome, código, quantidade em estoque e preço de venda.
  
### 2. **Cadastro de Vendedores**
- **Descrição**: Registra informações de vendedores, como número, nome, salário fixo e percentual de comissão.

### 3. **Cadastro de Compradores**
- **Descrição**: Realiza o cadastro de compradores no sistema, incluindo dados como nome, CPF, e-mail e endereço.

### 4. **Realização de Vendas**
- **Descrição**: Permite realizar uma venda, associando vendedor, comprador e os itens vendidos. Atualiza o estoque automaticamente e gera o valor total da venda.

### 5. **Alteração de Produtos**
- **Descrição**: Permite a modificação de dados de um produto já cadastrado no sistema, como nome, preço e quantidade de estoque.

### 6. **Alteração de Vendedores**
- **Descrição**: Permite editar informações de vendedores cadastrados, como nome, salário e comissão.

### 7. **Relatório de Vendas**
- **Descrição**: Gera relatórios completos sobre as vendas realizadas, detalhando os produtos vendidos, vendedores e compradores.

---

# Planejamento dos Casos de Teste

A seguir, temos o **planejamento dos casos de teste**, com entradas, procedimentos e resultados esperados.



## Casos de Teste para Produtos

# Casos de Teste para Menus

## 1. **Menu Principal**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS               | RESULTADO ESPERADO            |
|------------------|-----------------------------|------------------------------|---------------------------------|-------------------------------|
| Opção: 1         | Inteiro entre 0-4           | Abrir menu de produtos       | Opção < 0 ou > 4                | Exibir "Opção inválida"       |
| Opção: 2         | Inteiro entre 0-4           | Abrir menu de vendedores     | Caractere não numérico          | Exibir "Opção inválida"       |
| Opção: 0         | Inteiro entre 0-4           | Encerrar sistema             | -                               | -                             |

## 2. **Menu de Produtos**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS               | RESULTADO ESPERADO            |
|------------------|-----------------------------|------------------------------|---------------------------------|-------------------------------|
| Opção: 1         | Inteiro entre 0-4           | Chamar `cadastrar_produto()` | Opção < 0 ou > 4                | Exibir "Opção inválida"       |
| Opção: 4         | Inteiro entre 0-4           | Chamar `listar_produtos()`   | -                               | -                             |
| Opção: 0         | Inteiro entre 0-4           | Voltar ao menu principal     | -                               | -                             |

## 3. **Menu de Vendedores**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS               | RESULTADO ESPERADO            |
|------------------|-----------------------------|------------------------------|---------------------------------|-------------------------------|
| Opção: 2         | Inteiro entre 0-4           | Chamar `alterar_vendedor()`  | Valor float (ex: 1.5)           | Exibir "Opção inválida"       |
| Opção: 3         | Inteiro entre 0-4           | Chamar `excluir_vendedor()`  | -                               | -                             |

## 4. **Menu de Compradores**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS               | RESULTADO ESPERADO            |
|------------------|-----------------------------|------------------------------|---------------------------------|-------------------------------|
| Opção: 1         | Inteiro entre 0-4           | Chamar `cadastrar_comprador()`| String (ex: "abc")              | Exibir "Opção inválida"       |
| Opção: 4         | Inteiro entre 0-4           | Chamar `listar_compradores()` | -                               | -                             |

## 5. **Menu de Vendas**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS               | RESULTADO ESPERADO            |
|------------------|-----------------------------|------------------------------|---------------------------------|-------------------------------|
| Opção: 5         | Inteiro entre 0-5           | Chamar `emitir_nota_fiscal()`| Opção > 5                       | Exibir "Opção inválida"       |
| Opção: 0         | Inteiro entre 0-5           | Voltar ao menu principal     | -                               | -                             |

---

# Relatório de Execução de Testes - Menus

### **Menu Testado**: **Principal**

| Entrada          | Resultado Esperado     | Resultado Obtido     | Aprovado? |
|------------------|------------------------|----------------------|-----------|
| Opção: 1         | Abrir menu de produtos | Menu de produtos aberto | Sim      |
| Opção: 9         | Exibir "Opção inválida"| "Opção inválida" exibida | Sim      |

---

### **Menu Testado**: **Produtos**

| Entrada          | Resultado Esperado     | Resultado Obtido     | Aprovado? |
|------------------|------------------------|----------------------|-----------|
| Opção: 4         | Listar produtos        | Lista exibida        | Sim       |

---

### **Menu Testado**: **Vendas**

| Entrada          | Resultado Esperado     | Resultado Obtido     | Aprovado? |
|------------------|------------------------|----------------------|-----------|
| Opção: 5         | Emitir nota fiscal     | Função chamada       | Sim       |

---

### **Menu Testado**: **Compradores**

| Entrada          | Resultado Esperado     | Resultado Obtido     | Aprovado? |
|------------------|------------------------|----------------------|-----------|
| Opção: "a"       | Exibir "Opção inválida"| "Opção inválida" exibida | Sim      |

---

Esta documentação contém os **casos de teste para os menus**, com entradas válidas, resultados esperados, entradas inválidas e os resultados esperados para essas entradas. Também inclui o **relatório de execução de testes**, mostrando os testes realizados, resultados obtidos e aprovação de cada funcionalidade do sistema.

Se precisar de mais alguma alteração ou ajuste, estou à disposição!


### 1. **Cadastrar Produto**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS              | RESULTADO ESPERADO           |
|------------------|-----------------------------|------------------------------|--------------------------------|------------------------------|
| Nome: "Produto A" | String não vazia            | Produto cadastrado com sucesso| Nome vazio                    | Exibir mensagem de erro      |
| Código: 1001      | Inteiro único               | Produto cadastrado com sucesso| Código já existente           | Exibir mensagem de erro      |
| Quantidade: 50    | Inteiro positivo            | Produto cadastrado com sucesso| Quantidade negativa           | Exibir mensagem de erro      |
| Preço: 10.99      | Float positivo              | Produto cadastrado com sucesso| Preço negativo                | Exibir mensagem de erro      |

### 2. **Alterar Produto**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS              | RESULTADO ESPERADO           |
|------------------|-----------------------------|------------------------------|--------------------------------|------------------------------|
| Código: 1001     | Código existente            | Produto encontrado           | Código inexistente            | Exibir mensagem de erro      |
| Novo nome: "Produto B" | String não vazia        | Nome alterado                | Nome vazio                    | Manter nome original         |
| Nova quantidade: 60   | Inteiro positivo        | Quantidade alterada          | Quantidade negativa           | Manter quantidade original   |
| Novo preço: 12.99     | Float positivo           | Preço alterado               | Preço negativo                | Manter preço original        |

### 3. **Excluir Produto**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS              | RESULTADO ESPERADO           |
|------------------|-----------------------------|------------------------------|--------------------------------|------------------------------|
| Código: 1001     | Código existente            | Produto excluído             | Código inexistente            | Exibir mensagem de erro      |
| Produto vinculado a venda | -                   | Exibir mensagem de erro      | -                              | -                            |

### 4. **Listar Produtos**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS              | RESULTADO ESPERADO           |
|------------------|-----------------------------|------------------------------|--------------------------------|------------------------------|
| -                | Lista de produtos cadastrados| Exibir lista formatada       | Lista vazia                   | Exibir mensagem "Nenhum produto cadastrado" |

---

## Casos de Teste para Vendedores

### 1. **Cadastrar Vendedor**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS              | RESULTADO ESPERADO           |
|------------------|-----------------------------|------------------------------|--------------------------------|------------------------------|
| Nome: "Vendedor X"  | String não vazia           | Vendedor cadastrado          | Nome vazio                    | Exibir mensagem de erro      |
| Número: 101         | Inteiro único              | Vendedor cadastrado          | Número já existente           | Exibir mensagem de erro      |
| Salário: 1500.00     | Float positivo             | Vendedor cadastrado          | Salário negativo              | Exibir mensagem de erro      |
| Comissão: 5.0        | Float entre 0 e 100        | Vendedor cadastrado          | Comissão inválida             | Exibir mensagem de erro      |

### 2. **Alterar Vendedor**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS              | RESULTADO ESPERADO           |
|------------------|-----------------------------|------------------------------|--------------------------------|------------------------------|
| Número: 101     | Número existente            | Vendedor encontrado          | Número inexistente            | Exibir mensagem de erro      |
| Novo nome: "Vendedor Y"  | String não vazia       | Nome alterado                | Nome vazio                    | Manter nome original         |
| Novo salário: 1600.00     | Float positivo         | Salário alterado             | Salário negativo              | Manter salário original      |

### 3. **Excluir Vendedor**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS              | RESULTADO ESPERADO           |
|------------------|-----------------------------|------------------------------|--------------------------------|------------------------------|
| Número: 101     | Número existente            | Vendedor excluído            | Número inexistente            | Exibir mensagem de erro      |
| Vendedor vinculado a venda | -                   | Exibir mensagem de erro      | -                              | -                            |

### 4. **Listar Vendedores**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS              | RESULTADO ESPERADO           |
|------------------|-----------------------------|------------------------------|--------------------------------|------------------------------|
| -                | Lista de vendedores cadastrados| Exibir lista formatada       | Lista vazia                   | Exibir mensagem "Nenhum vendedor cadastrado" |

---

## Casos de Teste para Compradores

### 1. **Cadastrar Comprador**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS              | RESULTADO ESPERADO           |
|------------------|-----------------------------|------------------------------|--------------------------------|------------------------------|
| Nome: "Comprador Z"  | String não vazia           | Comprador cadastrado         | Nome vazio                    | Exibir mensagem de erro      |
| CPF: "123.456.789-00" | CPF válido                 | Comprador cadastrado         | CPF inválido ou já existente   | Exibir mensagem de erro      |
| CEP: "12345-678"     | CEP válido                 | Comprador cadastrado         | CEP inválido                  | Exibir mensagem de erro      |

### 2. **Alterar Comprador**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS              | RESULTADO ESPERADO           |
|------------------|-----------------------------|------------------------------|--------------------------------|------------------------------|
| CPF: "123.456.789-00" | CPF existente             | Comprador encontrado         | CPF inexistente               | Exibir mensagem de erro      |
| Novo email: "novo@email.com"  | Email válido       | Email alterado               | Email inválido                | Manter email original        |

### 3. **Excluir Comprador**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS              | RESULTADO ESPERADO           |
|------------------|-----------------------------|------------------------------|--------------------------------|------------------------------|
| CPF: "123.456.789-00" | CPF existente             | Comprador excluído           | CPF inexistente               | Exibir mensagem de erro      |
| Comprador vinculado a venda | -                   | Exibir mensagem de erro      | -                              | -                            |

### 4. **Listar Compradores**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS              | RESULTADO ESPERADO           |
|------------------|-----------------------------|------------------------------|--------------------------------|------------------------------|
| -                | Lista de compradores cadastrados | Exibir lista formatada       | Lista vazia                   | Exibir mensagem "Nenhum comprador cadastrado" |

---

## Casos de Teste para Vendas

### 1. **Realizar Venda**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS              | RESULTADO ESPERADO           |
|------------------|-----------------------------|------------------------------|--------------------------------|------------------------------|
| Código: 5001     | Inteiro único               | Venda iniciada               | Código já existente           | Exibir mensagem de erro      |
| Vendedor: 101    | Número existente            | Venda registrada             | Vendedor inexistente          | Exibir mensagem de erro      |
| Produto: 1001    | Código existente            | Item adicionado               | Produto inexistente           | Exibir mensagem de erro      |
| Quantidade: 5    | Inteiro positivo            | Item adicionado               | Quantidade > estoque          | Exibir mensagem de erro      |

### 2. **Cancelar Venda**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS              | RESULTADO ESPERADO           |
|------------------|-----------------------------|------------------------------|--------------------------------|------------------------------|
| Código: 5001     | Código existente            | Venda cancelada              | Código inexistente            | Exibir mensagem de erro      |

### 3. **Emitir Nota Fiscal**

| ENTRADAS         | CLASSES VÁLIDAS             | RESULTADO ESPERADO           | CLASSES INVÁLIDAS              | RESULTADO ESPERADO           |
|------------------|-----------------------------|------------------------------|--------------------------------|------------------------------|
| Código: 5001     | Código existente            | Nota fiscal emitida          | Código inexistente            | Exibir mensagem de erro      |

---

Este é o **relatório completo de testes** para as funcionalidades de **Produto**, **Vendedor**, **Comprador**, e **Venda** do sistema de gerenciamento de vendas. Ele inclui os **casos de teste** detalhados, o **planejamento dos testes** com entradas, resultados esperados e as saídas obtidas durante a execução.
