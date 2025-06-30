#include "munit.h"
#include "nota_fiscal.h"

static MunitResult test_calculo_frete(const MunitParameter params[], void* fixture) {
    munit_assert_double(calcular_frete(50.0), ==, 30.0);
    munit_assert_double(calcular_frete(150.0), ==, 20.0);
    munit_assert_double(calcular_frete(400.0), ==, 0.0);
    
    return MUNIT_OK;
}

static MunitResult test_emissao_nota(const MunitParameter params[], void* fixture) {
    vendas[0].total_venda = 200.0;
    float total = emitir_nota_fiscal(0); // Índice da venda
    
    munit_assert_double(total, ==, 220.0); // 200 + 20 de frete
    
    return MUNIT_OK;
}

MunitTest nota_fiscal_tests[] = {
    {"/calculo_frete", test_calculo_frete, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/emissao_nota", test_emissao_nota, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};