#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresa.h"
#include "funcionario.h"

//Definição da estrutura Empresa
struct empresa
{
    char cnpj[21]; //Documento da empresa
    char nome[21]; //Nome da empresa
    char localizacao[21]; //Localização da empresa
    int quantFuncionarios; //Quantidade de funcionários da empresa
    Funcionario *funcionarios; //Ponteiro para uma lista de funcionários
    int receita; //Receita da empresa
    char *cargos[5]; //Cargos da empresa
    float valor; //Valor da empresa
};

//Função para criar a empresa
Empresa *criaEmpresa(void)
{
    Empresa *empresa = (Empresa *) malloc(sizeof(Empresa));
    if (empresa == NULL)
    {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    //Inicialização dos campos com valores padrão
    strcpy(empresa->cnpj, "12.345.678/0001-90");
    strcpy(empresa->nome, "TechSolutions Inc");
    strcpy(empresa->localizacao, "Pau dos Ferros");
    empresa->quantFuncionarios = 0;
    empresa->funcionarios = criaFuncionario();
    empresa->receita = 1500000;

    //Alocação de memória e inicializa os cargos
    for (int i = 0; i < 5; i++)
    {
        empresa->cargos[i] = (char *)malloc(21 * sizeof(char));
        if (empresa->cargos[i] == NULL)
        {
            printf("Erro ao alocar memória\n");
            exit(1);
        }
    }
    strcpy(empresa->cargos[0], "Gerente");
    strcpy(empresa->cargos[1], "Analista");
    strcpy(empresa->cargos[2], "Assistente");
    strcpy(empresa->cargos[3], "Desenvolvedor");
    strcpy(empresa->cargos[4], "Estagiário");

    empresa->valor = 500000.0;

    return empresa;
}

//Função para imprimir informações sobre a Empresa
void imprimeEmpresa(Empresa *empresa)
{   
    printf("Empresa: %s\n", empresa->nome);
    printf("CNPJ: %s\n", empresa->cnpj);
    printf("Localização: %s\n", empresa->localizacao);
    printf("Quantidade de Funcionários: %d\n", empresa->quantFuncionarios);
    printf("Receita: R$ %d\n", empresa->receita);
    printf("Cargos:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("- %s\n", empresa->cargos[i]);
    }
    printf("Valor: R$ %.2f\n", empresa->valor);
}

//Função para liberar a memória alocada para a Empresa
void liberaEmpresa(Empresa *empresa)
{
    int i;
    for(i = 0; i < 5; i++){
        free(empresa->cargos[i]);
    }
    free(empresa);
}
