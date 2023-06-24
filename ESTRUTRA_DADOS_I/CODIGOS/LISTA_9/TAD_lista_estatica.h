typedef struct pessoa Pessoa;
void inserirPessoaInicio(Pessoa *lista);
void inserirPessoaFim(Pessoa *lista);
void inserirPessoaOrdenado(Pessoa *lista); //utilizar a idade para inserir em ordem crescente

void mostrarPessoa(Pessoa p);
void mostrarTodasPessoas(Pessoa *lista);
int contrarPessoasNaLista(Pessoa *lista); //troquei para int pois não fazia sentido ser void
int buscarPessoa(Pessoa *lista); //troquei para int pois não fazia sentido ser void
void removerPessoa(Pessoa *lista);
void liberarMemoria(Pessoa *lista);

