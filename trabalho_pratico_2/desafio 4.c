#include <stdio.h>
#include <string.h>

#define MAX_COLABORADORES 10
#define MAX_REUNIOES 20
#define MAX_NOME 50
#define MAX_DEPARTAMENTO 30
#define MAX_TELEFONE 15

// Estrutura para armazenar dados do colaborador
typedef struct {
    int codigo;
    char nome[MAX_NOME];
    char departamento[MAX_DEPARTAMENTO];
    char telefone[MAX_TELEFONE];
} Colaborador;

// Estrutura para armazenar dados da reuni�o
typedef struct {
    int codigo_colaborador;
    int dia;
    int mes;
    int hora;
    char tipo_reuniao[MAX_NOME]; // Interna ou Cliente
} Reuniao;

Colaborador colaboradores[MAX_COLABORADORES];
Reuniao reunioes[MAX_REUNIOES];
int num_colaboradores = 0;
int num_reunioes = 0;
int i,j;

// Fun��o para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1. Cadastro de colaboradores
void cadastrarColaborador() {
    if (num_colaboradores < MAX_COLABORADORES) {
        Colaborador novo_colaborador;
        printf("\n--- Cadastro de Colaborador ---\n");
        printf("C�digo identificador (inteiro): ");
        scanf("%d", &novo_colaborador.codigo);

        // Verifica se o c�digo j� existe
        for (i = 0; i < num_colaboradores; i++) {
            if (colaboradores[i].codigo == novo_colaborador.codigo) {
                printf("Erro: C�digo de colaborador j� existe. Tente novamente.\n");
                return;
            }
        }

        printf("Nome do colaborador: ");
        limparBuffer();
        fgets(novo_colaborador.nome, MAX_NOME, stdin);
        novo_colaborador.nome[strcspn(novo_colaborador.nome, "\n")] = 0;

        printf("Departamento: ");
        fgets(novo_colaborador.departamento, MAX_DEPARTAMENTO, stdin);
        novo_colaborador.departamento[strcspn(novo_colaborador.departamento, "\n")] = 0;

        printf("Telefone de contato: ");
        fgets(novo_colaborador.telefone, MAX_TELEFONE, stdin);
        novo_colaborador.telefone[strcspn(novo_colaborador.telefone, "\n")] = 0;

        colaboradores[num_colaboradores++] = novo_colaborador;
        printf("Colaborador cadastrado com sucesso!\n");
    } else {
        printf("Limite de colaboradores atingido.\n");
    }
}

// 2. Reserva de salas
void reservarSala() {
    if (num_reunioes < MAX_REUNIOES) {
        Reuniao nova_reuniao;
        printf("\n--- Reserva de Sala ---\n");
        printf("C�digo do colaborador respons�vel pela reserva: ");
        scanf("%d", &nova_reuniao.codigo_colaborador);

        // Verifica se o colaborador existe
        int colaborador_existe = 0;
        for (i = 0; i < num_colaboradores; i++) {
            if (colaboradores[i].codigo == nova_reuniao.codigo_colaborador) {
                colaborador_existe = 1;
                break;
            }
        }
        if (!colaborador_existe) {
            printf("Erro: Colaborador n�o cadastrado. Cadastre-o primeiro.\n");
            return;
        }

        printf("Data (dia e m�s - ex: 15 06): ");
        scanf("%d %d", &nova_reuniao.dia, &nova_reuniao.mes);
        printf("Hora (formato 24h, apenas hora cheia - ex: 9, 10, 14): ");
        scanf("%d", &nova_reuniao.hora);

        // Verifica conflito de hor�rio e sala
        for (i = 0; i < num_reunioes; i++) {
            if (reunioes[i].dia == nova_reuniao.dia &&
                reunioes[i].mes == nova_reuniao.mes &&
                reunioes[i].hora == nova_reuniao.hora) {
                printf("Erro: J� existe uma reuni�o agendada para esta data e hora.\n");
                return;
            }
        }

        printf("Tipo de reuni�o (Interna ou Cliente): ");
        limparBuffer();
        fgets(nova_reuniao.tipo_reuniao, MAX_NOME, stdin);
        nova_reuniao.tipo_reuniao[strcspn(nova_reuniao.tipo_reuniao, "\n")] = 0;

        reunioes[num_reunioes++] = nova_reuniao;
        printf("Reserva realizada com sucesso!\n");
    } else {
        printf("Limite de reuni�es atingido.\n");
    }
}

