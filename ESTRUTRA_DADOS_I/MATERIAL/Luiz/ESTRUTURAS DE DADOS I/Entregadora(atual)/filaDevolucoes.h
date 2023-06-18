typedef struct rotas Rotas;
typedef struct fila Fila; // 4 - Fila

Fila * inserirFilaDevolucao(Fila * fila, struct rotas * aux);
Fila * removerFilaDevolucao(Fila * fila, struct rotas * aux);
void mostrarFilaDevolucao(Fila *fila, struct rotas * aux);
