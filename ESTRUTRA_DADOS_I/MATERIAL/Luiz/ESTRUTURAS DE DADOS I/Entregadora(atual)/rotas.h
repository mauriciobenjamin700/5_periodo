typedef struct rotas Rotas;
typedef struct fila Fila; // 2 - Fila

Fila *CriarFiladeRotas(Fila * fila);
Fila *fila_insereRotas(Fila * fila);
Fila *fila_RemoverRota(Fila *fila, Rotas *aux);
void mostrarRotas(Fila *fila);

