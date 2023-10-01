typedef struct funcionario Funcionario;

int trataNome(char nome[21]);

void LimpaBuffer(void);

Funcionario *insereFuncionario(Funcionario *lista, char *nome, char *documento, char *cargo, char *setor, float salario, char *data, char *jornada);


Funcionario *listaLerArquivo(FILE *arquivo);

Funcionario *concatenaListas(Funcionario *lista1, Funcionario *lista2);

int compararNomes(const void *a, const void *b);


void liberaFuncionario(Funcionario *l);

void imprime(Funcionario *l);