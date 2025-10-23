#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int numero, palpite, i, contador;
	
	srand(time(NULL)); // Inicializa o gerador de números aleatórios com base no tempo atual
	numero = rand() % 100;
	contador = 0;
	
	printf("|            JOGO DA ADIVINHACAO               |\n");
	printf("|Regras:                                       |\n");
	printf("|Tente adivinhar o numero secreto de 1 a 100!  |\n");
	printf("|Para desistir digite 0.                       |\n");
	
	for(i = 1; i<= 100; i++){
		printf("\nTente adivinhar o numero (1-100): ");
		scanf("%d", &palpite);
		contador ++;
		
		if(palpite == 0){
			contador -= 1;
			printf("\nVoce desistiu!");
			printf("\nO numero secreto era %d.", numero);
			printf("\nVoce teve %d tentativas de acerto!", contador);
			break;
		} else if (palpite == numero){
			printf("\nCorreto!");
			printf("\nVoce teve %d tentativas de acerto!", contador);
			break;
		} else if(palpite < numero){
			printf("\nMuito baixo!\n");
		} else if(palpite > numero ){
			printf("\nMuito alto!\n");
		}
	}
	return 0;
}
