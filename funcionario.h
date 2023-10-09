typedef struct funcionario Funcionario;

Funcionario *criaFuncionario(void);

void retiraQuebraLinha(char *string);

int trataString(char string[21]);

void LimpaBuffer(void);

Funcionario *insereFuncionario1(Funcionario *lista);

Funcionario *insereFuncionario2(Funcionario *lista, char *nome, char *documento, char *cargo, char *setor, int salario, char *data, char *jornada);

int quantificaFuncionarios(FILE *arquivo);

FuncionariolistaLerArquivo(FILE *arquivo, int nfuncionarios);

FuncionarioconcatenaListas(Funcionario *lista1, Funcionario *lista2);

Funcionario *ordenaLista(Funcionario *lista);

void listaEscreveArquivo(Funcionario *lista, FILE *arquivo);

void liberaFuncionario(Funcionario *l);

void imprimeLista(Funcionario *l);

Funcionario *listaRetira(Funcionario *l, char *string);

void imprimeFuncionario(Funcionario *lista, char *string);

void buscaFuncionario(Funcionario *lista, char *string);

Funcionario *listaRetira(Funcionario *l, char *string);

void imprimeFuncionario(Funcionario *lista, char *string);

void buscaFuncionario(Funcionario *lista, char *string);

Funcionario *editarCadastro(Funcionario *lista, char *string);
