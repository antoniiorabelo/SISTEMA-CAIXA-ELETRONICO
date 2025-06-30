#include "munit.h"
#include "venda.h"

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

static MunitResult test_calculo_comissao(const MunitParameter params[], void* fixture) {
    vendedores[0].percentual_comissao = 10.0;
    vendas[0].total_venda = 1000.0;
    
    calcular_comissao(0); // Índice da venda
    
    munit_assert_double(vendedores[0].comissoes, ==, 100.0);
    
    return MUNIT_OK;
}

MunitTest venda_tests[] = {
    {"/realizar_venda", test_realizar_venda, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/calculo_comissao", test_calculo_comissao, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};