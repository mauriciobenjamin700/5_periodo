typedef struct cliente Cliente;
typedef struct endereco Endereco;
typedef struct rota Rota;
typedef struct produto Produto;
typedef struct devolucao Devolucao;
typedef struct pilha Pilha;

Cliente *criarListaCliente();
Cliente *inserirCliente(Cliente *clientes);
Cliente *buscarCliente(Cliente *clientes, int id);
Cliente *liberarCliente(Cliente *clientes);
Cliente *liberarClienteRota(Cliente *clientes);
int vazio(Cliente *clientes);
void mostrarTodos(Cliente *clientes);
void mostrarCliente(Cliente *clientes);

Rota *criarRota();
Rota *adiconarProdutos(Cliente *clientes, Rota *rotas);
Rota *inserirRota(Rota *rotas, Cliente *clientes);
Rota *entregarFila(Rota *rotas, Pilha *pilhas);
Rota *liberarRota(Rota *rotas);
void mostrarRotas(Rota *rotas);
void mostrarProduto(Produto *produtos);

void removerPilha(Pilha *pilhas);
Produto *liberarProdutos(Produto *produtos);
Devolucao *criarFilaDevolucao();
Devolucao *filaDevolucao(Devolucao *devolucao, Rota *rota);
void inserirPilha(Rota *rotas, Pilha *pilhas);
Pilha *criarPilha();
void mostrarPilha(Pilha *pilhas);

void imprimirEscore();