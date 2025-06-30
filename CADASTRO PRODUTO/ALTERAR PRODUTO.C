void alterar_produto() {
    int codigo;
    printf("\n--- Alterar Produto ---\n");
    printf("Codigo do produto a ser alterado: ");
    scanf("%d", &codigo);
    limpar_buffer();

    int idx = produto_existe(codigo);
    if (idx == -1) {
        printf("Produto nao encontrado!\n");
        return;
    }

    printf("\nDados atuais do produto:\n");
    printf("Nome: %s\n", produtos[idx].nome);
    printf("Codigo: %d\n", produtos[idx].codigo);
    printf("Quantidade em estoque: %d\n", produtos[idx].quantidade_estoque);
    printf("Preco de venda: %.2f\n", produtos[idx].preco_venda);

    printf("\nNovos dados (deixe em branco para manter o valor atual):\n");

    char novo_nome[50];
    printf("Nome [%s]: ", produtos[idx].nome);
    fgets(novo_nome, 50, stdin);
    if (strlen(novo_nome) > 1) {
        novo_nome[strcspn(novo_nome, "\n")] = '\0';
        strcpy(produtos[idx].nome, novo_nome);
    }

    char novo_estoque[20];
    printf("Quantidade em estoque [%d]: ", produtos[idx].quantidade_estoque);
    fgets(novo_estoque, 20, stdin);
    if (strlen(novo_estoque) > 1) {
        produtos[idx].quantidade_estoque = atoi(novo_estoque);
    }

    char novo_preco[20];
    printf("Preco de venda [%.2f]: ", produtos[idx].preco_venda);
    fgets(novo_preco, 20, stdin);
    if (strlen(novo_preco) > 1) {
        produtos[idx].preco_venda = atof(novo_preco);
    }

    printf("Produto alterado com sucesso!\n");
}
