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
    int jornadaTrabalho;
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
        if(!isalnum(nome[i]) && nome[i] != ' '){
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

//Funcionario *criaLista(void)

//void insereLista(Funcionario *ponteiroLista, char *nome)

//Funcionario *retiraLista(Funcionario *ponteiroLista, char *nome)
