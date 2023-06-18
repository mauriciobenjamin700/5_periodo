
typedef struct cliente Cliente;
typedef struct rota Rotas;
typedef struct fila Fila;

Cliente *criarListadeCliente();
Cliente *cadastrarCliente(Cliente *clientes);
void liberarListadeClientes(Cliente *clientes);
void mostrarListadeClientes(Cliente *clientes);


Fila * CriarFiladeRotas(Fila * fila);
Fila *fila_insereRotas(Fila * fila);
Fila* fila_RemoverRota(Fila *fila);


