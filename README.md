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

## Menu:
| ENTRADAS        | CLASSES VÁLIDAS           | RESULTADO ESPERADO           | CLASSES INVÁLIDAS                  | RESULTADO ESPERADO |
|-----------------|---------------------------|------------------------------|-----------------------------------|--------------------|
| Números inteiros| Opção existente           | Acessar funcionalidade       | Números negativos, acima de 8 e nulos | Opção inválida |

## Espaços em Branco:
| ENTRADAS           | CLASSES VÁLIDAS            | RESULTADO ESPERADO           | CLASSES INVÁLIDAS                 | RESULTADO ESPERADO       |
|--------------------|----------------------------|------------------------------|-----------------------------------|--------------------------|
| Texto              | Texto válido               | Cadastrar informação         | Espaços brancos, tabulação e nova linha | Solicitar ao usuário escrever novamente |

## Adicionar Produtos:
| ENTRADAS         | CLASSES VÁLIDAS            | RESULTADO ESPERADO           | CLASSES INVÁLIDAS                 | RESULTADO ESPERADO   |
|------------------|----------------------------|------------------------------|-----------------------------------|----------------------|
| Texto válido     | Texto alfabético ou numérico | Produto cadastrado           | Nome vazio ou caracteres inválidos | Solicitar novamente |

## Realizar Vendas:
| ENTRADAS         | CLASSES VÁLIDAS            | RESULTADO ESPERADO           | CLASSES INVÁLIDAS                 | RESULTADO ESPERADO   |
|------------------|----------------------------|------------------------------|-----------------------------------|----------------------|
| Código da venda, número do vendedor, CPF do comprador | Venda registrada com sucesso | Vendas criadas e estoque atualizado | Dados incorretos | Não realizar a venda |

---

# Relatório de Execução de Testes

### **Menu de opções:**
#### Teste 1: Menu de opções
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

## **Adicionar Produtos**:
#### Teste 1: Verificar Adição de Produto
| ENTRADAS     | RESULTADO | APROVADOS |
|--------------|----------|-----------|
| Valor: "Produto A" | Produto cadastrado | Sim |
| Valor: "Produto B" | Produto cadastrado | Sim |

---

## **Testes de Venda**:
#### Teste 1: **Testar Realizar Venda**
```c
static MunitResult test_realizar_venda(const MunitParameter params[], void* fixture) {
    // Configura ambiente de teste
    num_produtos = 1;
    produtos[0].codigo = 1001;
    produtos[0].quantidade_estoque = 10;
    
    num_vendedores = 1;
    vendedores[0].numero = 500;
    
    num_compradores = 1;
    strcpy(compradores[0].cpf, "12345678901");
    
    // Simula venda
    num_vendas = 0;
    vendas[0].codigo = 1;
    vendas[0].codigo_vendedor = 500;
    strcpy(vendas[0].cpf_comprador, "12345678901");
    vendas[0].itens[0].codigo_produto = 1001;
    vendas[0].itens[0].quantidade_vendida = 2;
    
    // Verificações
    munit_assert_int(num_vendas, ==, 1);
    munit_assert_int(produtos[0].quantidade_estoque, ==, 8);
    
    return MUNIT_OK;
}
