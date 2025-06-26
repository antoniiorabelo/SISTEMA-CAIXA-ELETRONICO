void excluir_produto() {
    int codigo;
    printf("\n--- Excluir Produto ---\n");
    printf("Codigo do produto a ser excluido: ");
    scanf("%d", &codigo);

    int idx = produto_existe(codigo);
    if (idx == -1) {
        printf("Produto nao encontrado!\n");
        return;
    }

    for (int i = 0; i < num_vendas; i++) {
        for (int j = 0; j < vendas[i].num_itens; j++) {
            if (vendas[i].itens[j].codigo_produto == codigo) {
                printf("Nao e possivel excluir: produto esta vinculado a uma ou mais vendas!\n");
                return;
            }
        }
    }

    for (int i = idx; i < num_produtos - 1; i++) {
        produtos[i] = produtos[i + 1];
    }
    num_produtos--;

    printf("Produto excluido com sucesso!\n");
}
