typedef struct Pessoa pessoa;
Pessoa* createVet();
Pessoa* adicionarPessoa(Pessoa* vet, int* tamanho, char* nome, int idade, float altura);
void imprimePessoas(Pessoa *vet, int tamanho);
int buscarPessoaAltura(Pessoa *vet, int tamanho, float altura);
void mostrarPessoaAltura(Pessoa *vet, int tamanho, float altura);
Pessoa* limpaMemoria(Pessoa *vet);
