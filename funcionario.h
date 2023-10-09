typedef struct funcionario Funcionario;

Funcionario criaFuncionario(void);

void retiraQuebraLinha(charstring);

int trataString(char string[21]);

void LimpaBuffer(void);

Funcionario insereFuncionario1(Funcionariolista);

Funcionario insereFuncionario2(Funcionariolista, char nome, chardocumento, char cargo, charsetor, int salario, char data, charjornada);

int quantificaFuncionarios(FILE arquivo);

FuncionariolistaLerArquivo(FILE arquivo, int nfuncionarios);

FuncionarioconcatenaListas(Funcionario lista1, Funcionariolista2);

Funcionario ordenaLista(Funcionariolista);

void listaEscreveArquivo(Funcionario lista, FILEarquivo);

void liberaFuncionario(Funcionario l);

void imprimeLista(Funcionariol);

Funcionario listaRetira(Funcionariol, char string);

void imprimeFuncionario(Funcionariolista, char string);

void buscaFuncionario(Funcionariolista, char string);

FuncionarioeditarCadastro(Funcionario lista, charstring);

Funcionario *listaRetira(Funcionario *l, char *string);

void imprimeFuncionario(Funcionario *lista, char *string);

void buscaFuncionario(Funcionario *lista, char *string);

Funcionario *editarCadastro(Funcionario *lista, char *string);
