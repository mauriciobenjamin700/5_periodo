typedef struct criador Criador;

Criador *criarListaDuplaCriadores();
Criador *cadastrarCriador(Criador *criadores);
void removerCriador(Criador **criador);//nao é permitido remover criador com fazendas cadastradas
void mostarCriador(Criador* criador);
void mostrarTodos(Criador *criadores);
Criador* buscarCriador(Criador *criadores);
void liberarMemoria(Criador *criadores);

/*
Desenvolva funçoes para:
- Retornar o patrimonio do criador (esse valor deve sempre estar atualizado)
- Funcao para mostrar cada criador e todos os seus respectivos atributos
- Funcao para liberar a memoria
*/