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
//removi esse função, quando iniciamos a transportadora ja criamos a lista de clientes
//Cliente *criarListaCliente();
// optei por trocar pra void por questão de eficiencia
void cadastrarCliente(Cliente **clientes);
Cliente *buscarCliente(Cliente *clientes);
Cliente *liberarClientes(Cliente *clientes);
void mostrarCliente(Cliente* c);
void mostrarTClientes(Cliente* clientes);

//questionavel
Cliente *liberarClienteRota(Cliente *clientes);
//questionavel


//ok
Rota *criarRota();
Rota *adicionarProdutos(Cliente *clientes, Rota *rotas);


Transportadora* criarTranspotadora();



Produto *liberarProdutos(Produto *produtos);

void imprimirEscore(Transportadora *t);

Transportadora* EntregaConcluida(Transportadora* t, char cpf[]);

int compara_str(char str1[], char str2[]);

Transportadora *EntregaFracassada(Transportadora *t);
