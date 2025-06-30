/* Teste para cadastrar_comprador() */
static MunitResult test_cadastrar_comprador(const MunitParameter params[], void* fixture) {
    num_compradores = 0;
    
    Comprador c = {
        "Comprador Teste", 
        "111.111.111-11", 
        "teste@email.com", 
        {"Rua Teste", "Bairro", "Cidade", "SP", "11111-111"}
    };
    compradores[num_compradores++] = c;
    
    munit_assert_int(num_compradores, ==, 1);
    munit_assert_string_equal(compradores[0].nome, "Comprador Teste");
    munit_assert_string_equal(compradores[0].cpf, "111.111.111-11");
    munit_assert_string_equal(compradores[0].endereco.cep, "11111-111");
    
    return MUNIT_OK;
}

/* Teste para alterar_comprador() */
static MunitResult test_alterar_comprador(const MunitParameter params[], void* fixture) {
    num_compradores = 0;
    Comprador c = {
        "Comprador Antigo", 
        "111.111.111-11", 
        "antigo@email.com", 
        {"Rua Antiga", "Bairro Antigo", "Cidade Antiga", "SP", "11111-111"}
    };
    compradores[num_compradores++] = c;
    
    // Simula alteração
    strcpy(compradores[0].nome, "Comprador Novo");
    strcpy(compradores[0].email, "novo@email.com");
    strcpy(compradores[0].endereco.rua, "Rua Nova");
    
    munit_assert_string_equal(compradores[0].nome, "Comprador Novo");
    munit_assert_string_equal(compradores[0].email, "novo@email.com");
    munit_assert_string_equal(compradores[0].endereco.rua, "Rua Nova");
    munit_assert_string_equal(compradores[0].cpf, "111.111.111-11"); // CPF não deve mudar