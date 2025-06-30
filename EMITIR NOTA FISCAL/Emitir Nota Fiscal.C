void emitir_nota_fiscal() {
    int codigo_venda;

    printf("\n--- Emissao de Nota Fiscal ---\n");
    printf("Codigo da venda: ");
    scanf("%d", &codigo_venda);

    int idx_venda = venda_existe(codigo_venda);
    if (idx_venda == -1) {
        printf("Erro: Venda nao encontrada!\n");
        return;
    }

    Venda v = vendas[idx_venda];

    int idx_comprador = comprador_existe(v.cpf_comprador);
    Comprador c = compradores[idx_comprador];

    int idx_vendedor = vendedor_existe(v.codigo_vendedor);
    Vendedor vend = vendedores[idx_vendedor];

    float frete = 0;
    if (v.total_venda <= 100.00) {
        frete = 30.00;
    } else if (v.total_venda <= 300.00) {
        frete = 20.00;
    }

    float total_geral = v.total_venda + frete;

    printf("\n=============================\n");
    printf("        NOTA FISCAL\n");
    printf("=============================\n");
    printf("Venda: %d\n", v.codigo);
    printf("Vendedor: %s (Num: %d)\n", vend.nome, vend.numero);
    printf("\nDados do Comprador:\n");
    printf("Nome: %s\n", c.nome);
    printf("CPF: %s\n", c.cpf);
    printf("Email: %s\n", c.email);
    printf("Endereco de entrega:\n");
    printf("%s, %s - %s/%s - CEP: %s\n", c.endereco.rua, c.endereco.bairro,
           c.endereco.cidade, c.endereco.estado, c.endereco.cep);

    printf("\nItens da Venda:\n");
    printf("------------------------------------------------------------\n");
    printf("Descricao                Codigo  Qtd  Unitario    Total\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < v.num_itens; i++) {
        printf("%-24s %-7d %-4d %-9.2f %-9.2f\n",
               v.itens[i].nome_produto, v.itens[i].codigo_produto,
               v.itens[i].quantidade_vendida, v.itens[i].preco_unitario,
               v.itens[i].preco_total);
    }

    printf("------------------------------------------------------------\n");
    printf("Subtotal: R$ %.2f\n", v.total_venda);
    printf("Frete: R$ %.2f\n", frete);
    printf("TOTAL GERAL: R$ %.2f\n", total_geral);
    printf("=============================\n");
}
