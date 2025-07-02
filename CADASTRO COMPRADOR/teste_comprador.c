#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "../munit/munit.h"
#include "../munit/munit.c"

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
    char cep[10];
} Endereco;

typedef struct {
    char nome[50];
    int codigo;
    int quantidade_estoque;
    float preco_venda;
} Produto;

typedef struct {
    char nome[50];
    unsigned long long cpf; // CPF como número
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
    char nome_produto[50];
    int codigo_produto;
    int quantidade_vendida;
    float preco_unitario;
    float preco_total;
} ItemVenda;

typedef struct {
    int codigo;
    int codigo_vendedor;
    unsigned long long cpf_comprador;
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

int comprador_existe(unsigned long long cpf) {
    for (int i = 0; i < num_compradores; i++) {
        if (compradores[i].cpf == cpf) {
            return i;
        }
    }
    return -1;
}

int excluir_comprador_logic(unsigned long long cpf) {
    int idx = comprador_existe(cpf);
    if (idx == -1) return 0;

    for (int i = 0; i < num_vendas; i++) {
        if (vendas[i].cpf_comprador == cpf) {
            return -1;
        }
    }

    for (int i = idx; i < num_compradores - 1; i++) {
        compradores[i] = compradores[i + 1];
    }
    num_compradores--;
    return 1;
}

// Função auxiliar para converter CPF formatado (string) para unsigned long long (somente números)
unsigned long long cpf_to_ull(const char *cpf_str) {
    char digits[12] = {0}; // 11 dígitos + terminador
    int j = 0;
    for (int i = 0; cpf_str[i] != '\0'; i++) {
        if (cpf_str[i] >= '0' && cpf_str[i] <= '9') {
            digits[j++] = cpf_str[i];
        }
    }
    return strtoull(digits, NULL, 10);
}

// ----------- TESTES -----------

static MunitResult test_cadastrar_comprador_valido(const MunitParameter params[], void* data) {
    num_compradores = 0;

    Comprador novo = {
        "João Silva",
        cpf_to_ull("123.456.789-09"),
        "joao@email.com",
        {"Rua A", "Centro", "Cidade B", "SP", "12345-678"}
    };

    compradores[num_compradores++] = novo;

    munit_assert_int(num_compradores, ==, 1);
    munit_assert_int(compradores[0].cpf, ==, cpf_to_ull("123.456.789-09"));

    return MUNIT_OK;
}

static MunitResult test_verificar_cpf_existente(const MunitParameter params[], void* data) {
    num_compradores = 0;

    Comprador c1 = {
        "Maria",
        cpf_to_ull("111.222.333-44"),
        "email",
        {"Rua X", "Bairro Y", "Cidade Z", "SP", "11111-222"}
    };
    compradores[num_compradores++] = c1;

    int idx = comprador_existe(cpf_to_ull("111.222.333-44"));

    munit_assert_int(idx, !=, -1);
    munit_assert_int(num_compradores, ==, 1);

    return MUNIT_OK;
}

static MunitResult test_excluir_comprador_sucesso(const MunitParameter params[], void* data) {
    num_compradores = 0;

    Comprador c1 = {
        "A",
        cpf_to_ull("111.111.111-11"),
        "e1",
        {"Rua A", "Bairro A", "Cidade A", "SP", "00000-000"}
    };
    Comprador c2 = {
        "B",
        cpf_to_ull("222.222.222-22"),
        "e2",
        {"Rua B", "Bairro B", "Cidade B", "RJ", "99999-999"}
    };
    compradores[num_compradores++] = c1;
    compradores[num_compradores++] = c2;

    int resultado = excluir_comprador_logic(cpf_to_ull("111.111.111-11"));

    munit_assert_int(resultado, ==, 1);
    munit_assert_int(num_compradores, ==, 1);
    munit_assert_int(compradores[0].cpf, ==, cpf_to_ull("222.222.222-22"));

    return MUNIT_OK;
}

static MunitResult test_excluir_comprador_inexistente(const MunitParameter params[], void* data) {
    num_compradores = 0;

    Comprador c1 = {
        "A",
        cpf_to_ull("111.111.111-11"),
        "e1",
        {"Rua A", "Bairro A", "Cidade A", "SP", "00000-000"}
    };
    compradores[num_compradores++] = c1;

    int resultado = excluir_comprador_logic(cpf_to_ull("999.999.999-99"));

    munit_assert_int(resultado, ==, 0);
    munit_assert_int(num_compradores, ==, 1);

    return MUNIT_OK;
}

static MunitResult test_excluir_comprador_com_venda(const MunitParameter params[], void* data) {
    num_compradores = 0;
    num_vendas = 0;

    Comprador c1 = {
        "A",
        cpf_to_ull("111.111.111-11"),
        "e1",
        {"Rua A", "Bairro A", "Cidade A", "SP", "00000-000"}
    };
    compradores[num_compradores++] = c1;

    Venda v = {0};
    v.codigo = 1;
    v.codigo_vendedor = 1;
    v.cpf_comprador = cpf_to_ull("111.111.111-11");

    vendas[num_vendas++] = v;

    int resultado = excluir_comprador_logic(cpf_to_ull("111.111.111-11"));

    munit_assert_int(resultado, ==, -1);
    munit_assert_int(num_compradores, ==, 1);

    return MUNIT_OK;
}

// ------------------------ SUITE ------------------------

static MunitTest tests[] = {
    {"/cadastro_valido", test_cadastrar_comprador_valido, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/cadastro_cpf_existente", test_verificar_cpf_existente, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/exclusao_sucesso", test_excluir_comprador_sucesso, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/exclusao_inexistente", test_excluir_comprador_inexistente, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/exclusao_com_venda", test_excluir_comprador_com_venda, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
    "/gerenciamento-compradores",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
    printf("Concluido");
    getchar();
    return 0;
}
