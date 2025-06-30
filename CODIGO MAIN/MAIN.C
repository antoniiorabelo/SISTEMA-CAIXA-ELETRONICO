#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUTOS 100
#define MAX_VENDEDORES 50
#define MAX_COMPRADORES 100
#define MAX_VENDAS 200
#define MAX_ITENS_VENDA 20

typedef struct {
    char rua[50];
    char bairro[30];
    char cidade[30];
    char estado[3];
    char cep[10]; // Formato: "12345-678"
} Endereco;

typedef struct {
    char nome[50];
    char cpf[15];
    char email[50];
    Endereco endereco;
} Comprador;

typedef struct {
    char nome[50];
    int numero;
    float salario_fixo;
    float comissoes;
    float percentual_comissao;
} Vendedor;

typedef struct {
    char nome[50];
    int codigo;
    int quantidade_estoque;
    float preco_venda;
} Produto;

typedef struct {
    char nome_produto[50];
    int codigo_produto;
    int quantidade_vendida;
    float preco_unitario;
    float preco_total;
} ItemVenda;

typedef struct {
    int codigo;
    int codigo_vendedor;
    char cpf_comprador[15];
    ItemVenda itens[MAX_ITENS_VENDA];
    int num_itens;
    float total_venda;
} Venda;

Produto produtos[MAX_PRODUTOS];
int num_produtos = 0;

Vendedor vendedores[MAX_VENDEDORES];
int num_vendedores = 0;

Comprador compradores[MAX_COMPRADORES];
int num_compradores = 0;

Venda vendas[MAX_VENDAS];
int num_vendas = 0;

