void alterar_comprador() {
    char cpf[15];
    printf("\n--- Alterar Comprador ---\n");
    printf("CPF do comprador a ser alterado: ");
    fgets(cpf, 15, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    int idx = comprador_existe(cpf);
    if (idx == -1) {
        printf("Comprador nao encontrado!\n");
        return;
    }

    printf("\nDados atuais do comprador:\n");
    printf("Nome: %s\n", compradores[idx].nome);
    printf("CPF: %s\n", compradores[idx].cpf);
    printf("Email: %s\n", compradores[idx].email);
    printf("Endereco: %s, %s - %s/%s - CEP: %s\n",
           compradores[idx].endereco.rua, compradores[idx].endereco.bairro,
           compradores[idx].endereco.cidade, compradores[idx].endereco.estado,
           compradores[idx].endereco.cep);

    printf("\nNovos dados (deixe em branco para manter o valor atual):\n");

    char novo_nome[50];
    printf("Nome [%s]: ", compradores[idx].nome);
    fgets(novo_nome, 50, stdin);
    if (strlen(novo_nome) > 1) {
        novo_nome[strcspn(novo_nome, "\n")] = '\0';
        strcpy(compradores[idx].nome, novo_nome);
    }

    char novo_email[50];
    printf("Email [%s]: ", compradores[idx].email);
    fgets(novo_email, 50, stdin);
    if (strlen(novo_email) > 1) {
        novo_email[strcspn(novo_email, "\n")] = '\0';
        strcpy(compradores[idx].email, novo_email);
    }

    printf("\n--- Endereco ---\n");
    char nova_rua[50];
    printf("Rua [%s]: ", compradores[idx].endereco.rua);
    fgets(nova_rua, 50, stdin);
    if (strlen(nova_rua) > 1) {
        nova_rua[strcspn(nova_rua, "\n")] = '\0';
        strcpy(compradores[idx].endereco.rua, nova_rua);
    }

    char novo_bairro[30];
    printf("Bairro [%s]: ", compradores[idx].endereco.bairro);
    fgets(novo_bairro, 30, stdin);
    if (strlen(novo_bairro) > 1) {
        novo_bairro[strcspn(novo_bairro, "\n")] = '\0';
        strcpy(compradores[idx].endereco.bairro, novo_bairro);
    }

    char nova_cidade[30];
    printf("Cidade [%s]: ", compradores[idx].endereco.cidade);
    fgets(nova_cidade, 30, stdin);
    if (strlen(nova_cidade) > 1) {
        nova_cidade[strcspn(nova_cidade, "\n")] = '\0';
        strcpy(compradores[idx].endereco.cidade, nova_cidade);
    }

    char novo_estado[3];
    printf("Estado [%s]: ", compradores[idx].endereco.estado);
    fgets(novo_estado, 3, stdin);
    if (strlen(novo_estado) > 1) {
        novo_estado[strcspn(novo_estado, "\n")] = '\0';
        strcpy(compradores[idx].endereco.estado, novo_estado);
    }
    limpar_buffer();

    char novo_cep[10];
    printf("CEP [%s] (deixe em branco para manter): ", compradores[idx].endereco.cep);
    fgets(novo_cep, 10, stdin);
    if (strlen(novo_cep) > 1) {
        novo_cep[strcspn(novo_cep, "\n")] = '\0';
        
        char *p = novo_cep;
        while (*p) {
            if (isspace(*p)) {
                memmove(p, p+1, strlen(p));
            } else {
                p++;
            }
        }
        
        if (validar_cep(novo_cep)) {
            formatar_cep(novo_cep);
            strcpy(compradores[idx].endereco.cep, novo_cep);
        } else {
            printf("CEP invalido! Mantendo o CEP anterior.\n");
        }
    }

    printf("Comprador alterado com sucesso!\n");
}
