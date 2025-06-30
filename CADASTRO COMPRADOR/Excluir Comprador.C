void excluir_comprador() {
    char cpf[15];
    printf("\n--- Excluir Comprador ---\n");
    printf("CPF do comprador a ser excluido: ");
    fgets(cpf, 15, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    int idx = comprador_existe(cpf);
    if (idx == -1) {
        printf("Comprador nao encontrado!\n");
        return;
    }

    for (int i = 0; i < num_vendas; i++) {
        if (strcmp(vendas[i].cpf_comprador, cpf) == 0) {
            printf("Nao e possivel excluir: comprador esta vinculado a uma ou mais vendas!\n");
            return;
        }
    }

    for (int i = idx; i < num_compradores - 1; i++) {
        compradores[i] = compradores[i + 1];
    }
    num_compradores--;

    printf("Comprador excluido com sucesso!\n");
}
