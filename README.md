# Sistema De Registro DeFuncionarios

# Problemática

A problemática deste projeto gira em torno da necessidade de desenvolver um Sistema de Registro de Funcionários em linguagem C para atender às demandas de uma empresa. O principal objetivo é criar uma ferramenta eficaz que permita o gerenciamento eficiente das informações de funcionários

# Como Exercutar
- Windows: gcc main.c -o prog.exe & prog.exe
- Linux: gcc main.c -o prog && ./prog

# Conhecimentos Utilizados
- Ponteiro
- Alocação Dinâmica
- Struct
- Manipulação de Arquivos
- Tipos Abstratos de Dados
- Algoritmo de Ordenação
- Lista Encadeada Simples

# Estrutura do Sistema:
O sistema é composto por duas "TAD's" (Tipos Abstratos de Dados) representados pelos arquivos empresa.c e funcionario.c Esses elementos permitem o cadastro, edição, busca e listagem eficientes das informações dos funcionários em uma empresa.

###  1. O sistema oferece o seguinte menu de interações
```
printf("\n========== MENU ==========\n");
printf("1. Cadastrar Funcionário\n");
printf("2. Excluir Funcionário\n");
printf("3. Listar Funcionário\n");
printf("4. Buscar Funcionário\n");
printf("5. Editar Cadastro de Funcionário\n");
printf("6. Consultar Receita\n");
printf("7. Consultar Quantitativo de Funcionário Por Cargos\n");
printf("8. Sair\n");
```

###  2. TAD empresa
Essa TAD oferece as seguintes funções:
```
//Função para criar a empresa
Empresa *criaEmpresa(void);

//Função para imprimir informações sobre a Empresa
void imprimeEmpresa(Empresa *empresa);

//Função para liberar a memória alocada para a Empresa
void liberaEmpresa(Empresa *empresa);
```
###  3. TAD funcionario
Essa TAD ofecere as seguintes funções:
```
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
Funcionario *insereFuncionarioArquivo(Funcionario *lista, char *nome, char *documento, char *cargo, char *setor, float salario, char *data, char *jornada);

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
```