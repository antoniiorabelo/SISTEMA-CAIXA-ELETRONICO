#include "munit.h"
#include "comprador.h"

static MunitResult test_validar_cep(const MunitParameter params[], void* fixture) {
    munit_assert_true(validar_cep("12345678"));
    munit_assert_true(validar_cep("12345-678"));
    munit_assert_false(validar_cep("1234-5678"));
    
    return MUNIT_OK;
}

static MunitResult test_cadastro_comprador(const MunitParameter params[], void* fixture) {
    num_compradores = 0;
    strcpy(compradores[0].nome, "Maria Souza");
    strcpy(compradores[0].cpf, "12345678901");
    strcpy(compradores[0].endereco.cep, "12345678");
    
    formatar_cep(compradores[0].endereco.cep);
    
    munit_assert_int(num_compradores, ==, 1);
    munit_assert_string_equal(compradores[0].nome, "Maria Souza");
    munit_assert_string_equal(compradores[0].endereco.cep, "12345-678");
    
    return MUNIT_OK;
}

MunitTest comprador_tests[] = {
    {"/validar_cep", test_validar_cep, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/cadastro_comprador", test_cadastro_comprador, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};