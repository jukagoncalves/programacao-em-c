#include <stdio.h>

int main() {
	float salario_minimo, salario_funcionario, taxa_paga;
	float imposto_bruto, taxa_adicional, imposto_total, debito;
	int n_dependentes;
	
	printf("Digite o valor do salario minimo: ");
	scanf("%f", &salario_minimo);
	printf("Digite o numero de dependentes: ");
	scanf("%d", &n_dependentes);
	printf("Digite o seu salario: ");
	scanf("%f", &salario_funcionario);
	printf("Digite a taxa de imposto normal (ja pago): ");
	scanf("%f", &taxa_paga);
	
	if(salario_funcionario > (12*salario_minimo))
		imposto_bruto = salario_funcionario * 20 / 100;
	else if(salario_funcionario > (5*salario_minimo))
			imposto_bruto = salario_funcionario * 8 / 100;
	else
		imposto_bruto = 0.0;	

	taxa_adicional = imposto_bruto * 4 /100;
	imposto_total = imposto_bruto + taxa_adicional;
	debito = imposto_total - taxa_paga;
	
	printf("\nO imposto bruto e de: %.2f R$.", imposto_bruto);
	printf("\nA taxa adicional e de: %.2f R$.", taxa_adicional);
	printf("\nO valor cobrado de imposto de renda e de: %.2f R$.", imposto_total);
	
	if(debito > 0.0)
		printf("\nVoce deve pagar: %.2f R$.", debito);
	else if(debito < 0.0)
		printf("\nVoce tem uma restituicao de: %.2f R$.", -debito);
	else
		printf("\nImposto pago corretamente!");
		
	return 0;
}
