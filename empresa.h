//Struct Empresa
typedef struct empresa Empresa;

//Função para criar a empresa
Empresa *criaEmpresa(void);

//Função para imprimir informações sobre a Empresa
void imprimeEmpresa(Empresa *empresa);

//Função para liberar a memória alocada para a Empresa

void liberaEmpresa(Empresa *empresa);

