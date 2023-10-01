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

    novo->proximo = lista;

    return novo;
}

int quantificaFuncionarios(FILE *arquivo)
{
    int nlinhas = 0, c;

    //Abre o arquivo para ler
    arquivo = fopen("funcionarios.txt", "rt"); 
    if(arquivo == NULL){
        printf("Erro ao abrir!\n");
        exit(1);
    }

    //Conta a quantidade de linhas do arquivo
    while((c = fgetc(arquivo)) != EOF){
        if(c == '\n'){
            nlinhas++;
        }
    }

    //Retorna a quantidade de funcionários
    return nlinhas/7;
}

//função para copiar os dados do arquivo
Funcionario *copiaDadosArquivo(FILE *arquivo, int quantFuncionarios)
{
    Funcionario *l = NULL;
    int i;

    arquivo = fopen("funcionarios.txt", "r"); 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for (i = 0; i < quantFuncionarios; i++) {
        Funcionario *funcionario = (Funcionario *) malloc(sizeof(Funcionario));
        if (funcionario == NULL) {
            printf("Erro ao alocar memória\n");
            exit(1);
        }

        fgets(funcionario->nome, 21, arquivo);
        funcionario->nome[strcspn(funcionario->nome, "\n")] = '\0';

        fgets(funcionario->documento, 21, arquivo);
        funcionario->documento[strcspn(funcionario->documento, "\n")] = '\0';

        fgets(funcionario->cargo, 21, arquivo);
        funcionario->cargo[strcspn(funcionario->cargo, "\n")] = '\0';

        fgets(funcionario->setor, 21, arquivo);
        funcionario->setor[strcspn(funcionario->setor, "\n")] = '\0';

        fscanf(arquivo, "%f", &funcionario->salario); 

        fgets(funcionario->dataContratacao, 21, arquivo);
        funcionario->dataContratacao[strcspn(funcionario->dataContratacao, "\n")] = '\0';

        fgets(funcionario->jornadaTrabalho, 21, arquivo);
        funcionario->jornadaTrabalho[strcspn(funcionario->jornadaTrabalho, "\n")] = '\0';

        funcionario->proximo = l;
        l = funcionario;
    }

    LimpaBuffer();

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

    arquivo = fopen("funcionarios.txt", "r"); 
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

