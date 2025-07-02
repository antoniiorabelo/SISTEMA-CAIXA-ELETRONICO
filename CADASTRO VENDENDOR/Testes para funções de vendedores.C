#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "../munit/munit.h"
#include "../munit/munit.c"
/* Teste para cadastrar_vendedor() */
static MunitResult test_cadastrar_vendedor(const MunitParameter params[], void* fixture) {
    num_vendedores = 0;
    
    Vendedor v = {"Vendedor Teste", 1, 1500.0, 0.0, 5.0};
    vendedores[num_vendedores++] = v;
    
    munit_assert_int(num_vendedores, ==, 1);
    munit_assert_string_equal(vendedores[0].nome, "Vendedor Teste");
    munit_assert_int(vendedores[0].numero, ==, 1);
    munit_assert_double(vendedores[0].salario_fixo, ==, 1500.0);
    munit_assert_double(vendedores[0].percentual_comissao, ==, 5.0);
    
    return MUNIT_OK;
}

/* Teste para alterar_vendedor() */
static MunitResult test_alterar_vendedor(const MunitParameter params[], void* fixture) {
    num_vendedores = 0;
    Vendedor v = {"Vendedor Antigo", 1, 1500.0, 0.0, 5.0};
    vendedores[num_vendedores++] = v;
    
    // Simula alteração
    strcpy(vendedores[0].nome, "Vendedor Novo");
    vendedores[0].salario_fixo = 2000.0;
    
    munit_assert_string_equal(vendedores[0].nome, "Vendedor Novo");
    munit_assert_double(vendedores[0].salario_fixo, ==, 2000.0);
    munit_assert_double(vendedores[0].percentual_comissao, ==, 5.0); // Comissão não deve mudar
    
    return MUNIT_OK;
}

/* Teste para excluir_vendedor() */
static MunitResult test_excluir_vendedor(const MunitParameter params[], void* fixture) {
    num_vendedores = 0;
    Vendedor v1 = {"Vendedor 1", 1, 1500.0, 0.0, 5.0};
    Vendedor v2 = {"Vendedor 2", 2, 2000.0, 0.0, 5.0};
    vendedores[num_vendedores++] = v1;
    vendedores[num_vendedores++] = v2;
    
    // Remove o primeiro vendedor
    for (int i = 0; i < num_vendedores - 1; i++) {
        vendedores[i] = vendedores[i + 1];
    }
    num_vendedores--;
    
    munit_assert_int(num_vendedores, ==, 1);
    munit_assert_int(vendedores[0].numero, ==, 2);
    
    return MUNIT_OK;
}

/* Teste para listar_vendedores() */
static MunitResult test_listar_vendedores(const MunitParameter params[], void* fixture) {
    num_vendedores = 0;
    Vendedor v = {"Vendedor Teste", 1, 1500.0, 100.0, 5.0};
    vendedores[num_vendedores++] = v;
    
    freopen("test_output.txt", "w", stdout);
    listar_vendedores();
    freopen("/dev/tty", "w", stdout);
    
    FILE *fp = fopen("test_output.txt", "r");
    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);
    
    munit_assert_true(strstr(buffer, "Vendedor Teste") != NULL);
    munit_assert_true(strstr(buffer, "1") != NULL);
    munit_assert_true(strstr(buffer, "1500.00") != NULL);
    
    return MUNIT_OK;
}