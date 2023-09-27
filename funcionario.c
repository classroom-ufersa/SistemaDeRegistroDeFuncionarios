#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionario.h"

struct funcionario
{
    char nome[21];
    char cpf[21]; //usar union?
    char cargo[21];
    char setor[21];
    float salario;
    char dataContratacao[21];
    char jornadaTrabalho[21];
    struct funcionario *proximo;
    struct funcionario *anterior;
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

Funcionario *insereFuncionario(Funcionario *ponteiroLista, char *nome, char *documento, char *setor, float salario, char *data, char *jornada) 
{
    Funcionario *novoFuncionario = (Funcionario *)malloc(sizeof(Funcionario));
    if (novoFuncionario == NULL) {
        printf("Erro ao alocar memória para o novo funcionário.\n");
        return ponteiroLista; // Retorna a lista original
    }

    strcpy(novoFuncionario->nome, nome);
    strcpy(novoFuncionario->cpf, documento);
    strcpy(novoFuncionario->setor, setor);
    novoFuncionario->salario = salario;
    strcpy(novoFuncionario->dataContratacao, data);
    strcpy(novoFuncionario->jornadaTrabalho, jornada);

    novoFuncionario->proximo = ponteiroLista; // Insere no início da lista
    novoFuncionario->anterior = NULL; // Não há elemento anterior ao primeiro
    
    if (ponteiroLista != NULL) {
        ponteiroLista->anterior = novoFuncionario; // Atualiza o anterior do próximo nó, se não for nulo
    }
    
    return novoFuncionario; // Retorna o novo início da lista
}


/*
Funcionario *retiraLista(ListaFuncionarios *ponteiroLista, char *nome) 
{
    Funcionario *atual = ponteiroLista;

    while (atual != NULL) {
        if (strcmp(atual->funcionario.nome, nome) == 0) {
            if (atual->anterior != NULL) {
                atual->anterior->proximo = atual->proximo; 
            }
            if (atual->proximo != NULL) {
                atual->proximo->anterior = atual->anterior; 
            }

            if (atual == ponteiroLista) {
                ponteiroLista = atual->proximo; 
            }

            free(atual); 
            return ponteiroLista; 
        }

        atual = atual->proximo;
    }

    printf("Funcionário com nome '%s' não encontrado na lista.\n", nome);
    return ponteiroLista; 
}
*/
/*
Funcionario*BuscaFuncionario(Funcionario*ponteiroLista,char*nome){
    Funcionario*atual=ponteiroLista;
    while(atual!=NULL){
        if (strcmp(atual->nome, nome) == 0 ){
            return atual;
        }
        atual= atual->proximo;
    }
    return NULL;
}

*/

/*
void imprimeFuncionarios(Funcionario *ponteiroLista) {
    Funcionario *atual = ponteiroLista;

    printf("Lista de Funcionários:\n");
    
    while (atual != NULL) {
        printf("Nome: %s\n", atual->nome);
        printf("CPF: %s\n", atual->cpf);
        printf("Cargo: %s\n", atual->cargo);
        printf("Setor: %s\n", atual->setor);
        printf("Salário: %.2f\n", atual->salario);
        printf("Data de Contratação: %s\n", atual->dataContratacao);
        printf("Jornada de Trabalho: %s\n", atual->jornadaTrabalho);
         
        
        atual = atual->proximo; 
    }
}
*/

/*
int contaFuncionarios(Funcionario *ponteiroLista) {
    int contador = 0;
    Funcionario *atual = ponteiroLista;

    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }

    return contador;
}

int quantidadedeFuncionarios = contaFuncionarios(ponteiroParaLista); 
printf("Total de funcionários na lista: %d\n", quantidadedeFuncionarios);

*/
