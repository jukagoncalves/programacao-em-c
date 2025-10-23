#include <stdio.h>
#include <math.h>

int main() {
	int numero, num_original, i, digito, num_digitos, soma;
	
	num_digitos = 0;
	soma = 0;
	
	printf("Digite um numero: ");
	scanf("%d", &numero);
	num_original = numero;
	
	//contar digitos
	for(i = numero; i != 0; i /= 10)
		num_digitos++;
		
	//somar cada digito de acordo com a potencia
	for(i = numero; i != 0; i /= 10)
	{
		digito = i % 10;
		soma += pow(digito, num_digitos);
	}
	
	if(soma == num_original)
		printf("%d e um numero narcisista!\n", num_original);
	else
		printf("%d nao e um numero narcisista!\n", num_original);
		
	return 0;
}
