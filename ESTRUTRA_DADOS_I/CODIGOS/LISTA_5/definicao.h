typedef struct pessoa Pessoa;


//void servidor(int sinal, Pessoa *vetor);


Pessoa add_pessoa(char nome[], int idade, float altura);

// busca no vetor de Pessoa a Pessoa que possui a altura passada e retorna o indice referente a ela
int buscar_pessoa(float altura, Pessoa *vetor, int tamanho);

// remove a Pessoa do vetor passado de acordo com o indice
int remover_pessoa(int indice,Pessoa *vetor, int tamanho);

// percorre o vetor de pessoas e printa cada Pessoa dentro do vetor
void mostrar_pessoas(Pessoa *vetor, int tamanho);

// mostrar uma Pessoa que possuia uma altura especifica informada
void mostrar_pessoa(float altura, Pessoa *vetor, int tamanho);
