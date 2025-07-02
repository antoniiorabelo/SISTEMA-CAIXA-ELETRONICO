#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "../munit/munit.h"
#include "../munit/munit.c"

// Fixture para inicialização do ambiente de teste
static void* setup(const MunitParameter params[], void* user_data) {
    // Inicializa uma venda de teste
    Venda v = {
        .codigo = 1,
        .codigo_vendedor = 100,
        .cpf_comprador = "123.456.789-09",
        .num_itens = 2,
        .total_venda = 250.00,
        .itens = {
            {"Produto A", 101, 2, 50.00, 100.00},
            {"Produto B", 102, 1, 150.00, 150.00}
        }
    };
    
    // Inicializa um comprador de teste
    Comprador c = {
        .nome = "João Silva",
        .cpf = "123.456.789-09",
        .email = "joao@example.com",
        .endereco = {
            .rua = "Rua das Flores",
            .bairro = "Centro",
            .cidade = "São Paulo",
            .estado = "SP",
            .cep = "01001-000"
        }
    };
    
    // Inicializa um vendedor de teste
    Vendedor vend = {
        .nome = "Maria Souza",
        .numero = 100,
        .salario_fixo = 2000.00,
        .percentual_comissao = 5.0,
        .comissoes = 0.0
    };
    
    // Adiciona aos arrays globais
    vendas[num_vendas++] = v;
    compradores[num_compradores++] = c;
    vendedores[num_vendedores++] = vend;
    
    return NULL;
}

static void tear_down(void* fixture) {
    // Limpa os arrays globais após o teste
    num_vendas = 0;
    num_compradores = 0;
    num_vendedores = 0;
}

/* Teste: Verificar cálculo de frete e total geral */
static MunitResult test_emitir_nota_fiscal(const MunitParameter params[], void* fixture) {
    // Redireciona a saída padrão para um buffer para capturar o resultado
    FILE* original_stdout = stdout;
    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    
    // Cria um arquivo temporário para capturar a saída
    FILE* temp_stdout = fmemopen(buffer, sizeof(buffer), "w");
    if (temp_stdout == NULL) {
        return MUNIT_ERROR;
    }
    stdout = temp_stdout;
    
    // Chama a função que queremos testar
    emitir_nota_fiscal(1);
    
    // Restaura a saída padrão
    fclose(temp_stdout);
    stdout = original_stdout;
    
    // Verifica se a saída contém os valores esperados
    munit_assert_true(strstr(buffer, "Subtotal: R$ 250.00") != NULL);
    munit_assert_true(strstr(buffer, "Frete: R$ 20.00") != NULL); // Frete para valor entre 100 e 300
    munit_assert_true(strstr(buffer, "TOTAL GERAL: R$ 270.00") != NULL);
    
    // Verifica se os dados do comprador estão corretos
    munit_assert_true(strstr(buffer, "João Silva") != NULL);
    munit_assert_true(strstr(buffer, "123.456.789-09") != NULL);
    munit_assert_true(strstr(buffer, "Rua das Flores") != NULL);
    
    // Verifica se os itens estão listados corretamente
    munit_assert_true(strstr(buffer, "Produto A") != NULL);
    munit_assert_true(strstr(buffer, "Produto B") != NULL);
    
    return MUNIT_OK;
}

/* Teste: Verificar nota fiscal para valor baixo (frete maior) */
static MunitResult test_nota_fiscal_valor_baixo(const MunitParameter params[], void* fixture) {
    // Adiciona uma venda com valor baixo
    Venda v = {
        .codigo = 2,
        .codigo_vendedor = 100,
        .cpf_comprador = "123.456.789-09",
        .num_itens = 1,
        .total_venda = 80.00,
        .itens = {
            {"Produto C", 103, 1, 80.00, 80.00}
        }
    };
    vendas[num_vendas++] = v;
    
    // Redireciona a saída padrão
    FILE* original_stdout = stdout;
    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    FILE* temp_stdout = fmemopen(buffer, sizeof(buffer), "w");
    stdout = temp_stdout;
    
    emitir_nota_fiscal(2);
    
    fclose(temp_stdout);
    stdout = original_stdout;
    
    // Verifica o frete para valor <= 100
    munit_assert_true(strstr(buffer, "Frete: R$ 30.00") != NULL);
    munit_assert_true(strstr(buffer, "TOTAL GERAL: R$ 110.00") != NULL);
    
    return MUNIT_OK;
}

/* Teste: Verificar nota fiscal para valor alto (sem frete) */
static MunitResult test_nota_fiscal_valor_alto(const MunitParameter params[], void* fixture) {
    // Adiciona uma venda com valor alto
    Venda v = {
        .codigo = 3,
        .codigo_vendedor = 100,
        .cpf_comprador = "123.456.789-09",
        .num_itens = 1,
        .total_venda = 350.00,
        .itens = {
            {"Produto D", 104, 1, 350.00, 350.00}
        }
    };
    vendas[num_vendas++] = v;
    
    // Redireciona a saída padrão
    FILE* original_stdout = stdout;
    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    FILE* temp_stdout = fmemopen(buffer, sizeof(buffer), "w");
    stdout = temp_stdout;
    
    emitir_nota_fiscal(3);
    
    fclose(temp_stdout);
    stdout = original_stdout;
    
    // Verifica que não há frete para valor > 300
    munit_assert_true(strstr(buffer, "Frete: R$ 0.00") != NULL);
    munit_assert_true(strstr(buffer, "TOTAL GERAL: R$ 350.00") != NULL);
    
    return MUNIT_OK;
}

/* Teste: Verificar nota fiscal para venda inexistente */
static MunitResult test_nota_fiscal_venda_inexistente(const MunitParameter params[], void* fixture) {
    // Redireciona a saída padrão
    FILE* original_stdout = stdout;
    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    FILE* temp_stdout = fmemopen(buffer, sizeof(buffer), "w");
    stdout = temp_stdout;
    
    emitir_nota_fiscal(999); // Código que não existe
    
    fclose(temp_stdout);
    stdout = original_stdout;
    
    // Verifica a mensagem de erro
    munit_assert_true(strstr(buffer, "Venda nao encontrada") != NULL);
    
    return MUNIT_OK;
}

/* Suite de testes */
static MunitTest tests[] = {
    {"/emitir_nota_fiscal", test_emitir_nota_fiscal, setup, tear_down, MUNIT_TEST_OPTION_NONE, NULL},
    {"/nota_fiscal_valor_baixo", test_nota_fiscal_valor_baixo, setup, tear_down, MUNIT_TEST_OPTION_NONE, NULL},
    {"/nota_fiscal_valor_alto", test_nota_fiscal_valor_alto, setup, tear_down, MUNIT_TEST_OPTION_NONE, NULL},
    {"/nota_fiscal_venda_inexistente", test_nota_fiscal_venda_inexistente, setup, tear_down, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
    "/nota_fiscal",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}