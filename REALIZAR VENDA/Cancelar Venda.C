void cancelar_venda() {
    int codigo;
    printf("\n--- Cancelar Venda ---\n");
    printf("Codigo da venda a ser cancelada: ");
    scanf("%d", &codigo);

    int idx = venda_existe(codigo);
    if (idx == -1) {
        printf("Venda nao encontrada!\n");
        return;
    }

    for (int i = 0; i < vendas[idx].num_itens; i++) {
        int cod_prod = vendas[idx].itens[i].codigo_produto;
        int qtd = vendas[idx].itens[i].quantidade_vendida;
        
        int idx_prod = produto_existe(cod_prod);
        if (idx_prod != -1) {
            produtos[idx_prod].quantidade_estoque += qtd;
        }
    }

    int idx_vendedor = vendedor_existe(vendas[idx].codigo_vendedor);
    if (idx_vendedor != -1) {
        float percentual = vendedores[idx_vendedor].percentual_comissao / 100;
        vendedores[idx_vendedor].comissoes -= vendas[idx].total_venda * percentual;
    }

    for (int i = idx; i < num_vendas - 1; i++) {
        vendas[i] = vendas[i + 1];
    }
    num_vendas--;

    printf("Venda cancelada com sucesso!\n");
}