// 3. Altera��o de dados do colaborador
void alterarDadosColaborador() {
    int codigo_busca;
    printf("\n--- Alterar Dados do Colaborador ---\n");
    printf("Digite o c�digo do colaborador para alterar: ");
    scanf("%d", &codigo_busca);

    for (i = 0; i < num_colaboradores; i++) {
        if (colaboradores[i].codigo == codigo_busca) {
            printf("Colaborador encontrado. Digite os novos dados:\n");
            printf("Nome do colaborador (%s): ", colaboradores[i].nome);
            limparBuffer();
            fgets(colaboradores[i].nome, MAX_NOME, stdin);
            colaboradores[i].nome[strcspn(colaboradores[i].nome, "\n")] = 0;

            printf("Departamento (%s): ", colaboradores[i].departamento);
            fgets(colaboradores[i].departamento, MAX_DEPARTAMENTO, stdin);
            colaboradores[i].departamento[strcspn(colaboradores[i].departamento, "\n")] = 0;

            printf("Telefone de contato (%s): ", colaboradores[i].telefone);
            fgets(colaboradores[i].telefone, MAX_TELEFONE, stdin);
            colaboradores[i].telefone[strcspn(colaboradores[i].telefone, "\n")] = 0;

            printf("Dados do colaborador atualizados com sucesso!\n");
            return;
        }
    }
    printf("Colaborador com c�digo %d n�o encontrado.\n", codigo_busca);
}

// 4. Listagem de reuni�es agendadas
void listarReunioesAgendadas() {
    printf("\n--- Reuni�es Agendadas ---\n");
    if (num_reunioes == 0) {
        printf("Nenhuma reuni�o agendada.\n");
        return;
    }

    for (i = 0; i < num_reunioes; i++) {
        char nome_colaborador[MAX_NOME] = "Desconhecido";
        for (j = 0; j < num_colaboradores; j++) {
            if (colaboradores[j].codigo == reunioes[i].codigo_colaborador) {
                strcpy(nome_colaborador, colaboradores[j].nome);
                break;
            }
        }
        printf("\nReuni�o %d:\n", i + 1);
        printf("  Colaborador: %s\n", nome_colaborador);
        printf("  Data: %02d/%02d\n", reunioes[i].dia, reunioes[i].mes);
        printf("  Hora: %02dh\n", reunioes[i].hora);
        printf("  Tipo: %s\n", reunioes[i].tipo_reuniao);
    }
}

// 5. Lista para notifica��o de agenda
void gerarListaNotificacao() {
    printf("\n--- Lista para Notifica��o de Agenda ---\n");
    if (num_reunioes == 0) {
        printf("Nenhuma reuni�o para notifica��o.\n");
        return;
    }

    for (i = 0; i < num_reunioes; i++) {
        char nome_colaborador[MAX_NOME] = "Desconhecido";
        for (j = 0; j < num_colaboradores; j++) {
            if (colaboradores[j].codigo == reunioes[i].codigo_colaborador) {
                strcpy(nome_colaborador, colaboradores[j].nome);
                break;
            }
        }
        printf("  %s - %02d/%02d �s %02dh\n", nome_colaborador, reunioes[i].dia, reunioes[i].mes, reunioes[i].hora);
    }
}

int main() {
    int opcao;

    do {
        printf("\n--- Menu Principal - Gerenciamento de Reuni�es ---\n");
        printf("1. Cadastrar colaborador\n");
        printf("2. Reservar sala\n");
        printf("3. Alterar dados do colaborador\n");
        printf("4. Listar reuni�es agendadas\n");
        printf("5. Gerar lista para notifica��o de agenda\n");
        printf("0. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarColaborador();
                break;
            case 2:
                reservarSala();
                break;
            case 3:
                alterarDadosColaborador();
                break;
            case 4:
                listarReunioesAgendadas();
                break;
            case 5:
                gerarListaNotificacao();
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}



