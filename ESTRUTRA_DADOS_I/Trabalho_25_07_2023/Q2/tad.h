typedef struct produto Produto;
typedef struct cliente Cliente;
typedef struct rota Rota;
typedef struct transportadora Transportadora;


void cadastrarCliente(Cliente **clientes);
Cliente *buscarCliente(Cliente *clientes);
void mostrarCliente(Cliente* c);
void mostrarTClientes(Cliente* clientes);
void removerCliente(Cliente *clientes);
void liberarCliente(Cliente *cliente);
int compara_str(char str1[], char str2[]);
Rota *criarRota();
void ativarRota(Transportadora* t);
void concluirRota(Transportadora* t);
void clienteRota(Transportadora* t);
void produtoCliente();
Transportadora* criarTranspotadora();
void imprimirEscore(Transportadora *t);
Transportadora *EntregaConcluida(Transportadora *t);
Transportadora *Falha1(Transportadora *t);
void liberarProdutos(Produto *produtos);

void sucesso(Transportadora* t);

Transportadora *Falha1(Transportadora *t);
Transportadora *Falha2(Transportadora *t);
Transportadora *Falha3(Transportadora *t, FilaDevolucao *fila);
