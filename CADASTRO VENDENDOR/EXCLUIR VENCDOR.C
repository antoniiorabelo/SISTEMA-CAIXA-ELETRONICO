void excluir_vendedor() {
    int numero;
    printf("\n--- Excluir Vendedor ---\n");
    printf("Numero do vendedor a ser excluido: ");
    scanf("%d", &numero);

    int idx = vendedor_existe(numero);
    if (idx == -1) {
        printf("Vendedor nao encontrado!\n");
        return;
    }

    for (int i = 0; i < num_vendas; i++) {
        if (vendas[i].codigo_vendedor == numero) {
            printf("Nao e possivel excluir: vendedor esta vinculado a uma ou mais vendas!\n");
            return;
        }
    }

    for (int i = idx; i < num_vendedores - 1; i++) {
        vendedores[i] = vendedores[i + 1];
    }
    num_vendedores--;

    printf("Vendedor excluido com sucesso!\n");
}
