void listar_produtos() {
    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < num_produtos; i++) {
        printf("Codigo: %d | Nome: %s | Estoque: %d | Preco: R$ %.2f\n",
               produtos[i].codigo, produtos[i].nome,
               produtos[i].quantidade_estoque, produtos[i].preco_venda);
    }
}
