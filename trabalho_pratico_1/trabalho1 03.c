#include <stdio.h>

int main() {
	int n1, n2, i, soma1, soma2;
	
	soma1 = 0;
	soma2 = 0;
	
	printf("Digite o primeiro numero: ");
	scanf("%d", &n1);
	printf("Digite o segundo numero: ");
	scanf("%d", &n2);
	
	//calculo da soma dos divisores
	for(i = 1; i < n1; i++)
	{
		if(n1 % i == 0)
			soma1 += i;
	}
	
	for(i = 1; i < n2; i++)
	{
		if(n2 % i == 0)
			soma2 += i;
	}
	
	if(soma1 == n2 || soma2 == n1)
		printf("Os numeros %d e %d sao amigaveis!\n", n1, n2);
	else
		printf("Os numeros %d e %d nao sao amigaveis!\n", n1, n2);
	
	return 0;
}

