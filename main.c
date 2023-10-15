#include <stdio.h>
#include <stdlib.h>
#include "empresa.c"
#include "funcionario.c"

int main()
{
    int opcao1 = 0, opcao2 = 0, totalFuncionarios = 0, nfuncionarios = 0, resultado = 0, quantidadeCargos = 0;
    char dado[51];
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

                if(nfuncionarios == 0){
                    do
                    {
                        //Insere um novo funcionário na lista
                        empresa->funcionarios = insereFuncionario1(empresa->funcionarios);
                        printf("Deseja Continuar Cadastrando?\n");
                        printf("1 - Sim\n");
                        printf("2 - Não\n");
                        scanf(" %d", &opcao2);
                    }while(opcao2 != 2);

                    empresa->funcionarios = ordenaLista(empresa->funcionarios);
                    
                    listaEscreveArquivo(empresa->funcionarios, arquivo);

                    liberaFuncionario(empresa->funcionarios);
                }

                else{
                    do
                    {
                        //Insere um novo funcionário na lista
                        empresa->funcionarios = insereFuncionario1(empresa->funcionarios);
                        
                        printf("Deseja Continuar Cadastrando?\n");
                        printf("1 - Sim\n");
                        printf("2 - Não\n");
                        scanf(" %d", &opcao2);
                    }while(opcao2 != 2);

                    //Copia os dados dos funcionários do arquivo, e cria uma lista com esses dados
                    nfuncionarios = quantificaFuncionarios(arquivo);
                    listaArquivo = listaLerArquivo(arquivo, nfuncionarios);

                    //Concatena as listas
                    listaConcatenada = concatenaListas(empresa->funcionarios, listaArquivo);

                    //Ordena lista
                    listaOrdenada = ordenaLista(listaConcatenada);

                    //Escrever lista ordenada no arquivo
                    listaEscreveArquivo(listaOrdenada, arquivo);

                    liberaFuncionario(listaOrdenada);
                }


                break;

            case 2:
                do
                {   
                    printf("Informe o nome/documento do funcionário: ");
                    scanf(" %[^\n]", dado);
                    resultado = trataString(dado);
                }while(resultado != 0);

                nfuncionarios = quantificaFuncionarios(arquivo);
                listaArquivo = listaLerArquivo(arquivo, nfuncionarios);

                listaArquivo = listaRetira(listaArquivo, dado);
                listaEscreveArquivo(listaArquivo, arquivo);
                break;

            case 3:
                nfuncionarios = quantificaFuncionarios(arquivo);
                listaArquivo = listaLerArquivo(arquivo, nfuncionarios);
                
                listaArquivo = ordenaLista(listaArquivo);
                imprimeLista(listaArquivo);

                liberaFuncionario(listaArquivo);
                break;

            case 4:
                do
                {   
                    printf("Informe o nome/documento do funcionário: ");
                    scanf(" %[^\n]", dado);
                    resultado = trataString(dado);
                }while(resultado != 0);

                nfuncionarios = quantificaFuncionarios(arquivo);
                listaArquivo = listaLerArquivo(arquivo, nfuncionarios);

                buscaFuncionario(listaArquivo, dado);

                break;

            case 5:
                do
                {   
                    printf("Informe o nome/documento do funcionário: ");
                    scanf(" %[^\n]", dado);
                    resultado = trataString(dado);
                }while(resultado != 0);

                nfuncionarios = quantificaFuncionarios(arquivo);
                listaArquivo = listaLerArquivo(arquivo, nfuncionarios);

                editarCadastro(listaArquivo, dado);

                listaEscreveArquivo(listaArquivo, arquivo);

                break;

            case 6:
                printf("Receita: %d\n", empresa->receita);

                break;

            case 7:
                nfuncionarios = quantificaFuncionarios(arquivo);
                listaArquivo = listaLerArquivo(arquivo, nfuncionarios);
                
                printf("Quantitativo de Funcionário Por Cargos:\n");
                quantidadeCargos = quantificaCargo(listaArquivo, "GERENTE");
                printf("Gerentes: %d\n", quantidadeCargos);
                quantidadeCargos = 0;

                quantidadeCargos = quantificaCargo(listaArquivo, "ANALISTA");
                printf("Analistas: %d\n", quantidadeCargos);
                quantidadeCargos = 0;

                quantidadeCargos = quantificaCargo(listaArquivo, "ASSISTENTE");
                printf("Assistentes: %d\n", quantidadeCargos);
                quantidadeCargos = 0;

                quantidadeCargos = quantificaCargo(listaArquivo, "DESENVOLVEDOR");
                printf("Desenvolvedores: %d\n", quantidadeCargos);
                quantidadeCargos = 0;

                quantidadeCargos = quantificaCargo(listaArquivo, "ESTAGIARIO");
                printf("Estagiários: %d\n", quantidadeCargos);

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
