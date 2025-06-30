#include "munit.h"
#include "clientes.h" // Supondo que suas funções estão aqui

/* Fixture para inicialização */
static Cliente* clientes;
static int num_clientes;

static void* setup(const MunitParameter params[], void* user_data) {
    // Inicializa array de clientes para testes
    num_clientes = 0;
    clientes = (Cliente*)malloc(MAX_CLIENTES * sizeof(Cliente));
    return NULL;
}

static void tear_down(void* fixture) {
    free(clientes);
}

/* Teste 1: Cadastro de novo comprador válido */
static MunitResult test_cadastrar_comprador_valido(const MunitParameter params[], void* fixture) {
    Cliente novo = {
        .nome = "João Silva",
        .cpf = "123.456.789-09",
        .senha = "Senha@123",
        .saldo = 0.0
    };

    int resultado = cadastrar_cliente(clientes, &num_clientes, novo);
    
    munit_assert_int(resultado, ==, 1); // Sucesso
    munit_assert_int(num_clientes, ==, 1);
    munit_assert_string_equal(clientes[0].cpf, "123.456.789-09");
    
    return MUNIT_OK;
}

/* Teste 2: Cadastro com CPF duplicado */
static MunitResult test_cadastrar_cpf_duplicado(const MunitParameter params[], void* fixture) {
    // Primeiro cadastro
    Cliente c1 = {"Maria", "111.222.333-44", "senha123", 100.0};
    cadastrar_cliente(clientes, &num_clientes, c1);
    
    // Tentativa de duplicar
    Cliente c2 = {"Outro", "111.222.333-44", "outrasenha", 50.0};
    int resultado = cadastrar_cliente(clientes, &num_clientes, c2);
    
    munit_assert_int(resultado, ==, 0); // Falha
    munit_assert_int(num_clientes, ==, 1);
    
    return MUNIT_OK;
}

/* Teste 3: Alterar comprador existente */
static MunitResult test_alterar_comprador(const MunitParameter params[], void* fixture) {
    // Cadastra inicial
    Cliente original = {"Carlos", "999.888.777-66", "abc123", 200.0};
    cadastrar_cliente(clientes, &num_clientes, original);
    
    // Altera dados
    Cliente alterado = original;
    strcpy(alterado.nome, "Carlos Eduardo");
    alterado.saldo = 300.0;
    
    int resultado = alterar_cliente(clientes, num_clientes, "999.888.777-66", alterado);
    
    munit_assert_int(resultado, ==, 1);
    munit_assert_string_equal(clientes[0].nome, "Carlos Eduardo");
    munit_assert_double(clientes[0].saldo, ==, 300.0);
    
    return MUNIT_OK;
}

/* Teste 4: Tentar alterar comprador inexistente */
static MunitResult test_alterar_inexistente(const MunitParameter params[], void* fixture) {
    Cliente dummy = {"Nome", "000.000.000-00", "senha", 0.0};
    int resultado = alterar_cliente(clientes, num_clientes, "999.999.999-99", dummy);
    
    munit_assert_int(resultado, ==, 0);
    return MUNIT_OK;
}

/* Teste 5: Excluir comprador existente */
static MunitResult test_excluir_comprador(const MunitParameter params[], void* fixture) {
    // Setup
    Comprador c1 = {"A", "111.111.111-11", "email1", {"Rua 1", "Bairro 1", "Cidade 1", "SP", "12345-678"}};
    Comprador c2 = {"B", "222.222.222-22", "email2", {"Rua 2", "Bairro 2", "Cidade 2", "RJ", "23456-789"}};
    
    // Cadastra os compradores
    compradores[num_compradores++] = c1;
    compradores[num_compradores++] = c2;
    
    // Teste: excluir o primeiro comprador
    int resultado = excluir_comprador("111.111.111-11");
    
    munit_assert_int(resultado, ==, 1); // Sucesso
    munit_assert_int(num_compradores, ==, 1);
    munit_assert_string_equal(compradores[0].cpf, "222.222.222-22");
    
    return MUNIT_OK;
}

/* Teste 6: Tentar excluir comprador inexistente */
static MunitResult test_excluir_comprador_inexistente(const MunitParameter params[], void* fixture) {
    // Setup com um comprador
    Comprador c1 = {"A", "111.111.111-11", "email1", {"Rua 1", "Bairro 1", "Cidade 1", "SP", "12345-678"}};
    compradores[num_compradores++] = c1;
    
    // Teste: tentar excluir CPF que não existe
    int resultado = excluir_comprador("999.999.999-99");
    
    munit_assert_int(resultado, ==, 0); // Falha
    munit_assert_int(num_compradores, ==, 1); // Número de compradores não mudou
    
    return MUNIT_OK;
}

/* Teste 7: Tentar excluir comprador com venda associada */
static MunitResult test_excluir_comprador_com_venda(const MunitParameter params[], void* fixture) {
    // Setup com comprador e venda associada
    Comprador c1 = {"A", "111.111.111-11", "email1", {"Rua 1", "Bairro 1", "Cidade 1", "SP", "12345-678"}};
    compradores[num_compradores++] = c1;
    
    // Cria uma venda associada a este comprador
    Venda v = {
        .codigo = 1,
        .codigo_vendedor = 1,
        .cpf_comprador = "111.111.111-11",
        .num_itens = 0,
        .total_venda = 0
    };
    vendas[num_vendas++] = v;
    
    // Teste: tentar excluir comprador com venda
    int resultado = excluir_comprador("111.111.111-11");
    
    munit_assert_int(resultado, ==, 0); // Falha
    munit_assert_int(num_compradores, ==, 1); // Comprador não foi excluído
    
    return MUNIT_OK;
}

/* Suite de testes */
static MunitTest tests[] = {
    {"/cadastrar_comprador_valido", test_cadastrar_comprador_valido, setup, tear_down, MUNIT_TEST_OPTION_NONE, NULL},
    {"/cadastrar_cpf_duplicado", test_cadastrar_cpf_duplicado, setup, tear_down, MUNIT_TEST_OPTION_NONE, NULL},
    {"/alterar_comprador", test_alterar_comprador, setup, tear_down, MUNIT_TEST_OPTION_NONE, NULL},
    {"/alterar_inexistente", test_alterar_inexistente, setup, tear_down, MUNIT_TEST_OPTION_NONE, NULL},
    {"/excluir_comprador", test_excluir_comprador, setup, tear_down, MUNIT_TEST_OPTION_NONE, NULL},
    {"/excluir_comprador_inexistente", test_excluir_comprador_inexistente, setup, tear_down, MUNIT_TEST_OPTION_NONE, NULL},
    {"/excluir_comprador_com_venda", test_excluir_comprador_com_venda, setup, tear_down, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
    "/compradores",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}");
    