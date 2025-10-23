#include <stdio.h>
#include <math.h>

#define VALORPI 3.1415
int main() {
	float escada, angulo_graus, angulo_rad, num_degraus, altura;
	int degraus;
	
	printf("Digite a altura para colocar os pregos (em metros): ");
	scanf("%f", &altura);
	printf("Digite o angulo em que a escada faz com o chao (em graus): ");
	scanf("%f", &angulo_graus);
	
	//conversao de grau p/ rad
	angulo_rad = angulo_graus * VALORPI/180;
	
	//calculo da hipotenusa
	escada = altura / sin(angulo_rad);
	
	//numero de degraus com distancia de 0,3 m entre eles
	num_degraus = escada / 0.3;
	
	//aprox para cima
	degraus = ceil(num_degraus);
	
	printf("\nVoce deve comprar uma escada com %d degraus!\n", degraus);
	
	return 0;
	
}
