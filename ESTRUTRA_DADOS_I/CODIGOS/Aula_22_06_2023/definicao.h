// lista encadeadas estaticas
typedef struct pessoa Pessoa;
void inserir(Pessoa* lista);

void mostrarElemento(Pessoa lista);
void mostrarTodaLista(Pessoa* lista, int tamanho);
void removerPessoa(Pessoa* lista);
int buscarPessoa(Pessoa* lista);
void inserirOrdenado(Pessoa* lista);
int contarElementos(Pessoa* lista);
