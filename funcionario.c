#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionario.h"

struct funcionario
{
    char nome[21];
    char documento[21]; 
    char cargo[21];
    char setor[21];
    float salario;
    char dataContratacao[21];
    char jornadaTrabalho[21];
    struct funcionario *proximo;
};

int trataNome(char nome[21])
{
    int i, tamanhoNome = strlen(nome);
  
    //Verifica se o nome é muito pequeno
    if(tamanhoNome <= 2){
        printf("Nome Muito Pequeno\n");
        return 1;
    }
    
    //Verifica se o nome contém caracteres especiais
    for(i = 0; nome[i] != '\0'; i++){
        if(!isalnum(nome[i]) && nome[i] != ' ' && nome[i] != '/'){
            printf("Nome Inválidao\n");
            return 1;
        }
    }
    
    //Converte o nome para maiúsculo
    for(i = 0; nome[i] != '\0'; i++){
        nome[i] = toupper(nome[i]);
    }
    
    return 0;
}

void LimpaBuffer(void)
{
    int valorLido; 
    do
    {
        valorLido = getchar(); 
    } while ((valorLido != '\n') && (valorLido != EOF)); 
}

Funcionario *insereFuncionario(FILE * arquivo, Funcionario *lista, char *nome, char *documento, char *cargo, char *setor, float salario, char *data, char *jornada)
{
    Funcionario *novo = (Funcionario *) malloc(sizeof(Funcionario));
    if(novo == NULL){
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    /*arquivo = fopen("funcionarios.txt", "a"); 
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }*/

    strcpy(novo->nome, nome);
    strcpy(novo->documento, documento);
    strcpy(novo->cargo, cargo);
    strcpy(novo->setor, setor);
    novo->salario = salario;
    strcpy(novo->dataContratacao, data);
    strcpy(novo->jornadaTrabalho, jornada);

    novo->proximo = lista;

    /*fprintf(arquivo, "%s\n%s\n%s\n%s\n%.2f\n%s\n%s\n", novo->nome, novo->documento, novo->cargo, novo->setor, novo->salario, novo->dataContratacao, novo->jornadaTrabalho);
    fclose(arquivo);
    LimpaBuffer();*/

    return novo;
}

//função para copiar os dados do arquivo

//função para concatenar as listas

//função para ordenar os elementos da lista

void imprime(Funcionario *l)
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


