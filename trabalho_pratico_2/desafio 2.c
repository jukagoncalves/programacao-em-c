#include <stdio.h>
#include <stdlib.h>
#define MAX_VAGAS 40
#define NUM_PROGRAMAS 3

// Estrutura para armazenar os dados do estudante
typedef struct {
	int codigo;
	int nota;
} Estudante;

// Função para inserir um estudante no programa, mantendo a ordem decrescente de notas
void inserirEstudante(Estudante programa[], int*num_estudantes, int codigo, int nota) {
	int i, j;
	if (*num_estudantes < MAX_VAGAS) {
		// Inserção simples se houver vagas
		programa[*num_estudantes].codigo = codigo;
		programa[*num_estudantes].nota = nota;
		(*num_estudantes)++;
		} else {
		// Se não houver vagas, verifica se a nota é maior que a menor nota existente
		if (nota > programa[MAX_VAGAS - 1].nota) {
			programa[MAX_VAGAS - 1].codigo = codigo;
			programa[MAX_VAGAS - 1].nota = nota;
			}
	}
	// Ordena o array em ordem decrescente de notas
	for (i = 0; i < *num_estudantes - 1; i++) {
		for (j = i + 1; j < *num_estudantes; j++) {
			if (programa[i].nota < programa[j].nota) {
				Estudante temp = programa[i];
				programa[i] = programa[j];
				programa[j] = temp;
			}
		}
	}
}

int main() {
	Estudante bolsas[NUM_PROGRAMAS][MAX_VAGAS];
	int num_estudantes_programa[NUM_PROGRAMAS] = {0, 0, 0};
	int codigo_estudante, nota_final, programa_desejado;
	char continuar = 's';
	int i, j;

	while (continuar == 's' || continuar == 'S') {
		printf("\n--- Inserção de Candidato ---\n");
		printf("Código do estudante: ");
		scanf("%d", &codigo_estudante);
		printf("Nota final (0-100): ");
		scanf("%d", &nota_final);
		while (nota_final < 0 || nota_final > 100) {
			printf("Nota inválida. Digite um valor entre 0 e 100: ");
			scanf("%d", &nota_final);
		}
		printf("Programa desejado (1-Pesquisa, 2-Extensão, 3-Monitoria): ");
		scanf("%d", &programa_desejado);
		while (programa_desejado < 1 || programa_desejado > 3) {
			printf("Programa inválido. Digite 1, 2 ou 3: ");
			scanf("%d", &programa_desejado);
			}
		// Ajusta o índice do programa (0-based)
		programa_desejado--;
		inserirEstudante(bolsas[programa_desejado],&num_estudantes_programa[programa_desejado], codigo_estudante,nota_final);
		printf("Deseja inserir outro candidato? (s/n): ");
		scanf(" %c", &continuar);
	}
	// Exibir a lista dos 40 selecionados para cada programa
	printf("\n--- Candidatos Selecionados por Programa ---\n");
	for (i = 0; i < NUM_PROGRAMAS; i++) {
		printf("\nPrograma %d (%s) ---\n", i + 1, (i == 0 ? "Pesquisa" : (i == 1 ? "Extensão" : "Monitoria")));
		if (num_estudantes_programa[i] == 0) {
			printf("Nenhum estudante selecionado para este programa.\n");
			} 
			else {
				for (j = 0; j < num_estudantes_programa[i]; j++) {
					printf("Código: %d, Nota: %d\n", bolsas[i][j].codigo, bolsas[i][j].nota);
				}
			}
		}
	return 0;
}