// Funções auxiliares
int produto_existe(int codigo) {
    for (int i = 0; i < num_produtos; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

int vendedor_existe(int numero) {
    for (int i = 0; i < num_vendedores; i++) {
        if (vendedores[i].numero == numero) {
            return i;
        }
    }
    return -1;
}

int comprador_existe(char *cpf) {
    for (int i = 0; i < num_compradores; i++) {
        if (strcmp(compradores[i].cpf, cpf) == 0) {
            return i;
        }
    }
    return -1;
}

int venda_existe(int codigo) {
    for (int i = 0; i < num_vendas; i++) {
        if (vendas[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int validar_cep(char *cep) {
    int digitos = 0;
    int hifen_pos = -1;

    for (int i = 0; cep[i] != '\0'; i++) {
        if (isdigit(cep[i])) {
            digitos++;
        } else if (cep[i] == '-') {
            if (hifen_pos != -1 || i != 5) {
                return 0;
            }
            hifen_pos = i;
        } else {
            return 0;
        }
    }

    return (digitos == 8);
}

void formatar_cep(char *cep) {
    char cep_limpo[9];
    int j = 0;

    for (int i = 0; cep[i] != '\0' && j < 8; i++) {
        if (isdigit(cep[i])) {
            cep_limpo[j++] = cep[i];
        }
    }
    cep_limpo[j] = '\0';

    if (strlen(cep_limpo) == 8) {
        sprintf(cep, "%.5s-%.3s", cep_limpo, cep_limpo + 5);
    }
}

// Funções para Produtos
void cadastrar_produto() {
    if (num_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto p;

    printf("\n--- Cadastro de Produto ---\n");
    printf("Nome: ");
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';

    printf("Codigo: ");
    scanf("%d", &p.codigo);

    if (produto_existe(p.codigo) != -1) {
        printf("Erro: Codigo de produto ja existe!\n");
        return;
    }

    printf("Quantidade em estoque: ");
    scanf("%d", &p.quantidade_estoque);

    printf("Preco de venda: ");
    scanf("%f", &p.preco_venda);

    produtos[num_produtos++] = p;
    printf("Produto cadastrado com sucesso!\n");
}

void alterar_produto() {
    int codigo;
    printf("\n--- Alterar Produto ---\n");
    printf("Codigo do produto a ser alterado: ");
    scanf("%d", &codigo);
    limpar_buffer();

    int idx = produto_existe(codigo);
    if (idx == -1) {
        printf("Produto nao encontrado!\n");
        return;
    }

    printf("\nDados atuais do produto:\n");
    printf("Nome: %s\n", produtos[idx].nome);
    printf("Codigo: %d\n", produtos[idx].codigo);
    printf("Quantidade em estoque: %d\n", produtos[idx].quantidade_estoque);
    printf("Preco de venda: %.2f\n", produtos[idx].preco_venda);

    printf("\nNovos dados (deixe em branco para manter o valor atual):\n");

    char novo_nome[50];
    printf("Nome [%s]: ", produtos[idx].nome);
    fgets(novo_nome, 50, stdin);
    if (strlen(novo_nome) > 1) {
        novo_nome[strcspn(novo_nome, "\n")] = '\0';
        strcpy(produtos[idx].nome, novo_nome);
    }

    char novo_estoque[20];
    printf("Quantidade em estoque [%d]: ", produtos[idx].quantidade_estoque);
    fgets(novo_estoque, 20, stdin);
    if (strlen(novo_estoque) > 1) {
        produtos[idx].quantidade_estoque = atoi(novo_estoque);
    }

    char novo_preco[20];
    printf("Preco de venda [%.2f]: ", produtos[idx].preco_venda);
    fgets(novo_preco, 20, stdin);
    if (strlen(novo_preco) > 1) {
        produtos[idx].preco_venda = atof(novo_preco);
    }

    printf("Produto alterado com sucesso!\n");
}

void excluir_produto() {
    int codigo;
    printf("\n--- Excluir Produto ---\n");
    printf("Codigo do produto a ser excluido: ");
    scanf("%d", &codigo);

    int idx = produto_existe(codigo);
    if (idx == -1) {
        printf("Produto nao encontrado!\n");
        return;
    }

    for (int i = 0; i < num_vendas; i++) {
        for (int j = 0; j < vendas[i].num_itens; j++) {
            if (vendas[i].itens[j].codigo_produto == codigo) {
                printf("Nao e possivel excluir: produto esta vinculado a uma ou mais vendas!\n");
                return;
            }
        }
    }

    for (int i = idx; i < num_produtos - 1; i++) {
        produtos[i] = produtos[i + 1];
    }
    num_produtos--;

    printf("Produto excluido com sucesso!\n");
}

void listar_produtos() {
    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < num_produtos; i++) {
        printf("Codigo: %d | Nome: %s | Estoque: %d | Preco: R$ %.2f\n",
               produtos[i].codigo, produtos[i].nome,
               produtos[i].quantidade_estoque, produtos[i].preco_venda);
    }
}

// Funções para Vendedores
void cadastrar_vendedor() {
    if (num_vendedores >= MAX_VENDEDORES) {
        printf("Limite de vendedores atingido!\n");
        return;
    }

    Vendedor v;

    printf("\n--- Cadastro de Vendedor ---\n");
    printf("Nome: ");
    fgets(v.nome, 50, stdin);
    v.nome[strcspn(v.nome, "\n")] = '\0';

    printf("Numero: ");
    scanf("%d", &v.numero);

    if (vendedor_existe(v.numero) != -1) {
        printf("Erro: Numero de vendedor ja existe!\n");
        return;
    }

    printf("Salario fixo: ");
    scanf("%f", &v.salario_fixo);

    printf("Percentual de comissao (%%): ");
    scanf("%f", &v.percentual_comissao);

    v.comissoes = 0;
    vendedores[num_vendedores++] = v;
    printf("Vendedor cadastrado com sucesso!\n");
}

void alterar_vendedor() {
    int numero;
    printf("\n--- Alterar Vendedor ---\n");
    printf("Numero do vendedor a ser alterado: ");
    scanf("%d", &numero);
    limpar_buffer();

    int idx = vendedor_existe(numero);
    if (idx == -1) {
        printf("Vendedor nao encontrado!\n");
        return;
    }

    printf("\nDados atuais do vendedor:\n");
    printf("Nome: %s\n", vendedores[idx].nome);
    printf("Numero: %d\n", vendedores[idx].numero);
    printf("Salario fixo: %.2f\n", vendedores[idx].salario_fixo);
    printf("Percentual de comissao: %.2f%%\n", vendedores[idx].percentual_comissao);

    printf("\nNovos dados (deixe em branco para manter o valor atual):\n");

    char novo_nome[50];
    printf("Nome [%s]: ", vendedores[idx].nome);
    fgets(novo_nome, 50, stdin);
    if (strlen(novo_nome) > 1) {
        novo_nome[strcspn(novo_nome, "\n")] = '\0';
        strcpy(vendedores[idx].nome, novo_nome);
    }

    char novo_salario[20];
    printf("Salario fixo [%.2f]: ", vendedores[idx].salario_fixo);
    fgets(novo_salario, 20, stdin);
    if (strlen(novo_salario) > 1) {
        vendedores[idx].salario_fixo = atof(novo_salario);
    }

    printf("Percentual de comissao (FIXO): %.2f%%\n", vendedores[idx].percentual_comissao);

    printf("Vendedor alterado com sucesso!\n");
}

void excluir_vendedor() {
    int numero;
    printf("\n--- Excluir Vendedor ---\n");
    printf("Numero do vendedor a ser excluido: ");
    scanf("%d", &numero);

    int idx = vendedor_existe(numero);
    if (idx == -1) {
        printf("Vendedor nao encontrado!\n");
        return;
    }

    for (int i = 0; i < num_vendas; i++) {
        if (vendas[i].codigo_vendedor == numero) {
            printf("Nao e possivel excluir: vendedor esta vinculado a uma ou mais vendas!\n");
            return;
        }
    }

    for (int i = idx; i < num_vendedores - 1; i++) {
        vendedores[i] = vendedores[i + 1];
    }
    num_vendedores--;

    printf("Vendedor excluido com sucesso!\n");
}

void listar_vendedores() {
    printf("\n--- Lista de Vendedores ---\n");
    for (int i = 0; i < num_vendedores; i++) {
        printf("Numero: %d | Nome: %s | Salario: R$ %.2f | Comissao: %.2f%% | Comissoes Acumuladas: R$ %.2f\n",
               vendedores[i].numero, vendedores[i].nome,
               vendedores[i].salario_fixo, vendedores[i].percentual_comissao,
               vendedores[i].comissoes);
    }
}

// Funções para Compradores
void cadastrar_comprador() {
    if (num_compradores >= MAX_COMPRADORES) {
        printf("Limite de compradores atingido!\n");
        return;
    }

    Comprador c;

    printf("\n--- Cadastro de Comprador ---\n");
    printf("Nome: ");
    fgets(c.nome, 50, stdin);
    c.nome[strcspn(c.nome, "\n")] = '\0';

    printf("CPF: ");
    fgets(c.cpf, 15, stdin);
    c.cpf[strcspn(c.cpf, "\n")] = '\0';

    if (comprador_existe(c.cpf) != -1) {
        printf("Erro: CPF ja cadastrado!\n");
        return;
    }

    printf("Email: ");
    fgets(c.email, 50, stdin);
    c.email[strcspn(c.email, "\n")] = '\0';

    printf("--- Endereco ---\n");
    printf("Rua: ");
    fgets(c.endereco.rua, 50, stdin);
    c.endereco.rua[strcspn(c.endereco.rua, "\n")] = '\0';

    printf("Bairro: ");
    fgets(c.endereco.bairro, 30, stdin);
    c.endereco.bairro[strcspn(c.endereco.bairro, "\n")] = '\0';

    printf("Cidade: ");
    fgets(c.endereco.cidade, 30, stdin);
    c.endereco.cidade[strcspn(c.endereco.cidade, "\n")] = '\0';

    printf("Estado (sigla): ");
    fgets(c.endereco.estado, 3, stdin);
    c.endereco.estado[strcspn(c.endereco.estado, "\n")] = '\0';
    limpar_buffer();

    int cep_valido = 0;
    do {
        printf("CEP (formato: 12345-678 ou 12345678): ");
        fgets(c.endereco.cep, 10, stdin);
        c.endereco.cep[strcspn(c.endereco.cep, "\n")] = '\0';

        char *p = c.endereco.cep;
        while (*p) {
            if (isspace(*p)) {
                memmove(p, p+1, strlen(p));
            } else {
                p++;
            }
        }

        cep_valido = validar_cep(c.endereco.cep);

        if (cep_valido) {
            formatar_cep(c.endereco.cep);
        } else {
            printf("CEP invalido! Deve conter exatamente 8 digitos no formato 12345-678 ou 12345678.\n");
        }
    } while (!cep_valido);

    compradores[num_compradores++] = c;
    printf("Comprador cadastrado com sucesso!\n");
}

void alterar_comprador() {
    char cpf[15];
    printf("\n--- Alterar Comprador ---\n");
    printf("CPF do comprador a ser alterado: ");
    fgets(cpf, 15, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    int idx = comprador_existe(cpf);
    if (idx == -1) {
        printf("Comprador nao encontrado!\n");
        return;
    }

    printf("\nDados atuais do comprador:\n");
    printf("Nome: %s\n", compradores[idx].nome);
    printf("CPF: %s\n", compradores[idx].cpf);
    printf("Email: %s\n", compradores[idx].email);
    printf("Endereco: %s, %s - %s/%s - CEP: %s\n",
           compradores[idx].endereco.rua, compradores[idx].endereco.bairro,
           compradores[idx].endereco.cidade, compradores[idx].endereco.estado,
           compradores[idx].endereco.cep);

    printf("\nNovos dados (deixe em branco para manter o valor atual):\n");

    char novo_nome[50];
    printf("Nome [%s]: ", compradores[idx].nome);
    fgets(novo_nome, 50, stdin);
    if (strlen(novo_nome) > 1) {
        novo_nome[strcspn(novo_nome, "\n")] = '\0';
        strcpy(compradores[idx].nome, novo_nome);
    }

    char novo_email[50];
    printf("Email [%s]: ", compradores[idx].email);
    fgets(novo_email, 50, stdin);
    if (strlen(novo_email) > 1) {
        novo_email[strcspn(novo_email, "\n")] = '\0';
        strcpy(compradores[idx].email, novo_email);
    }

    printf("\n--- Endereco ---\n");
    char nova_rua[50];
    printf("Rua [%s]: ", compradores[idx].endereco.rua);
    fgets(nova_rua, 50, stdin);
    if (strlen(nova_rua) > 1) {
        nova_rua[strcspn(nova_rua, "\n")] = '\0';
        strcpy(compradores[idx].endereco.rua, nova_rua);
    }

    char novo_bairro[30];
    printf("Bairro [%s]: ", compradores[idx].endereco.bairro);
    fgets(novo_bairro, 30, stdin);
    if (strlen(novo_bairro) > 1) {
        novo_bairro[strcspn(novo_bairro, "\n")] = '\0';
        strcpy(compradores[idx].endereco.bairro, novo_bairro);
    }

    char nova_cidade[30];
    printf("Cidade [%s]: ", compradores[idx].endereco.cidade);
    fgets(nova_cidade, 30, stdin);
    if (strlen(nova_cidade) > 1) {
        nova_cidade[strcspn(nova_cidade, "\n")] = '\0';
        strcpy(compradores[idx].endereco.cidade, nova_cidade);
    }

    char novo_estado[3];
    printf("Estado [%s]: ", compradores[idx].endereco.estado);
    fgets(novo_estado, 3, stdin);
    if (strlen(novo_estado) > 1) {
        novo_estado[strcspn(novo_estado, "\n")] = '\0';
        strcpy(compradores[idx].endereco.estado, novo_estado);
    }
    limpar_buffer();

    char novo_cep[10];
    printf("CEP [%s] (deixe em branco para manter): ", compradores[idx].endereco.cep);
    fgets(novo_cep, 10, stdin);
    if (strlen(novo_cep) > 1) {
        novo_cep[strcspn(novo_cep, "\n")] = '\0';

        char *p = novo_cep;
        while (*p) {
            if (isspace(*p)) {
                memmove(p, p+1, strlen(p));
            } else {
                p++;
            }
        }

        if (validar_cep(novo_cep)) {
            formatar_cep(novo_cep);
            strcpy(compradores[idx].endereco.cep, novo_cep);
        } else {
            printf("CEP invalido! Mantendo o CEP anterior.\n");
        }
    }

    printf("Comprador alterado com sucesso!\n");
}

void excluir_comprador() {
    char cpf[15];
    printf("\n--- Excluir Comprador ---\n");
    printf("CPF do comprador a ser excluido: ");
    fgets(cpf, 15, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    int idx = comprador_existe(cpf);
    if (idx == -1) {
        printf("Comprador nao encontrado!\n");
        return;
    }

    for (int i = 0; i < num_vendas; i++) {
        if (strcmp(vendas[i].cpf_comprador, cpf) == 0) {
            printf("Nao e possivel excluir: comprador esta vinculado a uma ou mais vendas!\n");
            return;
        }
    }

    for (int i = idx; i < num_compradores - 1; i++) {
        compradores[i] = compradores[i + 1];
    }
    num_compradores--;

    printf("Comprador excluido com sucesso!\n");
}

void listar_compradores() {
    printf("\n--- Lista de Compradores ---\n");
    for (int i = 0; i < num_compradores; i++) {
        printf("CPF: %s | Nome: %s | Email: %s\n",
               compradores[i].cpf, compradores[i].nome, compradores[i].email);
        printf("Endereco: %s, %s - %s/%s - CEP: %s\n",
               compradores[i].endereco.rua, compradores[i].endereco.bairro,
               compradores[i].endereco.cidade, compradores[i].endereco.estado,
               compradores[i].endereco.cep);
    }
}

// Funções para Vendas
void realizar_venda() {
    if (num_vendas >= MAX_VENDAS) {
        printf("Limite de vendas atingido!\n");
        return;
    }

    Venda v;
    v.num_itens = 0;
    v.total_venda = 0;

    printf("\n--- Realizar Venda ---\n");
    printf("Codigo da venda: ");
    scanf("%d", &v.codigo);

    if (venda_existe(v.codigo) != -1) {
        printf("Erro: Codigo de venda ja existe!\n");
        return;
    }

    printf("Numero do vendedor: ");
    scanf("%d", &v.codigo_vendedor);

    int idx_vendedor = vendedor_existe(v.codigo_vendedor);
    if (idx_vendedor == -1) {
        printf("Erro: Vendedor nao encontrado!\n");
        return;
    }

    limpar_buffer();
    printf("CPF do comprador: ");
    char cpf[15];
    fgets(cpf, 15, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    int idx_comprador = comprador_existe(cpf);
    if (idx_comprador == -1) {
        printf("Erro: Comprador nao encontrado!\n");
        return;
    }
    strcpy(v.cpf_comprador, cpf);

    char continuar;
    do {
        if (v.num_itens >= MAX_ITENS_VENDA) {
            printf("Limite de itens por venda atingido!\n");
            break;
        }

        ItemVenda item;

        printf("\n--- Item %d ---\n", v.num_itens + 1);
        printf("Codigo do produto: ");
        scanf("%d", &item.codigo_produto);

        int idx_produto = produto_existe(item.codigo_produto);
        if (idx_produto == -1) {
            printf("Erro: Produto nao encontrado!\n");
            continue;
        }

        printf("Quantidade: ");
        scanf("%d", &item.quantidade_vendida);

        if (item.quantidade_vendida > produtos[idx_produto].quantidade_estoque) {
            printf("Erro: Quantidade em estoque insuficiente!\n");
            printf("Estoque disponivel: %d\n", produtos[idx_produto].quantidade_estoque);
            continue;
        }

        strcpy(item.nome_produto, produtos[idx_produto].nome);
        item.preco_unitario = produtos[idx_produto].preco_venda;
        item.preco_total = item.preco_unitario * item.quantidade_vendida;

        produtos[idx_produto].quantidade_estoque -= item.quantidade_vendida;

        v.itens[v.num_itens++] = item;
        v.total_venda += item.preco_total;

        printf("Item adicionado com sucesso!\n");

        printf("Adicionar outro item? (s/n): ");
        limpar_buffer();
        continuar = tolower(getchar());
    } while (continuar == 's');

    float percentual_comissao = vendedores[idx_vendedor].percentual_comissao / 100;
    float comissao = v.total_venda * percentual_comissao;
    vendedores[idx_vendedor].comissoes += comissao;

    vendas[num_vendas++] = v;
    printf("Venda registrada com sucesso! Total: R$ %.2f\n", v.total_venda);
}

void alterar_venda() {
    int codigo;
    printf("\n--- Alterar Venda ---\n");
    printf("Codigo da venda a ser alterada: ");
    scanf("%d", &codigo);

    int idx = venda_existe(codigo);
    if (idx == -1) {
        printf("Venda nao encontrada!\n");
        return;
    }

    printf("\nDados atuais da venda:\n");
    printf("Codigo: %d\n", vendas[idx].codigo);
    printf("Vendedor: %d\n", vendas[idx].codigo_vendedor);
    printf("Comprador: %s\n", vendas[idx].cpf_comprador);
    printf("Total: R$ %.2f\n", vendas[idx].total_venda);

    printf("\nItens da venda:\n");
    for (int i = 0; i < vendas[idx].num_itens; i++) {
        printf("  %s (Cod: %d) - %d x R$ %.2f = R$ %.2f\n",
               vendas[idx].itens[i].nome_produto, vendas[idx].itens[i].codigo_produto,
               vendas[idx].itens[i].quantidade_vendida, vendas[idx].itens[i].preco_unitario,
               vendas[idx].itens[i].preco_total);
    }

    printf("\nPara alterar uma venda, cancele a venda existente e crie uma nova.\n");
}

void cancelar_venda() {
    int codigo;
    printf("\n--- Cancelar Venda ---\n");
    printf("Codigo da venda a ser cancelada: ");
    scanf("%d", &codigo);

    int idx = venda_existe(codigo);
    if (idx == -1) {
        printf("Venda nao encontrada!\n");
        return;
    }

    for (int i = 0; i < vendas[idx].num_itens; i++) {
        int cod_prod = vendas[idx].itens[i].codigo_produto;
        int qtd = vendas[idx].itens[i].quantidade_vendida;

        int idx_prod = produto_existe(cod_prod);
        if (idx_prod != -1) {
            produtos[idx_prod].quantidade_estoque += qtd;
        }
    }

    int idx_vendedor = vendedor_existe(vendas[idx].codigo_vendedor);
    if (idx_vendedor != -1) {
        float percentual = vendedores[idx_vendedor].percentual_comissao / 100;
        vendedores[idx_vendedor].comissoes -= vendas[idx].total_venda * percentual;
    }

    for (int i = idx; i < num_vendas - 1; i++) {
        vendas[i] = vendas[i + 1];
    }
    num_vendas--;

    printf("Venda cancelada com sucesso!\n");
}

void listar_vendas() {
    printf("\n--- Lista de Vendas ---\n");
    for (int i = 0; i < num_vendas; i++) {
        printf("Codigo: %d | Vendedor: %d | Comprador: %s | Total: R$ %.2f\n",
               vendas[i].codigo, vendas[i].codigo_vendedor,
               vendas[i].cpf_comprador, vendas[i].total_venda);

        printf("Itens:\n");
        for (int j = 0; j < vendas[i].num_itens; j++) {
            printf("  %s (Cod: %d) - %d x R$ %.2f = R$ %.2f\n",
                   vendas[i].itens[j].nome_produto, vendas[i].itens[j].codigo_produto,
                   vendas[i].itens[j].quantidade_vendida, vendas[i].itens[j].preco_unitario,
                   vendas[i].itens[j].preco_total);
        }
    }
}

void emitir_nota_fiscal() {
    int codigo_venda;

    printf("\n--- Emissao de Nota Fiscal ---\n");
    printf("Codigo da venda: ");
    scanf("%d", &codigo_venda);

    int idx_venda = venda_existe(codigo_venda);
    if (idx_venda == -1) {
        printf("Erro: Venda nao encontrada!\n");
        return;
    }

    Venda v = vendas[idx_venda];

    int idx_comprador = comprador_existe(v.cpf_comprador);
    Comprador c = compradores[idx_comprador];

    int idx_vendedor = vendedor_existe(v.codigo_vendedor);
    Vendedor vend = vendedores[idx_vendedor];

    float frete = 0;
    if (v.total_venda <= 100.00) {
        frete = 30.00;
    } else if (v.total_venda <= 300.00) {
        frete = 20.00;
    }

    float total_geral = v.total_venda + frete;

    printf("\n=============================\n");
    printf("        NOTA FISCAL\n");
    printf("=============================\n");
    printf("Venda: %d\n", v.codigo);
    printf("Vendedor: %s (Num: %d)\n", vend.nome, vend.numero);
    printf("\nDados do Comprador:\n");
    printf("Nome: %s\n", c.nome);
    printf("CPF: %s\n", c.cpf);
    printf("Email: %s\n", c.email);
    printf("Endereco de entrega:\n");
    printf("%s, %s - %s/%s - CEP: %s\n", c.endereco.rua, c.endereco.bairro,
           c.endereco.cidade, c.endereco.estado, c.endereco.cep);

    printf("\nItens da Venda:\n");
    printf("------------------------------------------------------------\n");
    printf("Descricao                Codigo  Qtd  Unitario    Total\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < v.num_itens; i++) {
        printf("%-24s %-7d %-4d %-9.2f %-9.2f\n",
               v.itens[i].nome_produto, v.itens[i].codigo_produto,
               v.itens[i].quantidade_vendida, v.itens[i].preco_unitario,
               v.itens[i].preco_total);
    }

    printf("------------------------------------------------------------\n");
    printf("Subtotal: R$ %.2f\n", v.total_venda);
    printf("Frete: R$ %.2f\n", frete);
    printf("TOTAL GERAL: R$ %.2f\n", total_geral);
    printf("=============================\n");
}

// Menus
void menu_produtos() {
    int opcao;
    do {
        printf("\n=== MENU PRODUTOS ===\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Alterar Produto\n");
        printf("3. Excluir Produto\n");
        printf("4. Listar Produtos\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1: cadastrar_produto(); break;
            case 2: alterar_produto(); break;
            case 3: excluir_produto(); break;
            case 4: listar_produtos(); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menu_vendedores() {
    int opcao;
    do {
        printf("\n=== MENU VENDEDORES ===\n");
        printf("1. Cadastrar Vendedor\n");
        printf("2. Alterar Vendedor\n");
        printf("3. Excluir Vendedor\n");
        printf("4. Listar Vendedores\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1: cadastrar_vendedor(); break;
            case 2: alterar_vendedor(); break;
            case 3: excluir_vendedor(); break;
            case 4: listar_vendedores(); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menu_compradores() {
    int opcao;
    do {
        printf("\n=== MENU COMPRADORES ===\n");
        printf("1. Cadastrar Comprador\n");
        printf("2. Alterar Comprador\n");
        printf("3. Excluir Comprador\n");
        printf("4. Listar Compradores\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1: cadastrar_comprador(); break;
            case 2: alterar_comprador(); break;
            case 3: excluir_comprador(); break;
            case 4: listar_compradores(); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menu_vendas() {
    int opcao;
    do {
        printf("\n=== MENU VENDAS ===\n");
        printf("1. Realizar Venda\n");
        printf("2. Alterar Venda\n");
        printf("3. Cancelar Venda\n");
        printf("4. Listar Vendas\n");
        printf("5. Emitir Nota Fiscal\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1: realizar_venda(); break;
            case 2: alterar_venda(); break;
            case 3: cancelar_venda(); break;
            case 4: listar_vendas(); break;
            case 5: emitir_nota_fiscal(); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menu_principal() {
    int opcao;

    do {
        printf("\n=== SISTEMA DE VENDAS ===\n");
        printf("1. Gerenciar Produtos\n");
        printf("2. Gerenciar Vendedores\n");
        printf("3. Gerenciar Compradores\n");
        printf("4. Gerenciar Vendas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1: menu_produtos(); break;
            case 2: menu_vendedores(); break;
            case 3: menu_compradores(); break;
            case 4: menu_vendas(); break;
            case 0: printf("Saindo do sistema...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

int main() {
    menu_principal();
    return 0;
}
