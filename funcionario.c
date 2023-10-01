#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionario.h"

//Definição da struct Funcionário
struct funcionario
{
    char nome[51]; //Nome do funcionário
    char documento[51]; //Documento do funcionário
    char cargo[51]; //Cargo do funcionário
    char setor[51]; //Setor de trabalho do funcionário
    float salario; //Salário do funcionário
    char dataContratacao[51]; //Data de contratação do funcionário
    char jornadaTrabalho[51]; //Jornada de tarabalho do funcionário
    struct funcionario *proximo; //Ponteiro para uma struct funcionário
};

//Função para corrigir as strings inseridos pelo usuário
int trataNome(char nome[21])
{
    int i, tamanhoNome = strlen(nome);
  
    //Verifica se o nome é muito pequeno
    if(tamanhoNome <= 2){
        printf("Entrada Muito Pequeno\n");
        return 1;
    }
    
    //Verifica se o nome contém caracteres especiais
    for(i = 0; nome[i] != '\0'; i++){
        if(!isalnum(nome[i]) && nome[i] != ' ' && nome[i] != '/'){
            printf("Entrada Inválido\n");
            return 1;
        }
    }
    
    //Converte o nome para maiúsculo
    for(i = 0; nome[i] != '\0'; i++){
        nome[i] = toupper(nome[i]);
    }
    
    return 0;
}

// Função para limpar o buffer
void LimpaBuffer(void)
{
    int valorLido; 
    do
    {
        valorLido = getchar(); 
    } while ((valorLido != '\n') && (valorLido != EOF)); 
}


Funcionario *insereFuncionario(Funcionario *lista, char *nome, char *documento, char *cargo, char *setor, float salario, char *data, char *jornada)
{
    Funcionario *novo = (Funcionario *) malloc(sizeof(Funcionario));
    if(novo == NULL){
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    strcpy(novo->nome, nome);
    strcpy(novo->documento, documento);
    strcpy(novo->cargo, cargo);
    strcpy(novo->setor, setor);
    novo->salario = salario;
    strcpy(novo->dataContratacao, data);
    strcpy(novo->jornadaTrabalho, jornada);

    novo->proximo = lista;// Define o próximo como o início da lista existente

    return novo;
}


Funcionario *listaLerArquivo(FILE *arquivo)
{
	char nome[51]; //Nome do funcionário
    char documento[51]; //Documento do funcionário
    char cargo[51]; //Cargo do funcionário
    char setor[51]; //Setor de trabalho do funcionário
    float salario; //Salário do funcionário
    char dataContratacao[51]; //Data de contratação do funcionário
    char jornadaTrabalho[51]; //Jornada de tarabalho do funcionário

	Funcionario *l = NULL;
	arquivo = fopen("funcionarios.txt", "r");
	if(arquivo == NULL){
		printf("Erro ao abrir o arquivo!\n");
		exit(1);
	}
	while(fscanf(arquivo, "%s%s%s%s%f%s%s", nome, documento, cargo, setor, &salario, dataContratacao, jornadaTrabalho) != EOF){
		l = insereFuncionario(l, nome, documento, cargo, setor, salario, dataContratacao, jornadaTrabalho);
	}
    
	fclose(arquivo);
	return l;
}



//função para concatenar as listas
Funcionario *concatenaListas(Funcionario *lista1, Funcionario *lista2)
{
    Funcionario *atual = lista1;
    Funcionario * anterior = NULL;

    while(atual != NULL){
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = lista2;

    return anterior;
}

//função para ordenar a lista em ordem alfabética
int compararNomes(const void *a, const void *b)
{
    Funcionario *funcionarioA = (Funcionario *)a; //Converte o ponteiro
    Funcionario *funcionarioB = (Funcionario *)b; //Converte o ponteiro
    return strcmp(funcionarioA->nome, funcionarioB->nome); //compara as strings 
}


//Função para escrever a lista no arquivo
void escreveArquivo(Funcionario *lista, FILE *arquivo)
{
    Funcionario *atual = lista;

    arquivo = fopen("funcionarios.txt", "w"); 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    while(atual != NULL){
        fprintf(arquivo, "%s\n%s\n%s\n%s\n%f\n%s\n%s\n", atual->nome, atual->documento, atual->cargo, atual->setor, atual->salario, atual->dataContratacao, atual->jornadaTrabalho);
        atual = atual->proximo;
    }

    LimpaBuffer();

    fclose(arquivo);
}

void imprime(Funcionario *l)// Função para imprimir a lista de funcionários
{
	Funcionario* p;

	for(p=l; p!=NULL; p=p->proximo){
		printf("Nome: %s\n", p->nome);
        printf("Documento: %s\n", p->documento);
        printf("Cargo: %s\n", p->cargo);
        printf("Setor: %s\n", p->setor);
        printf("Salário: %f\n", p->salario);
        printf("Data de Contratação: %s\n", p->dataContratacao);
        printf("Jornada de Trabalho: %s\n", p->jornadaTrabalho);
	}
}

void liberaFuncionario(Funcionario *l)
{
    Funcionario* p = l;
    Funcionario* t;
    while (p != NULL) {
        t = p->proximo;
        free(p);
        p = t;

    }
}

