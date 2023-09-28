typedef struct funcionario Funcionario;

int trataNome(char nome[21]);

void LimpaBuffer(void);

Funcionario *insereFuncionario(Funcionario *lista, char *nome, char *documento, char *cargo, char *setor, float salario, char *data, char *jornada);

void imprime(Funcionario *l);