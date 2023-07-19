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
//ok
Cliente *criarListaCliente();
Cliente *inserirCliente(Cliente *clientes);
Cliente *buscarCliente(Cliente *clientes, char cpf[]);
Cliente *liberarClientes(Cliente *clientes);
//questionavel
Cliente *liberarClienteRota(Cliente *clientes);
//questionavel
void mostrarTodos(Cliente *clientes);
void mostrarCliente(Cliente *clientes);

//ok
Rota *criarRota();
Rota *adicionarProdutos(Cliente *clientes, Rota *rotas);
Rota *inserirRota(Rota *rotas, Cliente *clientes);

Rota *liberarRota(Rota *rotas);

Produto *liberarProdutos(Produto *produtos);

void imprimirEscore();

Transportadora* EntregaConcluida(Transportadora* t, char cpf[]);

int compara_str(char str1[], char str2[]);

Transportadora *EntregaFracassada(Transportadora *t, char cpf[]);
