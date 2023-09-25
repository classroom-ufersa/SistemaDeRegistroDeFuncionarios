#include <stdio.h>
#include <stdlib.h>

struct empresa
{
    char cnpj[21];
    char nome[21];
    char localização[21];
    int quantFuncionarios;
    struct *funcionarios;
    float receita;
    char *cargos[5];
    float valor;
}
