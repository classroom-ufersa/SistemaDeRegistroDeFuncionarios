typedef struct funcionario Funcionario;

Funcionario *criaFuncionario(void);



void LimpaBuffer(void);

int trataString(char string[21]);

int quantificaFuncionarios(FILE *arquivo);

Funcionario *insereFuncionario(Funcionario *lista);

Funcionario *insereFuncionarioArquivo(Funcionario *lista, char *nome, char *documento, char *cargo, char *setor, float salario, char *data, char *jornada);

Funcionario *listaLerArquivo(FILE *arquivo, int nfuncionarios);

void listaEscreveArquivo(Funcionario *lista, FILE *arquivo);

Funcionario *concatenaListas(Funcionario *lista1, Funcionario *lista2);

Funcionario *ordenaLista(Funcionario *lista);

Funcionario *listaRetira(Funcionario *l, char *string);

void imprimeFuncionario(Funcionario *lista, char *string);

void buscaFuncionario(Funcionario *lista, char *string);

Funcionario *editarCadastro(Funcionario *lista, char *string);

int quantificaCargo(Funcionario *lista, char *string);

void imprimeLista(Funcionario *l);

void liberaFuncionario(Funcionario *l);