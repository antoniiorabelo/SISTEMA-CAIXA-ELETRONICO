void listar_vendedores() {
    printf("\n--- Lista de Vendedores ---\n");
    for (int i = 0; i < num_vendedores; i++) {
        printf("Numero: %d | Nome: %s | Salario: R$ %.2f | Comissao: %.2f%% | Comissoes Acumuladas: R$ %.2f\n",
               vendedores[i].numero, vendedores[i].nome,
               vendedores[i].salario_fixo, vendedores[i].percentual_comissao,
               vendedores[i].comissoes);
    }
}
