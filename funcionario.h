typedef struct funcionario Funcionario;

Funcionario *criaFuncionario(void);

int trataNome(char nome[21]);

void LimpaBuffer(void);

Funcionario *insereFuncionario(Funcionario *lista, char *nome, char *documento, char *cargo, char *setor, int salario, char *data, char *jornada);

int quantificaFuncionarios(FILE *arquivo);

Funcionario *listaLerArquivo(FILE *arquivo, int nfuncionarios);

Funcionario *concatenaListas(Funcionario *lista1, Funcionario *lista2);

int compararNomes(const void *a, const void *b);

void liberaFuncionario(Funcionario *l);

void imprimeLista(Funcionario *l);