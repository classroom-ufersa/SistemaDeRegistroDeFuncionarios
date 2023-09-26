#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"
#include "funcionario.h"

int main()
{
    Empresa *minhaEmpresa = criaEmpresa();
    
    printf("Dados da Empresa:\n");
    imprimeEmpresa(minhaEmpresa);
    free(minhaEmpresa);
    
    return 0;
}