typedef struct pessoa Pessoa;

Pessoa* criarLista(Pessoa* lista);
Pessoa* inserirPessoaInicio(Pessoa* lista);
Pessoa* inserirPessoaOrdenado(Pessoa* lista);
Pessoa* inserirPessoaFim(Pessoa* lista);
int buscarPessoa(Pessoa *lista);
void removerPessoa(Pessoa *lista);
int contrarPessoasNaLista(Pessoa *lista);
void mostrarPessoa(Pessoa p);
void mostrarTodasPessoas(Pessoa *lista);
void liberarMemoria(Pessoa *lista);



