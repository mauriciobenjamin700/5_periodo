typedef struct conta Conta;

Conta * criarListaEstatica();
void inserirElemento(Conta * ListarContas, int pos, int tamanho);
void removerElemento(Conta * ListarContas, int tamanho); // remover pelo "numero conta"
int buscarElemento(Conta * ListarContas, int tamanho, int num_conta);
void mostrarElemento(Conta elemento);
void mostrarTodosElementos(Conta *Lista,int tamanho);
void liberarMemoria(Conta *listaContas);
void mostrarSaldo(Conta * lista, int num_conta, int tamanho);
void mostrarSaldo(Conta * lista, int num_conta, int tamanho);