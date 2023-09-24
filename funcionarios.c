#include <stdio.h>
#include <stdlib.h>
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
}funcionario;

//Funcionario *criaLista(void)

//char trataString(char *nome)

//void insereLista(Funcionario *ponteiroLista, char *nome)

//Funcionario *retiraLista(Funcionario *ponteiroLista, char *nome)



