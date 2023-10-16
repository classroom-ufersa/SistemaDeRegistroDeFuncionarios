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

    //Imprime as informações da empresa
    //imprimeEmpresa(empresa);

    //Laço de repetição para voltar ao menu de opções
    do
    {   
        //Imprime as opções do menu ao usuário
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

        //Laço de repetição para interação com o menu
        switch(opcao1)
        {
            case 1:


                //Quantifica a quantidade de funcionários no arquivo
                nfuncionarios = quantificaFuncionarios(arquivo);

                //Caso não tenha funcionários no arquivo
                if(nfuncionarios == 0){
                    do
                    {
                        //Insere um novo funcionário na lista
                        empresa->funcionarios = insereFuncionario(empresa->funcionarios);
                        printf("Deseja Continuar Cadastrando?\n");
                        printf("1 - Sim\n");
                        printf("2 - Não\n");
                        scanf(" %d", &opcao2);
                    }while(opcao2 != 2);

                    //Ordena a lista
                    empresa->funcionarios = ordenaLista(empresa->funcionarios);
                    
                    //Escreve a lista no arquivo
                    listaEscreveArquivo(empresa->funcionarios, arquivo);

                    //Libera a lista
                    liberaFuncionario(empresa->funcionarios);
                }

                //Caso tenha ao menos um funcionário no arquivo
                else{
                    do
                    {
                        //Insere um novo funcionário na lista
                        empresa->funcionarios = insereFuncionario(empresa->funcionarios);
                        
                        printf("Deseja Continuar Cadastrando?\n");
                        printf("1 - Sim\n");
                        printf("2 - Não\n");
                        scanf(" %d", &opcao2);
                    }while(opcao2 != 2);

                    //Quantifica a quantidade de funcionários no arquivo
                    nfuncionarios = quantificaFuncionarios(arquivo);

                    //Copia os dados dos funcionários do arquivo, e cria uma lista com esses dados
                    listaArquivo = listaLerArquivo(arquivo, nfuncionarios);

                    //Concatena as listas
                    listaConcatenada = concatenaListas(empresa->funcionarios, listaArquivo);

                    //Ordena lista
                    listaOrdenada = ordenaLista(listaConcatenada);

                    //Escrever lista ordenada no arquivo
                    listaEscreveArquivo(listaOrdenada, arquivo);
                    
                    //Libera a lista
                    liberaFuncionario(listaOrdenada);
                }

                opcao1 = 0;

                break;

            case 2:

                //Laço de repetição para receber o nome ou o documento do funcionário
                do
                {   
                    printf("Informe o nome/documento do funcionário: ");
                    scanf(" %[^\n]", dado);
                    resultado = trataString(dado);
                }while(resultado != 0);

                //Quantifica a quantidade de funcionários no arquivo
                nfuncionarios = quantificaFuncionarios(arquivo);

                //Copia os dados dos funcionários do arquivo, e cria uma lista com esses dados
                listaArquivo = listaLerArquivo(arquivo, nfuncionarios);

                //Retira um funcionário da lista
                listaArquivo = listaRetira(listaArquivo, dado);

                //Escreve a lista no arquivo
                listaEscreveArquivo(listaArquivo, arquivo);

                //Libera a lista
                liberaFuncionario(listaArquivo);

                break;

            case 3:
                //Quantifica a quantidade de funcionários no arquivo
                nfuncionarios = quantificaFuncionarios(arquivo);

                //Copia os dados dos funcionários do arquivo, e cria uma lista com esses dados
                listaArquivo = listaLerArquivo(arquivo, nfuncionarios);
                
                //Imprime a lista
                imprimeLista(listaArquivo);

                //Libera a lista
                liberaFuncionario(listaArquivo);

                break;

            case 4:

                //Laço de repetição para receber o nome ou o documento do funcionário
                do
                {   
                    printf("Informe o nome/documento do funcionário: ");
                    scanf(" %[^\n]", dado);
                    resultado = trataString(dado);
                }while(resultado != 0);

                //Quantifica a quantidade de funcionários no arquivo
                nfuncionarios = quantificaFuncionarios(arquivo);

                //Copia os dados dos funcionários do arquivo, e cria uma lista com esses dados
                listaArquivo = listaLerArquivo(arquivo, nfuncionarios);

                //Busca o funcionário na lista
                buscaFuncionario(listaArquivo, dado);

                //Libera a lista
                liberaFuncionario(listaArquivo);

                break;

            case 5:
                //Laço de repetição para receber o nome ou o documento do funcionário
                do
                {   
                    printf("Informe o nome/documento do funcionário: ");
                    scanf(" %[^\n]", dado);
                    resultado = trataString(dado);
                }while(resultado != 0);

                //Quantifica a quantidade de funcionários no arquivo
                nfuncionarios = quantificaFuncionarios(arquivo);

                //Copia os dados dos funcionários do arquivo, e cria uma lista com esses dados
                listaArquivo = listaLerArquivo(arquivo, nfuncionarios);

                //Edita o cadastro do funcionário
                editarCadastro(listaArquivo, dado);

                //Escreve a lista no arquivo
                listaEscreveArquivo(listaArquivo, arquivo);

                //Libera a lista
                liberaFuncionario(listaArquivo);

                break;

            case 6:
                //Imprime o valor da receita da empresa 
                printf("Receita: %d\n", empresa->receita);

                break;

            case 7:
                //Quantifica a quantidade de funcionários no arquivo
                nfuncionarios = quantificaFuncionarios(arquivo);

                //Copia os dados dos funcionários do arquivo, e cria uma lista com esses dados
                listaArquivo = listaLerArquivo(arquivo, nfuncionarios);
                
                //Imprime a quantidade de funcionários por cargos
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

                //Libera a lista
                liberaFuncionario(listaArquivo);

                break;

            default:
                //Verifica se a opção é diferente de 8
                if(opcao1 != 8){
                    printf("Opção Inválida\n");
                }

                break;
        }

    }while(opcao1 != 8);

    //Libera a empresa
    liberaEmpresa(empresa);

    //Informa o usuário do termino do programa
    printf("Programa Encerrado\n");

    return 0;
}
