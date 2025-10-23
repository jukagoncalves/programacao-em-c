#include <stdio.h>
#define MAX_STUDENTS 5

int main() {
	int matriculas[MAX_STUDENTS];
	float notas[MAX_STUDENTS];
	int faltas[MAX_STUDENTS];
	int i;
	float nota_corte;
	
	// Inserção de dados dos estudantes
	printf("Cadastro de Estudantes:\n");
	for (i = 0; i < MAX_STUDENTS; i++) {
		printf("Estudante %d:\n", i + 1);
		printf("Matrícula: ");
		scanf("%d", &matriculas[i]);
		printf("Nota Final (0-100): ");
		scanf("%f", &notas[i]);
		// Validação da nota
		while (notas[i] < 0 || notas[i] > 100) {
			printf("Nota inválida. Digite um valor entre 0 e 100: ");
			scanf("%f", &notas[i]);
		}
		printf("Quantidade de Faltas: ");
		scanf("%d", &faltas[i]);
	}
	
	// a) Relatórios com base na nota de corte
	printf("\nDigite a nota de corte: ");
	scanf("%f", &nota_corte);
	printf("\n--- Estudantes com nota menor ou igual à nota de corte (%.2f) ---\n", nota_corte);
	int count_menor_igual = 0;
	for (i = 0; i < MAX_STUDENTS; i++) {
		if (notas[i] <= nota_corte) {
		printf("Matrícula: %d, Nota: %.2f\n",
		matriculas[i], notas[i]);
		count_menor_igual++;
		}
	}
	if (count_menor_igual == 0) {
		printf("Nenhum estudante nesta categoria.\n");
	}
	printf("\n--- Estudantes com nota maior que a nota de corte(%.2f) ---\n", nota_corte);
	int count_maior = 0;
	for (i = 0; i < MAX_STUDENTS; i++) {
		if (notas[i] > nota_corte) {
		printf("Matrícula: %d, Nota: %.2f\n",
		matriculas[i], notas[i]);
		count_maior++;
		}
	}
	if (count_maior == 0) {
		printf("Nenhum estudante nesta categoria.\n");
	}
	
	// b) Menor nota registrada
	float menor_nota = notas[0];
	for (i = 1; i < MAX_STUDENTS; i++) {
		if (notas[i] < menor_nota) {
		menor_nota = notas[i];
		}
	}
	printf("\n--- Menor Nota Registrada ---\n");
	printf("Menor nota: %.2f\n", menor_nota);
	printf("Estudantes que obtiveram a menor nota:\n");
	int count_menor_nota = 0;
	for (i = 0; i < MAX_STUDENTS; i++) {
		if (notas[i] == menor_nota) {
		printf("Matrícula: %d\n", matriculas[i]);
		count_menor_nota++;
		}
	}
	printf("Total de estudantes com a menor nota: %d\n",count_menor_nota);
	return 0;
}
