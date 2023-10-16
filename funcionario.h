typedef struct funcionario Funcionario;

//Função para criar uma lista de funcionários
Funcionario *criaFuncionario(void);

//Função para criar o arquivo caso não exista
void criarArquivo(char *nomeArquivo);

//Função para limpar o buffer
void LimpaBuffer(void);

//Função para corrigir as strings inseridas pelo usuário
int trataString(char string[21]);

//Função para contar a quantidade de funcionários
int quantificaFuncionarios(FILE *arquivo);

//Função para inserir um novo funcionários em uma lista encadeda simples
Funcionario *insereFuncionario(Funcionario *lista);

//Função para receber os dados de um arquivo e criar um novo funcionário
Funcionario *insereFuncionarioArquivo(Funcionario *lista, char *nome, char *documento, char *cargo, char *setor, int salario, char *data, char *jornada);

//Função para ler os dados do arquivo
Funcionario *listaLerArquivo(FILE *arquivo, int nfuncionarios);

//Função para escrever a lista no arquivo
void listaEscreveArquivo(Funcionario *lista, FILE *arquivo);

//função para concatenar as listas
Funcionario *concatenaListas(Funcionario *lista1, Funcionario *lista2);

//função para ordenar a lista em ordem alfabética
Funcionario *ordenaLista(Funcionario *lista);

//Função para retirar um funcionário da lista
Funcionario *listaRetira(Funcionario *l, char *string);

//Função para imprimir os dados de um funcionário
void imprimeFuncionario(Funcionario *lista, char *string);

//Função para buscar por um funcionário na lista
void buscaFuncionario(Funcionario *lista, char *string);

//Função para editar o cadastro de um funcionário
Funcionario *editarCadastro(Funcionario *lista, char *string);

//Função para quantificar os funcionários por cargos
int quantificaCargo(Funcionario *lista, char *string);

//Função para imprimir a lista
void imprimeLista(Funcionario *l);

//Função para liberar da memória a lista
void liberaFuncionario(Funcionario *l);