void realizar_venda() {
    if (num_vendas >= MAX_VENDAS) {
        printf("Limite de vendas atingido!\n");
        return;
    }

    Venda v;
    v.num_itens = 0;
    v.total_venda = 0;

    printf("\n--- Realizar Venda ---\n");
    printf("Codigo da venda: ");
    scanf("%d", &v.codigo);

    if (venda_existe(v.codigo) != -1) {
        printf("Erro: Codigo de venda ja existe!\n");
        return;
    }

    printf("Numero do vendedor: ");
    scanf("%d", &v.codigo_vendedor);

    int idx_vendedor = vendedor_existe(v.codigo_vendedor);
    if (idx_vendedor == -1) {
        printf("Erro: Vendedor nao encontrado!\n");
        return;
    }

    limpar_buffer();
    printf("CPF do comprador: ");
    char cpf[15];
    fgets(cpf, 15, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    int idx_comprador = comprador_existe(cpf);
    if (idx_comprador == -1) {
        printf("Erro: Comprador nao encontrado!\n");
        return;
    }
    strcpy(v.cpf_comprador, cpf);

    char continuar;
    do {
        if (v.num_itens >= MAX_ITENS_VENDA) {
            printf("Limite de itens por venda atingido!\n");
            break;
        }

        ItemVenda item;

        printf("\n--- Item %d ---\n", v.num_itens + 1);
        printf("Codigo do produto: ");
        scanf("%d", &item.codigo_produto);

        int idx_produto = produto_existe(item.codigo_produto);
        if (idx_produto == -1) {
            printf("Erro: Produto nao encontrado!\n");
            continue;
        }

        printf("Quantidade: ");
        scanf("%d", &item.quantidade_vendida);

        if (item.quantidade_vendida > produtos[idx_produto].quantidade_estoque) {
            printf("Erro: Quantidade em estoque insuficiente!\n");
            printf("Estoque disponivel: %d\n", produtos[idx_produto].quantidade_estoque);
            continue;
        }

        strcpy(item.nome_produto, produtos[idx_produto].nome);
        item.preco_unitario = produtos[idx_produto].preco_venda;
        item.preco_total = item.preco_unitario * item.quantidade_vendida;

        produtos[idx_produto].quantidade_estoque -= item.quantidade_vendida;

        v.itens[v.num_itens++] = item;
        v.total_venda += item.preco_total;

        printf("Item adicionado com sucesso!\n");

        printf("Adicionar outro item? (s/n): ");
        limpar_buffer();
        continuar = tolower(getchar());
    } while (continuar == 's');

    float percentual_comissao = vendedores[idx_vendedor].percentual_comissao / 100;
    float comissao = v.total_venda * percentual_comissao;
    vendedores[idx_vendedor].comissoes += comissao;

    vendas[num_vendas++] = v;
    printf("Venda registrada com sucesso! Total: R$ %.2f\n", v.total_venda);
}
