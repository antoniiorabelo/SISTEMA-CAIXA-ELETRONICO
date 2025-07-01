# Trabalho-Prático - Sistema de Vendas

Pontifícia Universidade Católica de Minas Gerais  
Instituto de Ciências Exatas e Informática  
Curso de Engenharia de Software  
Disciplinas: Algoritmos e Estruturas de Dados I / Fundamentos de Engenharia de Software  
Professores: Carlos Ribas e Laerte  
Entrega: 15/12/2024  
Valor: 10 pontos  

### Integrantes:
- [Antonio Rabelo](https://github.com/antoniiorabelo)  
- [Pedro Lucas](https://github.com/pedrolsrt)  

---

# Objetivo:
O objetivo do **Sistema de Gerenciamento de Vendas** é automatizar o processo de controle de dados para uma empresa de vendas, substituindo os métodos manuais antigos. O software foi desenvolvido em C, com foco em fornecer uma interface intuitiva para gerenciar produtos, vendedores, compradores, vendas e outras funcionalidades essenciais.

# Video de Demonstração:
[![Demonstração](https://img.youtube.com/vi/X9ePBc_Ke90/0.jpg)](https://www.youtube.com/watch?v=X9ePBc_Ke90)

---

# Backlog do Produto

## Evolução do Backlog de Produto

### **Backlog Inicial do Produto**:

1. **Cadastro de Produtos**
   - Descrição: Permitir cadastro de novos produtos no sistema com informações como nome, código, preço e quantidade de estoque.
   - Responsável: Wesley
   - Prioridade: Alta
   - Sprint: Sprint 1

2. **Cadastro de Vendedores**
   - Descrição: Permitir o cadastro de vendedores com informações como número, nome, salário fixo e percentual de comissão.
   - Responsável: Matheus
   - Prioridade: Alta
   - Sprint: Sprint 1

3. **Cadastro de Compradores**
   - Descrição: Permitir o cadastro de compradores no sistema com informações como nome, CPF, e-mail e endereço.
   - Responsável: Luiz
   - Prioridade: Alta
   - Sprint: Sprint 2

4. **Realização de Vendas**
   - Descrição: Registrar uma venda no sistema, associando um vendedor, um comprador e os itens vendidos.
   - Responsável: Nicolas
   - Prioridade: Alta
   - Sprint: Sprint 2

5. **Alteração de Produtos**
   - Descrição: Permitir a alteração dos dados de um produto, como nome, preço e quantidade de estoque.
   - Responsável: Wesley
   - Prioridade: Média
   - Sprint: Sprint 3

6. **Alteração de Vendedores**
   - Descrição: Permitir a alteração dos dados de um vendedor, como nome, salário e comissão.
   - Responsável: Matheus
   - Prioridade: Média
   - Sprint: Sprint 3

7. **Relatório de Vendas**
   - Descrição: Gerar relatórios detalhados sobre todas as vendas realizadas.
   - Responsável: Luiz
   - Prioridade: Baixa
   - Sprint: Sprint 4

---

### **Evolução das Sprints:**

#### **Sprint 1 (Início)**:
1. Cadastro de Produtos  
2. Cadastro de Vendedores  

#### **Sprint 2**:
1. Cadastro de Compradores  
2. Realização de Vendas  

#### **Sprint 3**:
1. Alteração de Produtos  
2. Alteração de Vendedores  

#### **Sprint 4**:
1. Relatório de Vendas  

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

# Relatório de Execução de Testes

### **Função Testada**: Cadastrar Produto

| Entrada           | Resultado Esperado   | Resultado Obtido    | Aprovado? |
|-------------------|----------------------|---------------------|-----------|
| Código: 1001      | Produto cadastrado    | Produto cadastrado   | Sim       |
| Novo preço: 12.99 | Preço alterado       | Preço alterado      | Sim       |
| Código: 1001      | Produto excluído     | Produto excluído    | Sim       |

### **Função Testada**: Realizar Venda

| Entrada           | Resultado Esperado   | Resultado Obtido    | Aprovado? |
|-------------------|----------------------|---------------------|-----------|
| Quantidade: 5     | Item adicionado      | Item adicionado     | Sim       |
| Código: 5001      | Venda registrada     | Venda registrada    | Sim       |

---

Este é o **relatório completo de testes** para as funcionalidades de **Produto**, **Vendedor**, **Comprador**, e **Venda** do sistema de gerenciamento de vendas. Ele inclui os **casos de teste** detalhados, o **planejamento dos testes** com entradas, resultados esperados e as saídas obtidas durante a execução.


