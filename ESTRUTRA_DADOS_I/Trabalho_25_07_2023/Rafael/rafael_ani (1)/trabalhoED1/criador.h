typedef struct criador Criador;

Criador *criarListaDuplaCriadores();
Criador *cadastrarCriador(Criador *criadores);
Criador *alterarFz(Criador *criadores, int id);
Criador *removerFz(Criador *criador, int id);
Criador *removerCriador(Criador *criadores, int id);//nao é permitido remover criador com fazendas cadastradas
void mostrarCriador(Criador *criadores);
int buscarCriador(Criador *criadores);
void liberarMemoria(Criador *criadores);

/*
Desenvolva funçoes para:
- Retornar o patrimonio do criador (esse valor deve sempre estar atualizado)
- Funcao para mostrar cada criador e todos os seus respectivos atributos
- Funcao para liberar a memoria
*/