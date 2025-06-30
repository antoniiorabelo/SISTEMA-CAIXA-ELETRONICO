void cadastrar_comprador() {
    if (num_compradores >= MAX_COMPRADORES) {
        printf("Limite de compradores atingido!\n");
        return;
    }

    Comprador c;

    printf("\n--- Cadastro de Comprador ---\n");
    printf("Nome: ");
    fgets(c.nome, 50, stdin);
    c.nome[strcspn(c.nome, "\n")] = '\0';

    printf("CPF: ");
    fgets(c.cpf, 15, stdin);
    c.cpf[strcspn(c.cpf, "\n")] = '\0';

    if (comprador_existe(c.cpf) != -1) {
        printf("Erro: CPF ja cadastrado!\n");
        return;
    }

    printf("Email: ");
    fgets(c.email, 50, stdin);
    c.email[strcspn(c.email, "\n")] = '\0';

    printf("--- Endereco ---\n");
    printf("Rua: ");
    fgets(c.endereco.rua, 50, stdin);
    c.endereco.rua[strcspn(c.endereco.rua, "\n")] = '\0';

    printf("Bairro: ");
    fgets(c.endereco.bairro, 30, stdin);
    c.endereco.bairro[strcspn(c.endereco.bairro, "\n")] = '\0';

    printf("Cidade: ");
    fgets(c.endereco.cidade, 30, stdin);
    c.endereco.cidade[strcspn(c.endereco.cidade, "\n")] = '\0';

    printf("Estado (sigla): ");
    fgets(c.endereco.estado, 3, stdin);
    c.endereco.estado[strcspn(c.endereco.estado, "\n")] = '\0';
    limpar_buffer();

    int cep_valido = 0;
    do {
        printf("CEP (formato: 12345-678 ou 12345678): ");
        fgets(c.endereco.cep, 10, stdin);
        c.endereco.cep[strcspn(c.endereco.cep, "\n")] = '\0';

        char *p = c.endereco.cep;
        while (*p) {
            if (isspace(*p)) {
                memmove(p, p+1, strlen(p));
            } else {
                p++;
            }
        }

        cep_valido = validar_cep(c.endereco.cep);

        if (cep_valido) {
            formatar_cep(c.endereco.cep);
        } else {
            printf("CEP invalido! Deve conter exatamente 8 digitos no formato 12345-678 ou 12345678.\n");
        }
    } while (!cep_valido);

    compradores[num_compradores++] = c;
    printf("Comprador cadastrado com sucesso!\n");
}
