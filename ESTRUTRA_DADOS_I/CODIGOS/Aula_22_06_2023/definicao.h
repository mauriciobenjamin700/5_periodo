// lista encadeadas estaticas
typedef struct pessoa Pessoa;
void inserirPessoaInicio(Pessoa *lista);
void inserirPessoaFim(Pessoa *lista);
void inserirPessoaOrdenado(Pessoa *lista); //utilizar a idade para inserir em ordem crescente

void mostrarPessoa(Pessoa p);
void mostrarTodasPessoas(Pessoa *lista);
void contrarPessoasNaLista(Pessoa *lista);
int buscarPessoa(Pessoa* lista);
void removerPessoa(Pessoa *lista);
int contarElementos(Pessoa* lista);
void liberarMemoria(Pessoa *lista);

void inserir(Pessoa* lista);



