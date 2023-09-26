#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresa.h"
#include "funcionario.h"

struct empresa
{
    char cnpj[21];
    char nome[21];
    char localizacao[21];
    int quantFuncionarios;
    struct Funcionario *funcionarios;
    float receita;
    char *cargos[5];
    float valor;
};

Empresa *CriaEmpresa(void)
{
    Empresa *empresa = (Empresa *) malloc(sizeof(Empresa));
    if(empresa == NULL){
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    strcpy(empresa->cnpj, "12.345.678/0001-90");
    strcpy(empresa->nome, "Empresa");
    strcpy(empresa->localizacao, "Pau dos Ferros");
    empresa->quantFuncionarios = 5;
    empresa->funcionarios = NULL;
    empresa->receita = 1500000.0;
    empresa->cargos[0] = "Gerente";
    empresa->cargos[1] = "Analista";
    empresa->cargos[2] = "Assistente";
    empresa->cargos[3] = "Desenvolvedor";
    empresa->cargos[4] = "Estagiário";
    empresa->valor = 500000.0;
    
    return empresa;
}

void ImprimeEmpresa(Empresa *empresa)
{
    printf("CNPJ: %s\n", empresa->cnpj);
    printf("Nome: %s\n", empresa->nome);
    printf("Localização: %s\n", empresa->localizacao);
    printf("Quantidade de Funcionários: %d\n", empresa->quantFuncionarios);
    printf("Receita: R$ %.2f\n", empresa->receita);
    printf("Cargos:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("- %s\n", empresa->cargos[i]);
    }
    printf("Valor: R$ %.2f\n", empresa->valor);
}