#include <stdio.h>
#include <stdlib.h>
#include "empresa.c"
#include "funcionario.c"

int main()
{
    int opcao1, opcao2, resultado;
    char nome[21], documento[21], setor[21], dataContratacao[21], jornadaTrabalho[21];
    float salario;
    Empresa *empresa = criaEmpresa();
    do
    {
        printf("MENU\n");
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
                    
                    //insereFuncionario(empresa->funcionarios, nome, documento, setor, salario, dataContratacao, jornadaTrabalho);
                    empresa->quantFuncionarios++;
                    break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;

            case 6:
            break;

            case 7:
            break;

            default:
        }
    }while(opcao1 != 8);
    imprimeEmpresa(empresa);
    liberaEmpresa(empresa);
    return 0;
}
