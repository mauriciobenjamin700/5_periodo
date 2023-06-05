typedef struct pessoa Pessoa;

Pessoa* criar_vetor();

// adiciona uma Pessoa usando o ponteiro no vetor de pessoas
void servidor(int sinal);

void add_pessoa();

// busca no vetor de Pessoa a Pessoa que possui a altura passada e retorna o indice referente a ela
int buscar_pessoa(float altura);

// remove a Pessoa do vetor passado de acordo com o indice
int remover_pessoa(int indice);

// percorre o vetor de pessoas e printa cada Pessoa dentro do vetor
void mostrar_pessoas();

// mostrar uma Pessoa que possuia uma altura especifica informada
void mostrar_pessoa(float altura);