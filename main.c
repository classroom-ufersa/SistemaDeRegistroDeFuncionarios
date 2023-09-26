#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"
#include "funcionario.h"

int main()
{
    Empresa *minhaEmpresa = CriaEmpresa();
    
    // Imprime os dados da empresa
    printf("Dados da Empresa:\n");
    ImprimeEmpresa(minhaEmpresa);
    
    // Libera a memória alocada
    free(minhaEmpresa);
    
    return 0;
}