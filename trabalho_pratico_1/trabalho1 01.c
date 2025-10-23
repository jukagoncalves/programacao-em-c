#include <stdio.h>
#include <math.h>

#define META_ALVOS 5000
#define PI 3.1415
#define CIRCULOS 6

int main() {
	int circulo;
	float diametro_maior, raio_maior, distancia_raio;
	float area_total_alvo, raio_atual, area_circulo;
	float area_total_papelao;
	
	//entrada
	printf("Digite o diametro do circulo maior(em metros): ");
	scanf("%f", &diametro_maior);
	
	raio_maior = diametro_maior/2.0;
	distancia_raio = raio_maior / CIRCULOS;
	
	//calculo individual de cada circulo
	for(circulo = 1; circulo <=6; circulo ++)
	{
		raio_atual = distancia_raio * 1;
		area_circulo = PI * pow(raio_atual, 2);
		area_total_alvo += area_circulo;
	}
	
	area_total_papelao = area_total_alvo * META_ALVOS;
	printf("\nA area total de papelao nescessario para %d alvos e: %.2f metros quadrados. \n", META_ALVOS, area_total_papelao);
	
	return 0;
	
}
