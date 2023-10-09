#include <stdio.h>
#include <stdlib.h>
#include "empresa.c"
#include "funcionario.c"

int main()
{
    int opcao1 = 0, opcao2 = 0, totalFuncionarios = 0, nfuncionarios = 0;

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
                    //Quantifica a quantidade de funcionários no arquivo
                    nfuncionarios = quantificaFuncionarios(arquivo);

                    //Caso não tenha funcionários registrados no arquivo
                    if(nfuncionarios == 0){
                        //Repete o laço até 'opcao2' ser igual a 2
                        do
                        {
                            //Insere um novo funcionário na lista
                            empresa->funcionarios = insereFuncionario1(empresa->funcionarios);

                            printf("Deseja Continuar Cadastrando?\n");
                            printf("1 - Sim\n");
                            printf("2 - Não\n");
                            scanf(" %d", &opcao2);

                        }while(opcao2 != 2);

                        //Escreve a lista no arquivo
                        listaEscreveArquivo(empresa->funcionarios, arquivo);
                    }

                    //Caso contenha ao menos 1 funcionário registrado no arquivo
                    else{
                        //Repete o laço até 'opcao2' ser igual a 2
                        do
                        {
                            //Insere um novo funcionário na lista
                            empresa->funcionarios = insereFuncionario1(empresa->funcionarios);  

                            printf("Deseja Continuar Cadastrando?\n");
                            printf("1 - Sim\n");
                            printf("2 - Não\n");
                            scanf(" %d", &opcao2);

                        }while(opcao2 != 2);

                        //Insere um novo funcionário na lista
                        empresa->funcionarios = insereFuncionario1(empresa->funcionarios);
                        
                        //Copia os dados dos funcionários do arquivo, e cria uma lista com esses dados
                        nfuncionarios = quantificaFuncionarios(arquivo);
                        listaArquivo = listaLerArquivo(arquivo, nfuncionarios);
                        
                        //Concatena as listas
                        listaConcatenada = concatenaListas(empresa->funcionarios, listaArquivo);

                        //Ordena lista
                        listaOrdenada = ordenaLista(listaConcatenada);

                        //Escrever lista ordenada no arquivo
                        listaEscreveArquivo(listaOrdenada, arquivo);
                    }

                    //Atualiza a quantidade de funcionários da empresa
                    empresa->quantFuncionarios++;
            system("clear");
            break;

            case 2:

            system("clear");
            break;

            case 3:
            system("clear");
            break;

            case 4:
            system("clear");
            break;

            case 5:
            system("clear");
            break;

            case 6:
                printf("Receita: %d\n", empresa->receita);

                system("clear");
            break;

            case 7:
                //Copia os dados dos funcionários do arquivo, e cria uma lista com esses dados
                nfuncionarios = quantificaFuncionarios(arquivo);
                listaArquivo = listaLerArquivo(arquivo, nfuncionarios);
                system("clear");
            break;

            default:
            if(opcao1 != 8){
                printf("Opção Inválida\n");
            }

            break;
        }
    }while(opcao1 != 8);
    liberaFuncionario(listaOrdenada);
    liberaEmpresa(empresa);
    printf("Programa Encerrado\n");
    return 0;
}