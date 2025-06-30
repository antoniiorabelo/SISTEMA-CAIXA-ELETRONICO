void cadastrar_produto() {
    if (num_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto p;

    printf("\n--- Cadastro de Produto ---\n");
    printf("Nome: ");
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';

    printf("Codigo: ");
    scanf("%d", &p.codigo);

    if (produto_existe(p.codigo) != -1) {
        printf("Erro: Codigo de produto ja existe!\n");
        return;
    }

    printf("Quantidade em estoque: ");
    scanf("%d", &p.quantidade_estoque);

    printf("Preco de venda: ");
    scanf("%f", &p.preco_venda);

    produtos[num_produtos++] = p;
    printf("Produto cadastrado com sucesso!\n");
}
