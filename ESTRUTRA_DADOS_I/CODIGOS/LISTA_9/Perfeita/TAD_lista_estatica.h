typedef struct pessoa Pessoa;
Pessoa* iniciar(); //precisei criar a função de iniciar para gerar a lista que trabalhei na "main"
void inserirPessoaInicio(Pessoa *lista);
void inserirPessoaFim(Pessoa *lista);
void inserirPessoaOrdenado(Pessoa *lista); //utilizar a idade para inserir em ordem crescente

void mostrarPessoa(Pessoa p);
void mostrarTodasPessoas(Pessoa *lista);
int contrarPessoasNaLista(Pessoa *lista); //troquei para int pois não fazia sentido ser void
int buscarPessoa(Pessoa *lista); //troquei para int pois não fazia sentido ser void
void removerPessoa(Pessoa *lista);
void liberarMemoria(Pessoa *lista);

