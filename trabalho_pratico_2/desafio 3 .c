#include <stdio.h>
#include <string.h>

#define PRODUTOS 6
#define CAMPOS 3
#define TAM_NOME 30

int main() {
    char descricao[PRODUTOS][TAM_NOME];
    float dados[PRODUTOS][CAMPOS]; // [0] estoque, [1] m�nimo, [2] valor
    int i, opcao;

    do {
        printf("\n=== MENU ESTOQUE LANCHONETE ===\n");
        printf("1 - Cadastrar produtos\n");
        printf("2 - Retirar produto do estoque\n");
        printf("3 - Mostrar produtos com estoque abaixo do m�nimo\n");
        printf("4 - Mostrar valor total do estoque\n");
        printf("0 - Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer

        switch (opcao) {
            case 1:
                printf("\n=== Cadastro de Produtos ===\n");
                for (i = 0; i < PRODUTOS; i++) {
                    printf("\nProduto %d\n", i + 1);

                    printf("Descri��o: ");
                    fgets(descricao[i], TAM_NOME, stdin);
                    descricao[i][strcspn(descricao[i], "\n")] = 0; // remove \n

                    // Quantidade m�nima
                    do {
                        printf("Quantidade m�nima exigida: ");
                        scanf("%f", &dados[i][1]);
                        if (dados[i][1] < 0)
                            printf("Erro: valor inv�lido.\n");
                    } while (dados[i][1] < 0);

                    // Quantidade em estoque
                    do {
                        printf("Quantidade em estoque: ");
                        scanf("%f", &dados[i][0]);
                        if (dados[i][0] < dados[i][1])
                            printf("Erro: estoque n�o pode ser inferior ao m�nimo.\n");
                    } while (dados[i][0] < dados[i][1]);

                    // Valor unit�rio
                    do {
                        printf("Valor unit�rio: R$ ");
                        scanf("%f", &dados[i][2]);
                        if (dados[i][2] <= 0)
                            printf("Erro: valor deve ser maior que zero.\n");
                    } while (dados[i][2] <= 0);

                    getchar(); // limpa o buffer
                }
                break;

            case 2: {
                printf("\n=== Retirar Produto do Estoque ===\n");
                char nomeBusca[TAM_NOME];
                int encontrado = -1;
                float qtdRetirar;

                printf("Digite o nome do produto: ");
                fgets(nomeBusca, TAM_NOME, stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = 0;

                for (i = 0; i < PRODUTOS; i++) {
                    if (strcmp(nomeBusca, descricao[i]) == 0) {
                        encontrado = i;
                        break;
                    }
                }

                if (encontrado == -1) {
                    printf("Erro: produto n�o encontrado.\n");
                } else {
                    printf("Quantidade a retirar: ");
                    scanf("%f", &qtdRetirar);
                    if (qtdRetirar <= dados[encontrado][0]) {
                        dados[encontrado][0] -= qtdRetirar;
                        printf("Retirada realizada com sucesso. Novo estoque: %.2f\n", dados[encontrado][0]);
                    } else {
                        printf("Estoque insuficiente.\n");
                    }
                }
                getchar(); // limpa buffer
                break;
            }

            case 3:
                printf("\n=== Produtos com estoque abaixo do m�nimo ===\n");
                int achou = 0;
                for (i = 0; i < PRODUTOS; i++) {
                    if (dados[i][0] < dados[i][1]) {
                        printf("Produto: %s | Estoque: %.2f | M�nimo: %.2f\n", descricao[i], dados[i][0], dados[i][1]);
                        achou = 1;
                    }
                }
                if (!achou)
                    printf("Todos os produtos est�o com estoque adequado.\n");
                break;

            case 4: {
                printf("\n=== Valor Total do Estoque ===\n");
                float total = 0;
                for (i = 0; i < PRODUTOS; i++) {
                    total += dados[i][0] * dados[i][2];
                }
                printf("Valor total do estoque: R$ %.2f\n", total);
                break;
            }

            case 0:
                printf("Encerrando o sistema.\n");
                break;

            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

