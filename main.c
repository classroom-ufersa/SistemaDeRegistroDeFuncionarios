#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"
#include "funcionario.h"

int main()
{
    Empresa *minhaEmpresa = CriaEmpresa();
    
    printf("Dados da Empresa:\n");
    ImprimeEmpresa(minhaEmpresa);
    free(minhaEmpresa);
    
    return 0;
}