typedef struct fazenda Fazenda;
typedef struct endereco Endereco;

Fazenda *criarListaEncadeadaCircularFazendas();
Fazenda *cadastrarFazenda(Fazenda *fazendas);
Fazenda *removerFazenda(Fazenda *fazendas, int id);//nao permitir remover fazenda se houver animais cadastrados
Fazenda *alterarFazenda(Fazenda *fazendas, int id);//alterar dados cadastrais da fazenda. exemplo: nome e endereco; 
int buscarFazenda(Fazenda *fazendas);
void liberarMemoriaCircular(Fazenda *fazendas);
void mostrarFazenda(Fazenda *fazendas);

/*
Desenvolva funcoes que, dado uma FAZENDA, informar
- Quantidade de animais por sexo;
- Peso total em arroba (isto é, a cada 15 KG)
- Valor total da fazenda considerando o preço da arroba de R$ 267,50
- lista de animais por tipo de status
- Funcao para liberar a memoria
*/
void mostrar(Fazenda* f);

                                