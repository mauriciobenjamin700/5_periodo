typedef struct pilha Pilha; // 3 - Pilha
typedef struct rota Rotas;

Pilha * inserirPilhaDevolucao(Pilha * pilhas, struct rotas * aux);
Pilha * removerPilhaDevolucao(Pilha * pilhas, struct rotas * aux);
void mostrarPilhaDevolucao(Pilha *pilhas, struct rotas * aux);