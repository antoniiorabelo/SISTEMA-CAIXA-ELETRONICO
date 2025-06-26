void cadastrar_vendedor() {
    if (num_vendedores >= MAX_VENDEDORES) {
        printf("Limite de vendedores atingido!\n");
        return;
    }

    Vendedor v;

    printf("\n--- Cadastro de Vendedor ---\n");
    printf("Nome: ");
    fgets(v.nome, 50, stdin);
    v.nome[strcspn(v.nome, "\n")] = '\0';

    printf("Numero: ");
    scanf("%d", &v.numero);

    if (vendedor_existe(v.numero) != -1) {
        printf("Erro: Numero de vendedor ja existe!\n");
        return;
    }

    printf("Salario fixo: ");
    scanf("%f", &v.salario_fixo);

    printf("Percentual de comissao (%%): ");
    scanf("%f", &v.percentual_comissao);

    v.comissoes = 0;
    vendedores[num_vendedores++] = v;
    printf("Vendedor cadastrado com sucesso!\n");
}
