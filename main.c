#include <stdio.h>
#include <stdlib.h>
#include "empresa.c"
#include "funcionario.c"

int main()
{
    int opcao1 = 0, opcao2 = 0, resultado = 0, totalFuncionarios = 0, nfuncionarios = 0;
    char nome[21], documento[21], cargo[21], setor[21], dataContratacao[21], jornadaTrabalho[21];
    float salario = 0;
    Empresa *empresa = criaEmpresa();
    Funcionario *listaArquivo = criaFuncionario();
    Funcionario *listaConcatenada = criaFuncionario();
    Funcionario *listaOrdenada = criaFuncionario();
    FILE *arquivo = NULL;

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Cadastrar Funcionário\n");
        printf("2. Excluir Funcionário\n");
        printf("3. Listar Funcionário\n");
        printf("4. Buscar Funcionário\n");
        printf("5. Editar Cadastro de Funcionário\n");
        printf("6. Consultar Receita\n");
        printf("7. Consultar Quantitativo de Funcionário Por Cargos\n");
        printf("8. Sair\n");
        printf("Digite uma Opção: \n");
        scanf(" %d", &opcao1);
        switch(opcao1)
        {
            case 1:
                    do
                    {   
                        printf("Informe seu nome: ");
                        scanf(" %[^\n]", nome);
                        resultado = trataNome(nome);
                    }while(resultado != 0);

                    do
                    {   
                        printf("Informe seu documento: ");
                        scanf(" %[^\n]", documento);
                        resultado = trataNome(documento);
                    }while(resultado != 0);

                    do
                    {   
                        printf("Informe seu cargo: ");
                        scanf(" %[^\n]", cargo);
                        resultado = trataNome(cargo);
                    }while(resultado != 0);
                    
                    do
                    {   
                        printf("Informe seu setor: ");
                        scanf(" %[^\n]", setor);
                        resultado = trataNome(setor);
                    }while(resultado != 0);
                    
                   
                    printf("Informe seu salário: ");
                    scanf(" %f", &salario);

                    do
                    {   
                        printf("Informe sua data de contratação: ");
                        scanf(" %[^\n]", dataContratacao);
                        resultado = trataNome(dataContratacao);
                    }while(resultado != 0);

                    do
                    {   
                        printf("Informe sua jornada de trabalho: ");
                        scanf(" %[^\n]", jornadaTrabalho);
                        resultado = trataNome(jornadaTrabalho);
                    }while(resultado != 0);
                    
                    //Insere um novo funcionário na lista
                    empresa->funcionarios = insereFuncionario(empresa->funcionarios, nome, documento, cargo, setor, salario, dataContratacao, jornadaTrabalho);
                    
                    //Copia os dados dos funcionários do arquivo, e cria uma lista com esses dados
                    nfuncionarios = quantificaFuncionarios(arquivo);
                    listaArquivo = listaLerArquivo(arquivo, nfuncionarios);
                    
                    //Concatena as listas
                    listaConcatenada = concatenaListas(empresa->funcionarios, listaArquivo);

                    //Ordena lista
                    listaOrdenada = ordenaLista(listaConcatenada);
                    imprimeLista(listaOrdenada);

                    //Escrever lista ordenada no arquivo
                    escreveArquivo(listaOrdenada, arquivo);

                    //Atualiza a quantidade de funcionários da empresa
                    empresa->quantFuncionarios++;
                    break;
            default:
        }
    }while(opcao1 != 8);
    liberaFuncionario(listaOrdenada);
    liberaEmpresa(empresa);
    return 0;
}