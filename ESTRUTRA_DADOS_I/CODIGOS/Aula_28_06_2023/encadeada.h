typedef struct pessoa Pessoa;
//Pessoa* inserirInicio(Pessoa* l);
void criarLista(Pessoa* lista);
void inserirPessoaInicio(Pessoa* lista);
void inserirPessoaFim(Pessoa* lista);
void inserirPessoaOrdenad(Pessoa* lista); //utilizar a idade para inserir em ordem crescente
void mostrarPessoa(Pessoa p); //ok
void mostrarTodasPessoas(Pessoa *lista); //ok
int contrarPessoasNaLista(Pessoa* lista, int t); 
int buscarPessoa(Pessoa* lista);
void removerPessoa(Pessoa* lista);
void liberarMemoria(Pessoa* lista);