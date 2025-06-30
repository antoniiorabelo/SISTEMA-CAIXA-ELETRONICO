void alterar_vendedor() {
    int numero;
    printf("\n--- Alterar Vendedor ---\n");
    printf("Numero do vendedor a ser alterado: ");
    scanf("%d", &numero);
    limpar_buffer();

    int idx = vendedor_existe(numero);
    if (idx == -1) {
        printf("Vendedor nao encontrado!\n");
        return;
    }

    printf("\nDados atuais do vendedor:\n");
    printf("Nome: %s\n", vendedores[idx].nome);
    printf("Numero: %d\n", vendedores[idx].numero);
    printf("Salario fixo: %.2f\n", vendedores[idx].salario_fixo);
    printf("Percentual de comissao: %.2f%%\n", vendedores[idx].percentual_comissao);

    printf("\nNovos dados (deixe em branco para manter o valor atual):\n");

    char novo_nome[50];
    printf("Nome [%s]: ", vendedores[idx].nome);
    fgets(novo_nome, 50, stdin);
    if (strlen(novo_nome) > 1) {
        novo_nome[strcspn(novo_nome, "\n")] = '\0';
        strcpy(vendedores[idx].nome, novo_nome);
    }

    char novo_salario[20];
    printf("Salario fixo [%.2f]: ", vendedores[idx].salario_fixo);
    fgets(novo_salario, 20, stdin);
    if (strlen(novo_salario) > 1) {
        vendedores[idx].salario_fixo = atof(novo_salario);
    }

    printf("Percentual de comissao (FIXO): %.2f%%\n", vendedores[idx].percentual_comissao);

    printf("Vendedor alterado com sucesso!\n");
}
