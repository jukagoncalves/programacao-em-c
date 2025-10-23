#include <stdio.h>
#include <string.h>

#define MAX_CARGOS 5
#define MAX_FUNCIONARIOS 15
#define MAX_NOME 50

// Estrutura para armazenar dados do cargo
typedef struct {
    int codigo;
    float salario;
} Cargo;

// Estrutura para armazenar dados do funcionário
typedef struct {
    int codigo;
    char nome[MAX_NOME];
    int codigo_cargo;
} Funcionario;

Cargo cargos[MAX_CARGOS];
Funcionario funcionarios[MAX_FUNCIONARIOS];
int num_cargos = 0;
int num_funcionarios = 0;
int i,j;

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Valida o número do funcionário (único)
int validarCodigoFuncionario(int codigo) {
    for (i = 0; i < num_funcionarios; i++) {
        if (funcionarios[i].codigo == codigo) {
            return 0; // Código já existe
        }
    }
    return 1; // Código único
}

// Valida o nome do funcionário (pelo menos duas palavras)
int validarNomeFuncionario(char *nome) {
    int espacos = 0;
    for (i = 0; nome[i] != '\0'; i++) {
        if (nome[i] == ' ') {
            espacos++;
        }
    }
    return espacos >= 1; // Pelo menos um espaço, indicando duas palavras
}

// Valida se o código do cargo existe
int validarCodigoCargo(int codigo_cargo) {
    for (i = 0; i < num_cargos; i++) {
        if (cargos[i].codigo == codigo_cargo) {
            return 1; // Cargo existe
        }
    }
    return 0; // Cargo não existe
}

// 1. Cadastrar cargos da empresa
void cadastrarCargos() {
    if (num_cargos < MAX_CARGOS) {
        printf("\n--- Cadastro de Cargo ---\n");
        printf("Código do cargo: ");
        scanf("%d", &cargos[num_cargos].codigo);
        printf("Salário do cargo: ");
        scanf("%f", &cargos[num_cargos].salario);
        num_cargos++;
        printf("Cargo cadastrado com sucesso!\n");
    } else {
        printf("Salários dos cargos já cadastrados (limite de 5 cargos atingido).\n");
    }
}

// 2. Cadastrar funcionários da empresa
void cadastrarFuncionario() {
    if (num_funcionarios < MAX_FUNCIONARIOS) {
        Funcionario novo_funcionario;
        printf("\n--- Cadastro de Funcionário ---\n");
        printf("Número do funcionário: ");
        scanf("%d", &novo_funcionario.codigo);
        while (!validarCodigoFuncionario(novo_funcionario.codigo)) {
            printf("Erro: Número de funcionário já existe. Digite novamente: ");
            scanf("%d", &novo_funcionario.codigo);
        }

        printf("Nome do funcionário (nome e sobrenome): ");
        limparBuffer();
        fgets(novo_funcionario.nome, MAX_NOME, stdin);
        novo_funcionario.nome[strcspn(novo_funcionario.nome, "\n")] = 0;
        while (!validarNomeFuncionario(novo_funcionario.nome)) {
            printf("Erro: Nome deve conter pelo menos duas palavras. Digite novamente: ");
            fgets(novo_funcionario.nome, MAX_NOME, stdin);
            novo_funcionario.nome[strcspn(novo_funcionario.nome, "\n")] = 0;
        }

        printf("Código do cargo: ");
        scanf("%d", &novo_funcionario.codigo_cargo);
        while (!validarCodigoCargo(novo_funcionario.codigo_cargo)) {
            printf("Erro: Código do cargo não existe. Digite novamente: ");
            scanf("%d", &novo_funcionario.codigo_cargo);
        }

        funcionarios[num_funcionarios++] = novo_funcionario;
        printf("Funcionário cadastrado com sucesso!\n");
    } else {
        printf("Limite de funcionários atingido (máximo de 15 funcionários).\n");
    }
}

// 3. Mostrar um relatório contendo o número, o nome e o valor do salário de todos os funcionários
void mostrarRelatorioFuncionarios() {
    printf("\n--- Relatório de Funcionários ---\n");
    if (num_funcionarios == 0) {
        printf("Nenhum funcionário cadastrado.\n");
        return;
    }

    for (i = 0; i < num_funcionarios; i++) {
        float salario_funcionario = 0;
        for (j = 0; j < num_cargos; j++) {
            if (cargos[j].codigo == funcionarios[i].codigo_cargo) {
                salario_funcionario = cargos[j].salario;
                break;
            }
        }
        printf("Número: %d, Nome: %s, Salário: R$ %.2f\n", funcionarios[i].codigo, funcionarios[i].nome, salario_funcionario);
    }
}

// 4. Mostrar o valor pago aos funcionários que pertençam a um cargo informado pelo usuário
void mostrarValorPagoPorCargo() {
    int codigo_cargo_busca;
    float total_pago = 0;
    printf("\n--- Valor Pago por Cargo ---\n");
    printf("Digite o código do cargo para consultar: ");
    scanf("%d", &codigo_cargo_busca);

    if (!validarCodigoCargo(codigo_cargo_busca)) {
        printf("Erro: Código do cargo não existe.\n");
        return;
    }

    for (i = 0; i < num_funcionarios; i++) {
        if (funcionarios[i].codigo_cargo == codigo_cargo_busca) {
            for (j = 0; j < num_cargos; j++) {
                if (cargos[j].codigo == codigo_cargo_busca) {
                    total_pago += cargos[j].salario;
                    break;
                }
            }
        }
    }
    printf("Valor total pago para o cargo %d: R$ %.2f\n", codigo_cargo_busca, total_pago);
}

int main() {
    int opcao;

    do {
        printf("\n--- Menu Principal - Gerenciamento de Pessoal ---\n");
        printf("1. Cadastrar cargos da empresa\n");
        printf("2. Cadastrar funcionários da empresa\n");
        printf("3. Mostrar relatório de todos os funcionários\n");
        printf("4. Mostrar valor pago aos funcionários por cargo\n");
        printf("5. Finalizar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCargos();
                break;
            case 2:
                cadastrarFuncionario();
                break;
            case 3:
                mostrarRelatorioFuncionarios();
                break;
            case 4:
                mostrarValorPagoPorCargo();
                break;
            case 5:
                printf("Finalizando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}



