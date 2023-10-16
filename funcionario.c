#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionario.h"

//Definição da struct Funcionário
struct funcionario
{
    char nome[51]; //Nome do funcionário
    char documento[51]; //Documento do funcionário
    char cargo[51]; //Cargo do funcionário
    char setor[51]; //Setor de trabalho do funcionário
    int salario; //Salário do funcionário
    char dataContratacao[51]; //Data de contratação do funcionário
    char jornadaTrabalho[51]; //Jornada de tarabalho do funcionário
    struct funcionario *proximo; //Ponteiro para uma struct funcionário
};

//Função para criar uma lista de funcionários
Funcionario *criaFuncionario(void)
{
    //Retorna NULL para o ponteiro da lista
    return NULL;
}

void criarArquivo(char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "r");
    
    if(arquivo == NULL){
        // O arquivo não existe, então criamos um novo
        arquivo = fopen(nomeArquivo, "w");
        if (arquivo != NULL) {
            fclose(arquivo);
        } else {
            // Lidar com erro ao criar o arquivo, se necessário
        }
    } else{
        fclose(arquivo);
    }
}

//Função para limpar o buffer
void LimpaBuffer(void)
{
    int valorLido; 

    //Laço de repetição para ler os caracteres do buffer até encontrar uma quebra de linha ('\n') ou o fim de arquivo (EOF)
    do
    {   
        // Lê um caractere do buffer
        valorLido = getchar(); 
    }while((valorLido != '\n') && (valorLido != EOF));
}

//Função para corrigir as strings inseridas pelo usuário
int trataString(char *string)
{
    int i, tamanhoString = strlen(string);
  
    //Verifica se o nome é muito pequeno
    if(tamanhoString <= 2){
        printf("Entrada Pequena\n");
        return 1;
    }
    
    //Verifica se o nome contém caracteres especiais
    for(i = 0; string[i] != '\0'; i++){
        if(!isalnum(string[i]) && string[i] != ' ' && string[i] != '/' && string[i] != '.'){
            printf("Entrada Inválida\n");
            return 1;
        }
    }
    
    //Converte o nome para maiúsculo
    for(i = 0; string[i] != '\0'; i++){
        string[i] = toupper(string[i]);
    }
    
    return 0;
}

//Função para contar a quantidade de funcionários
int quantificaFuncionarios(FILE *arquivo)
{
    int nlinhas = 1, c;

    //Abre o arquivo para ler
    arquivo = fopen("funcionarios.txt", "r"); 
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    //Conta a quantidade de linhas do arquivo
    while((c = fgetc(arquivo)) != EOF){
        if(c == '\n'){
            nlinhas++;
        }
    }

    //Retorna a quantidade de funcionários
    return nlinhas/7;
}

