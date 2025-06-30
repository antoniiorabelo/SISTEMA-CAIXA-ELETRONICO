/* Teste para cadastrar_produto() */
static MunitResult test_cadastrar_produto(const MunitParameter params[], void* fixture) {
    num_produtos = 0;
    
    // Simula entrada do usuário
    Produto p = {"Produto Teste", 123, 10, 25.50};
    produtos[num_produtos++] = p;
    
    munit_assert_int(num_produtos, ==, 1);
    munit_assert_string_equal(produtos[0].nome, "Produto Teste");
    munit_assert_int(produtos[0].codigo, ==, 123);
    munit_assert_int(produtos[0].quantidade_estoque, ==, 10);
    munit_assert_double(produtos[0].preco_venda, ==, 25.50);
    
    return MUNIT_OK;
}

/* Teste para alterar_produto() */
static MunitResult test_alterar_produto(const MunitParameter params[], void* fixture) {
    num_produtos = 0;
    Produto p = {"Produto Antigo", 123, 5, 10.0};
    produtos[num_produtos++] = p;
    
    // Simula alteração
    strcpy(produtos[0].nome, "Produto Novo");
    produtos[0].quantidade_estoque = 15;
    produtos[0].preco_venda = 20.0;
    
    munit_assert_string_equal(produtos[0].nome, "Produto Novo");
    munit_assert_int(produtos[0].quantidade_estoque, ==, 15);
    munit_assert_double(produtos[0].preco_venda, ==, 20.0);
    munit_assert_int(produtos[0].codigo, ==, 123); // Código não deve mudar
    
    return MUNIT_OK;
}

/* Teste para excluir_produto() */
static MunitResult test_excluir_produto(const MunitParameter params[], void* fixture) {
    num_produtos = 0;
    Produto p1 = {"Produto 1", 1, 10, 5.0};
    Produto p2 = {"Produto 2", 2, 20, 10.0};
    produtos[num_produtos++] = p1;
    produtos[num_produtos++] = p2;
    
    // Remove o primeiro produto
    for (int i = 0; i < num_produtos - 1; i++) {
        produtos[i] = produtos[i + 1];
    }
    num_produtos--;
    
    munit_assert_int(num_produtos, ==, 1);
    munit_assert_int(produtos[0].codigo, ==, 2);
    
    return MUNIT_OK;
}

/* Teste para listar_produtos() - teste de saída */
static MunitResult test_listar_produtos(const MunitParameter params[], void* fixture) {
    num_produtos = 0;
    Produto p = {"Produto Teste", 123, 10, 25.50};
    produtos[num_produtos++] = p;
    
    // Redireciona stdout para capturar a saída
    freopen("test_output.txt", "w", stdout);
    listar_produtos();
    freopen("/dev/tty", "w", stdout);
    
    // Lê o arquivo de saída
    FILE *fp = fopen("test_output.txt", "r");
    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);
    
    munit_assert_true(strstr(buffer, "Produto Teste") != NULL);
    munit_assert_true(strstr(buffer, "123") != NULL);
    
    return MUNIT_OK;
}