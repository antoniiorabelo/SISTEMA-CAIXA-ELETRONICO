void listar_compradores() {
    printf("\n--- Lista de Compradores ---\n");
    for (int i = 0; i < num_compradores; i++) {
        printf("CPF: %s | Nome: %s | Email: %s\n",
               compradores[i].cpf, compradores[i].nome, compradores[i].email);
        printf("Endereco: %s, %s - %s/%s - CEP: %s\n",
               compradores[i].endereco.rua, compradores[i].endereco.bairro,
               compradores[i].endereco.cidade, compradores[i].endereco.estado,
               compradores[i].endereco.cep);
    }
}
