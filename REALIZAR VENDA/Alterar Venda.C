void alterar_venda() {
    int codigo;
    printf("\n--- Alterar Venda ---\n");
    printf("Codigo da venda a ser alterada: ");
    scanf("%d", &codigo);

    int idx = venda_existe(codigo);
    if (idx == -1) {
        printf("Venda nao encontrada!\n");
        return;
    }

    printf("\nDados atuais da venda:\n");
    printf("Codigo: %d\n", vendas[idx].codigo);
    printf("Vendedor: %d\n", vendas[idx].codigo_vendedor);
    printf("Comprador: %s\n", vendas[idx].cpf_comprador);
    printf("Total: R$ %.2f\n", vendas[idx].total_venda);

    printf("\nItens da venda:\n");
    for (int i = 0; i < vendas[idx].num_itens; i++) {
        printf("  %s (Cod: %d) - %d x R$ %.2f = R$ %.2f\n",
               vendas[idx].itens[i].nome_produto, vendas[idx].itens[i].codigo_produto,
               vendas[idx].itens[i].quantidade_vendida, vendas[idx].itens[i].preco_unitario,
               vendas[idx].itens[i].preco_total);
    }

    printf("\nPara alterar uma venda, cancele a venda existente e crie uma nova.\n");
}
