/* Teste para produto_existe() */
static MunitResult test_produto_existe(const MunitParameter params[], void* fixture) {
    num_produtos = 0;
    Produto p1 = {"Produto 1", 1, 10, 5.0};
    produtos[num_produtos++] = p1;
    
    munit_assert_int(produto_existe(1), ==, 0);  // Deve existir no índice 0
    munit_assert_int(produto_existe(99), ==, -1); // Não deve existir
    
    return MUNIT_OK;
}

/* Teste para vendedor_existe() */
static MunitResult test_vendedor_existe(const MunitParameter params[], void* fixture) {
    num_vendedores = 0;
    Vendedor v1 = {"Vendedor 1", 1, 1500, 0, 5};
    vendedores[num_vendedores++] = v1;
    
    munit_assert_int(vendedor_existe(1), ==, 0);
    munit_assert_int(vendedor_existe(99), ==, -1);
    
    return MUNIT_OK;
}

/* Teste para comprador_existe() */
static MunitResult test_comprador_existe(const MunitParameter params[], void* fixture) {
    num_compradores = 0;
    Comprador c1 = {"Comprador 1", "111.111.111-11", "email@teste.com", {"Rua A", "Centro", "Cidade", "SP", "11111-111"}};
    compradores[num_compradores++] = c1;
    
    munit_assert_int(comprador_existe("111.111.111-11"), ==, 0);
    munit_assert_int(comprador_existe("999.999.999-99"), ==, -1);
    
    return MUNIT_OK;
}

/* Teste para venda_existe() */
static MunitResult test_venda_existe(const MunitParameter params[], void* fixture) {
    num_vendas = 0;
    Venda v1 = {1, 1, "111.111.111-11", {0}, 0, 0};
    vendas[num_vendas++] = v1;
    
    munit_assert_int(venda_existe(1), ==, 0);
    munit_assert_int(venda_existe(99), ==, -1);
    
    return MUNIT_OK;
}

/* Teste para validar_cep() */
static MunitResult test_validar_cep(const MunitParameter params[], void* fixture) {
    munit_assert_true(validar_cep("12345678"));
    munit_assert_true(validar_cep("12345-678"));
    munit_assert_false(validar_cep("1234567"));
    munit_assert_false(validar_cep("123456789"));
    munit_assert_false(validar_cep("1234x678"));
    
    return MUNIT_OK;
}

/* Teste para formatar_cep() */
static MunitResult test_formatar_cep(const MunitParameter params[], void* fixture) {
    char cep1[10] = "12345678";
    formatar_cep(cep1);
    munit_assert_string_equal(cep1, "12345-678");
    
    char cep2[10] = "12345-678";
    formatar_cep(cep2);
    munit_assert_string_equal(cep2, "12345-678");
    
    return MUNIT_OK;
}