//Função para inserir um novo funcionários em uma lista encadeda simples
Funcionario *insereFuncionario(Funcionario *lista)
{
    char nome[51]; 
    char documento[51]; 
    char cargo[51]; 
    char setor[51]; 
    int salario = 0, resultado = 0; 
    char dataContratacao[51]; 
    char jornadaTrabalho[51];

    Funcionario *novo = (Funcionario *) malloc(sizeof(Funcionario));
    if(novo == NULL){
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    //Loop para pedir o nome do funcionário
    do
    {   
        printf("Informe o Nome: ");
        scanf(" %[^\n]", nome);
        while(!isalpha(nome[0]))
        {   
            printf("Entrada Inválida\n");
            printf("Informe seu nome: ");
            scanf(" %[^\n]", nome); 
        }
        resultado = trataString(nome);
    }while(resultado != 0);

    //Loop para pedir o documento do funcionário
    do
    {   
        printf("Informe o Documento(CPF/RG): ");
        scanf(" %[^\n]", documento);
        resultado = trataString(documento);
    }while(resultado != 0);

    //Loop para pedir o cargo do funcionário
    do
    {   
        printf("Informe o Cargo: ");
        scanf(" %[^\n]", cargo);
        while(!isalpha(nome[0]))
        {   
            printf("Entrada Inválida\n");
            printf("Informe seu nome: ");
            scanf(" %[^\n]", nome); 
        }
        resultado = trataString(cargo);
    }while(resultado != 0);

    //Loop para pedir o setor do funcionário                            
    do
    {   
        printf("Informe o Setor: ");
        scanf(" %[^\n]", setor);

        while(!isalpha(nome[0]))//Veirica se o primeiro caracter da string é caracter alfabético
        {   
            printf("Entrada Inválida\n");
            printf("Informe seu nome: ");
            scanf(" %[^\n]", nome); 
        }

        resultado = trataString(setor);
    }while(resultado != 0);

    //Pede o salário do funcionário                         
    printf("Informe o Salário: ");
    scanf(" %d", &salario);

    //Loop para pedir a data da contratação do funcionário
    do
    {   
        printf("Informe a data de contratação: ");
        scanf(" %[^\n]", dataContratacao);
        resultado = trataString(dataContratacao);
    }while(resultado != 0);

    //Loop para pedir a jornada de trabalho do funcionário
    do
    {   
        printf("Informe a Jornada de Trabalho: ");
        scanf(" %[^\n]", jornadaTrabalho);
        resultado = trataString(jornadaTrabalho);
    }while(resultado != 0);

    //Preenche os campos da struct 
    strcpy(novo->nome, nome);
    strcpy(novo->documento, documento);
    strcpy(novo->cargo, cargo);
    strcpy(novo->setor, setor);
    novo->salario = salario;
    strcpy(novo->dataContratacao, dataContratacao);
    strcpy(novo->jornadaTrabalho, jornadaTrabalho);

    //Faz o encademanto com a lista
    novo->proximo = lista;

    //Retorna o endereço 
    return novo;
}

//Função para receber os dados de um arquivo e criar um novo funcionário
Funcionario *insereFuncionarioArquivo(Funcionario *lista, char *nome, char *documento, char *cargo, char *setor, int salario, char *data, char *jornada)
{   
    //Aloca memória para um novo funcionário
    Funcionario *novo = (Funcionario *) malloc(sizeof(Funcionario));
    if(novo == NULL){
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    //Preenche os campos da struct 
    strcpy(novo->nome, nome);
    strcpy(novo->documento, documento);
    strcpy(novo->cargo, cargo);
    strcpy(novo->setor, setor);
    novo->salario = salario;
    strcpy(novo->dataContratacao, data);
    strcpy(novo->jornadaTrabalho, jornada);
    novo->proximo = lista;

    //Retorna o endereço 
    return novo;
}

//Função para ler os dados do arquivo
Funcionario *listaLerArquivo(FILE *arquivo, int nfuncionarios)
{   
    //Criar uma lista e declara as variáveis para armazenar os dados dos funcionários
    Funcionario *lista = criaFuncionario();
    int i;
    char nome[51]; 
    char documento[51]; 
    char cargo[51]; 
    char setor[51]; 
    int salario; 
    char dataContratacao[51]; 
    char jornadaTrabalho[51];

    //Abre o arquivo para leitura
    arquivo = fopen("funcionarios.txt", "r");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    //Laço de repetição para ler os copiar os dados do arquivo
    for(i = 0; i < nfuncionarios; i++){
        //Lê o nome do funcionário
        fgets(nome, sizeof(nome), arquivo);
        nome[strcspn(nome, "\n")] = '\0';

        //Lê o documento do funcionário
        fgets(documento, sizeof(documento), arquivo);
        documento[strcspn(documento, "\n")] = '\0';

        //Lê o cargo do funcionário
        fgets(cargo, sizeof(cargo), arquivo);
        cargo[strcspn(cargo, "\n")] = '\0';

        //Lê o setor do funcionário
        fgets(setor, sizeof(setor), arquivo);
        setor[strcspn(setor, "\n")] = '\0';
        
        //Lê o salário do funcionário
        fscanf(arquivo, "%d", &salario);
        getc(arquivo);

        //Lê a data de contratação do funcionário
        fgets(dataContratacao, sizeof(dataContratacao), arquivo);
        dataContratacao[strcspn(dataContratacao, "\n")] = '\0';

        //Lê a jornada de trabalho do funcionário
        fgets(jornadaTrabalho, sizeof(jornadaTrabalho), arquivo);
        jornadaTrabalho[strcspn(jornadaTrabalho, "\n")] = '\0';

        //Insere os dados do funcionário em uma lista encadeada simples
        lista = insereFuncionarioArquivo(lista, nome, documento, cargo, setor, salario, dataContratacao, jornadaTrabalho);
    }

    //Limpa o buffer
    LimpaBuffer();

    //Fecha o arquivo
    fclose(arquivo);

    return lista;
}

//Função para escrever a lista no arquivo
void listaEscreveArquivo(Funcionario *lista, FILE *arquivo)
{   
    //Ponteiro auxiliar
    Funcionario *atual = lista;

    //Abre o arquivo para escrever
    arquivo = fopen("funcionarios.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    //Laço de repetição para escrever os dados dos funcionários no arquivo
    while(atual != NULL){
        fprintf(arquivo, "%s\n%s\n%s\n%s\n%d\n%s\n%s\n", atual->nome, atual->documento, atual->cargo, atual->setor, atual->salario, atual->dataContratacao, atual->jornadaTrabalho);
        atual = atual->proximo;
    }

    //fecha o arquivo
    fclose(arquivo);
}

//função para concatenar as listas
Funcionario *concatenaListas(Funcionario *lista1, Funcionario *lista2)
{   
    //Ponteiro auxiliares
    Funcionario *atual = lista1;
    Funcionario * anterior = NULL;

    //Laço de repetição para percorrer a lista até chegar ao fim
    while(atual != NULL){
        anterior = atual;
        atual = atual->proximo;
    }

    //Concatena a primeira lista com a segunda
    anterior->proximo = lista2;

    //Retorna a lista
    return anterior;
}

//função para ordenar a lista em ordem alfabética
Funcionario *ordenaLista(Funcionario *lista)
{   
    //Verifica se a lista está vazia
    if(lista == NULL){
        printf("Lista Vazia\n");
        return lista;
    }

    //Ponteiros auxiliares
    Funcionario *i = NULL;
    Funcionario *j = NULL;

    //Laço de repetição para percorrer a lista
    for(i = lista; i->proximo != NULL; i = i->proximo){
        //Inicializa o ponteiro "menor" com o primeiro elemento da lista
        Funcionario *menor = i; 

        //Laço de repetição aninhado para encontrar o menor elemento da lista
        for(j = i->proximo; j != NULL; j = j->proximo){
            // Compara os nomes de funcionários para encontrar o menor
            if (strcmp(j->nome, menor->nome) < 0){
                menor = j;
            }
        }

        //Se o elemento "menor" não for igual a "i", troca os nomes
        if(menor != i){
            char aux[51];
            //Realiza a troca dos nomes usando uma variável auxiliar
            strcpy(aux, i->nome);
            strcpy(i->nome, menor->nome);
            strcpy(menor->nome, aux);
        }
    }

    //Retorna a lista ordenada
    return lista;
}

//Função para retirar um funcionário da lista
Funcionario *listaRetira(Funcionario *l, char *string)
{
    //Ponteiros auxiliares
    Funcionario  *ant = NULL;
    Funcionario  *p = l;

    //Laço de repetição para percorrer a lista enquanto não chegar ao final
    while(p != NULL)
    {
        //Verifica se o nome ou documento do funcionário atual coincide com a string fornecida
        if(strcmp(p->nome, string) == 0 || strcmp(p->documento, string) == 0)
        {
            //Se o elemento a ser removido está no início da lista
            if (ant == NULL)
                l = p->proximo;
            else
                ant->proximo = p->proximo;

            //Libera a memória alocada para o elemento a ser removido
            free(p);

            //Retorna a lista atualizada após a remoção
            return l;
        }
        
        //Atualiza os ponteiros para a próxima iteração
        ant = p;
        p = p->proximo;
    }

    //Retorna a lista original se o elemento não for encontrado
    return l; 
}

//Função para imprimir os dados de um funcionário
void imprimeFuncionario(Funcionario *lista, char *string)
{
    //Ponteiro auxiliar
    Funcionario * p;

    //Laço de repetição para percorrer a lista
	for(p = lista; p != NULL; p = p->proximo){
        //Verifica se o nome ou o documento são coincidem com as string fornecidos
		if(strcmp(p->nome, string) == 0 || strcmp(p->documento, string) == 0)

        //imprime os dados do funcionário
        printf("Nome: %s\nDocumento: %s\nCargo: %s\nSetor: %s\nSalário: %d\nData de Contratação: %s\nJornada de Trabalho: %s\n", p->nome, p->documento, p->cargo, p->setor, p->salario, p->dataContratacao, p->jornadaTrabalho);
	}
}

//Função para buscar por um funcionário na lista
void buscaFuncionario(Funcionario *lista, char *string)
{   
    //Ponteiro auxiliar
    Funcionario *p;
    int encontrado = 0; 

    //Laço de repetição para percorrer a lista
    for(p = lista; p != NULL; p = p->proximo){
        //Verifica se o nome ou o documento são coincidem com as string fornecidas
        if(strcmp(p->nome, string) == 0 || strcmp(p->documento, string) == 0){

            //Imprime os dados do funcionário
            printf("Funcionário Encontrado\n");
            printf("Nome: %s\nDocumento: %s\nCargo: %s\nSetor: %s\nSalário: %d\nData de Contratação: %s\nJornada de Trabalho: %s\n", p->nome, p->documento, p->cargo, p->setor, p->salario, p->dataContratacao, p->jornadaTrabalho);
            encontrado = 1; 
            break; 
        }
    }

    //Caso o funcionário não seja encontrado na lista
    if(!encontrado){
        printf("Funcionário Não Encontrado\n");
    }
}

//Função para editar o cadastro de um funcionário
Funcionario *editarCadastro(Funcionario *lista, char *string)
{
    //Ponteiro auxiliar
    Funcionario *p;

    //Laço de repetição para percorrer a lista
    for(p = lista; p != NULL; p = p->proximo){
        //Verifica se o nome ou o documento são coincidem com as string fornecidas
        if(strcmp(p->nome, string) == 0 || strcmp(p->documento, string) == 0){
            printf("Funcionário encontrado. Edite as informações:\n");

            //Declara as variáveis para 
            char novoNome[51];
            char novoDocumento[51];
            char novoCargo[51];
            char novoSetor[51];
            int novoSalario;
            char novaDataContratacao[51];
            char novaJornadaTrabalho[51];

            do {
                printf("Informe o novo nome: ");
                scanf(" %[^\n]", novoNome);
                if (trataString(novoNome) != 0) {
                    printf("Entrada Inválida\n");
                }
            } while (trataString(novoNome) != 0);

            do {
                printf("Informe o novo documento: ");
                scanf(" %[^\n]", novoDocumento);
                if (trataString(novoDocumento) != 0) {
                    printf("Entrada Inválida\n");
                }
            } while (trataString(novoDocumento) != 0);

            do {
                printf("Informe o novo cargo: ");
                scanf(" %[^\n]", novoCargo);
                if (trataString(novoCargo) != 0) {
                    printf("Entrada Inválida\n");
                }
            } while (trataString(novoCargo) != 0);

            do {
                printf("Informe o novo setor: ");
                scanf(" %[^\n]", novoSetor);
                if (trataString(novoSetor) != 0) {
                    printf("Entrada Inválida\n");
                }
            } while (trataString(novoSetor) != 0);

            printf("Informe o novo salário: ");
            scanf("%d", &novoSalario);

            do {
                printf("Informe a nova data de contratação: ");
                scanf(" %[^\n]", novaDataContratacao);
                if (trataString(novaDataContratacao) != 0) {
                    printf("Entrada Inválida\n");
                }
            } while (trataString(novaDataContratacao) != 0);

            do {
                printf("Informe a nova jornada de trabalho: ");
                scanf(" %[^\n]", novaJornadaTrabalho);
                if (trataString(novaJornadaTrabalho) != 0) {
                    printf("Entrada Inválida\n");
                }
            } while (trataString(novaJornadaTrabalho) != 0);

            //Atualiza as informações do funcionário
            strcpy(p->nome, novoNome);
            strcpy(p->documento, novoDocumento);
            strcpy(p->cargo, novoCargo);
            strcpy(p->setor, novoSetor);
            p->salario = novoSalario;
            strcpy(p->dataContratacao, novaDataContratacao);
            strcpy(p->jornadaTrabalho, novaJornadaTrabalho);

            printf("Informações atualizadas com sucesso.\n");
        }
    }

    printf("Funcionário não encontrado.\n");
}

//Função para quantificar os funcionários por cargos
int quantificaCargo(Funcionario *lista, char *string)
{   
    //Ponteri auxiliar
    Funcionario *p;
    int quantidade = 0; 

    //Laço de repetição para percorrer a lista
    for(p = lista; p != NULL; p = p->proximo){
        //Verirfica se a string fornecida coincide com a do campo cargo
        if(strcmp(p->cargo, string) == 0){
            //A quantidade é inclementada em um
            quantidade++;
        }
    }

    //Retorna a quantidade de funcionários presentes em tal cargo
    return quantidade;
}

//Função para imprimir a lista
void imprimeLista(Funcionario *l)
{
    //Ponteiro auxiliar
	Funcionario* p;

    //Laço de repetição para percorrer a lista
	for(p=l; p!=NULL; p=p->proximo){
        //Imprime os campos de cada elemento da lista
		printf("Nome: %s\nDocumento: %s\nCargo: %s\nSetor: %s\nSalário: %d\nData de Contratação: %s\nJornada de Trabalho: %s\n", p->nome, p->documento, p->cargo, p->setor, p->salario, p->dataContratacao, p->jornadaTrabalho);
	}
}

//Função para liberar da memória a lista
void liberaFuncionario(Funcionario *l)
{   
    //Ponteiros auxiliares
    Funcionario* p = l;
    Funcionario* t;

    //Laço de repetição para percorrer a lista
    while (p != NULL) {
        //t aponta para elemento à frente de p
        t = p->proximo;

        //Libera p
        free(p);
        
        //p aponta para o mesmo elemento que t aponta
        p = t;
    }
}