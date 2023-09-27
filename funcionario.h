typedef struct funcionario Funcionario;

int trataNome(char nome[21]);

Funcionario *insereFuncionario(Funcionario *ponteiroLista, char *nome, char *documento, char *setor, float salario, char *data, char *jornada);

Funcionario*BuscaFuncionario(Funcionario*ponteiroLista,char*nome);

void imprimeFuncionarios(Funcionario *ponteiroLista);
