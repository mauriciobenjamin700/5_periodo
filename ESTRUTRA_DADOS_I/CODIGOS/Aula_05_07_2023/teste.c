//lista circular
/*

struct pessoa 
{
    char nome[30];
    float altura;
    int idade,id;
    struct pessoa *prox;
};

void imprimir(Pessoa *l)
{
    Pessoa *p = l;

    if(p)
    {
        do
        {
            mostrarPessoa(p);
            p = p->prox;
        }
        while(p!=l)
    }
}


Pessoa *inserir(Pessoa* lista) //insere no fim
{
    srand(time(NULL));
    Pessoa *new = (Pessoa*) malloc(sizeof(Pessoa));
    Pessoa* aux;

    if(new)
    {


        new->id = rand() % 1000 + 100;

        printf("\nNome: ");
        setbuf(stdin,NULL);
        scanf("%s",new->nome);

        printf("\nAltura: ");
        setbuf(stdin,NULL);
        scanf("%f",&new->altura);

        printf("\nIdade: ");
        setbuf(stdin,NULL);
        scanf("%d",&new->idade);

        if(lista == NULL)
        {
            new->prox = new;
            
        }
        else
        {
            aux = lista;
            while (aux->prox != lista)
            {
                aux->prox = aux;
            }
            aux->prox = new;
            new->prox = lista;
            
        }
        return lista;

*/
//####################################################################
/* Lista encadeada dupla

struct pessoa 
{
    char nome[30];
    float altura;
    int idade,id;
    struct pessoa* prox, ant;
};

    Pessoa* Criar()
    {
        return NULL;
    };

    Pessoa Inserir(Pessoa * l)
    {

    srand(time(NULL));
    Pessoa *new = (Pessoa*) malloc(sizeof(Pessoa));
    Pessoa* aux;

    if(new)
    {


        new->id = rand() % 1000 + 100;

        printf("\nNome: ");
        setbuf(stdin,NULL);
        scanf("%s",new->nome);

        printf("\nAltura: ");
        setbuf(stdin,NULL);
        scanf("%f",&new->altura);

        printf("\nIdade: ");
        setbuf(stdin,NULL);
        scanf("%d",&new->idade);

        if(l== NULL)
        {
            new->ant = NULL;;
            new->prox = NULL;
        }
        else
        {
            l->ant = new;
            new -> prox = l;
        }      
    
    return new;
    }

*/