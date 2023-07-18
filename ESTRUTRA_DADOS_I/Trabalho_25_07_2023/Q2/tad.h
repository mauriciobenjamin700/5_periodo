typedef struct produto Produto;
typedef struct cliente Cliente;
typedef struct rota Rota;
typedef struct transportadora Transportadora;

/* 
cadastro eficiente de clientes usando lista encadeada simples
rota de entrega deve usar fila
pode haver mais de uma entrega no mesmo endereço
*/
/* se entrega falhar 
    vai para uma pilha de entregas falhas
    apenas 3 tentativas de entrega
    se falhar mais de 3
        sai da pilha e forma uma Fila de devolução
    
    Para que a Pilha de não-entregas seja processado, é  necessário  que  todas  as  demais  encomendas  nas  rotas constantes naFila sejam processadas. 
*/

/*
Entregas efetuadas na primeira tentativa: 5 pontos;○ Entregas efetuadas na segunda tentativa: 3 pontos;○ Entregas efetuadas na terceira tentativa: 2 pontos;○ Entregas não efetuadas e devolvidas para a Fila de Devolução de Produtos: -0,8 pontos(subtrair 0,8)
*/

Cliente *criarListaCliente();
Cliente *inserirCliente(Cliente *clientes);
Cliente *buscarCliente(Cliente *clientes, char cpf[]);
Cliente *liberarClientes(Cliente *clientes);
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