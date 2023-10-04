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
    int salario; //Salário do funcionário
    char dataContratacao[51]; //Data de contratação do funcionário
    char jornadaTrabalho[51]; //Jornada de tarabalho do funcionário
    struct funcionario *proximo; //Ponteiro para uma struct funcionário
};

Funcionario *criaFuncionario(void)
{
    return NULL;
}

//Função para corrigir as strings inseridos pelo usuário
int trataNome(char nome[21])
{
    int i, tamanhoNome = strlen(nome);
  
    //Verifica se o nome é muito pequeno
    if(tamanhoNome <= 2){
        printf("Entrada Pequena\n");
        return 1;
    }
    
    //Verifica se o nome contém caracteres especiais
    for(i = 0; nome[i] != '\0'; i++){
        if(!isalnum(nome[i]) && nome[i] != ' ' && nome[i] != '/' && nome[i] != '.'){
            printf("Entrada Inválida\n");
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

Funcionario *insereFuncionario(Funcionario *lista, char *nome, char *documento, char *cargo, char *setor, int salario, char *data, char *jornada)
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
    int nlinhas = 1, c;

    //Abre o arquivo para ler
    arquivo = fopen("funcionarios.txt", "r"); 
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

Funcionario *listaLerArquivo(FILE *arquivo, int nfuncionarios)
{
    Funcionario *lista = criaFuncionario();
    int i;
    char nome[51]; 
    char documento[51]; 
    char cargo[51]; 
    char setor[51]; 
    char salarioStr[51]; 
    char dataContratacao[51]; 
    char jornadaTrabalho[51]; 
    arquivo = fopen("funcionarios.txt", "r");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    for(i = 0; i < nfuncionarios; i++){
        fgets(nome, 51, arquivo);
        fgets(documento, 51, arquivo);
        fgets(cargo, 51, arquivo);
        fgets(setor, 51, arquivo);
        fgets(salarioStr, 51, arquivo); 
        fgets(dataContratacao, 51, arquivo);
        fgets(jornadaTrabalho, 51, arquivo);

        nome[strcspn(nome, "\n")] = '\0';
        documento[strcspn(documento, "\n")] = '\0';
        cargo[strcspn(cargo, "\n")] = '\0';
        setor[strcspn(setor, "\n")] = '\0';
        int salario = atoi(salarioStr); 
        dataContratacao[strcspn(dataContratacao, "\n")] = '\0';
        jornadaTrabalho[strcspn(jornadaTrabalho, "\n")] = '\0';

        lista = insereFuncionario(lista, nome, documento, cargo, setor, salario, dataContratacao, jornadaTrabalho);

        LimpaBuffer();
    }   
    
    fclose(arquivo);
    return lista;
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
Funcionario *ordenaLista(Funcionario *lista)
{
    Funcionario *i = NULL;
    Funcionario *j = NULL;

    if (lista == NULL) {
        printf("Lista Vazia\n");
        return lista;
    } else {
        for (i = lista; i->proximo != NULL; i = i->proximo) {
            Funcionario *maior = i;
            for (j = i->proximo; j != NULL; j = j->proximo) {
                if (strcmp(j->nome, maior->nome) > 0) {
                    maior = j;
                }
            }
            char aux[51];
            strcpy(aux, i->nome);
            strcpy(i->nome, maior->nome);
            strcpy(maior->nome, aux);
        }
    }

    return lista;
}

//Função para escrever a lista no arquivo
void listaEscreveArquivo(Funcionario *lista, FILE *arquivo)
{
    Funcionario *atual = lista;

    arquivo = fopen("funcionarios.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    while (atual != NULL) {
        fprintf(arquivo, "%s\n%s\n%s\n%s\n%d\n%s\n%s\n", atual->nome, atual->documento, atual->cargo, atual->setor, atual->salario, atual->dataContratacao, atual->jornadaTrabalho);
        atual = atual->proximo;
        LimpaBuffer();
    }

    fclose(arquivo);
}

void imprimeLista(Funcionario *l)// Função para imprimir a lista de funcionários
{
	Funcionario* p;

	for(p=l; p!=NULL; p=p->proximo){
		printf("Nome: %s\nDocumento: %s\nCargo: %s\nSetor: %s\nSalário: %d\nData de Contratação: %s\nJornada de Trabalho: %s\n", p->nome, p->documento, p->cargo, p->setor, p->salario, p->dataContratacao, p->jornadaTrabalho);
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
/*
Funcionario *ordenaLista(Funcionario *lista)
{
    Funcionario *i = NULL;
    Funcionario *j = NULL;

    if (lista == NULL) {
        printf("Lista Vazia\n");
        return lista;
    } else {
        for (i = lista; i->proximo != NULL; i = i->proximo) {
            Funcionario *menor = i;
            for (j = i->proximo; j != NULL; j = j->proximo) {
                if (strcmp(j->nome, menor->nome) < 0) {
                    menor = j;
                }
            }
            if (i != menor) {
                Funcionario temp;
                memcpy(&temp, i, sizeof(Funcionario));
                memcpy(i, menor, sizeof(Funcionario));
                memcpy(menor, &temp, sizeof(Funcionario));
            }
        }
    }

    return lista;
}
*/
/*
Funcionario *excluiFuncionarioPorNome(Funcionario *lista, char *nome)
{
    Funcionario *atual = lista;
    Funcionario *anterior = NULL;
    
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            if (anterior != NULL) {
                anterior->proximo = atual->proximo;
            } else {
                lista = atual->proximo;
            }
            free(atual);
            return lista; // Retorna a lista atualizada após a exclusão
        }
        anterior = atual;
        atual = atual->proximo;
    }
    
    return lista; // Retorna a lista original se o funcionário não for encontrado
}
*/
/*
#include <stdbool.h>

Funcionario *buscaFuncionarioPorNomeOuDocumento(Funcionario *lista, char *nomeOuDocumento)
{
    Funcionario *atual = lista;
    Funcionario *resultados = NULL; // Lista para armazenar os resultados
    bool encontrou = false; // Flag para indicar se foi encontrado pelo menos um funcionário

    while (atual != NULL) {
        if (strcmp(atual->nome, nomeOuDocumento) == 0 || strcmp(atual->documento, nomeOuDocumento) == 0) {
            // Se o nome ou documento corresponderem, adiciona o funcionário aos resultados
            resultados = insereFuncionario(resultados, atual->nome, atual->documento, atual->cargo, atual->setor, atual->salario, atual->dataContratacao, atual->jornadaTrabalho);
            encontrou = true; // Indica que pelo menos um funcionário foi encontrado
        }
        atual = atual->proximo;
    }

    if (!encontrou) {
        printf("Nenhum funcionário encontrado com o nome ou documento especificado.\n");
    }

    return resultados;
*/ //(PEGUEI ESSA FUNÇÂO DA NET)
