/*
Artur Rodrigues Santos
Lista I - Questão 10

Escreva um programa que leia da entrada padrão o lado de um quadrado e imprima:

-> O tamanho da diagonal do mesmo;

-> O valor do perímetro;

-> Sua área.
*/

#include <stdio.h>
#include <math.h>

int main()
{
	float lado,diagonal,area,perimetro;

	printf("Olá, vamos calcular as propriedades de um quadrado!!! Me dê a medida de um dos lados do quadrado por favor: ");
	scanf("%f",&lado);

	area = lado * lado;
	printf("A área do quadrado é de %g m.\n",area);

	diagonal = lado * sqrtf(2);
	printf("A diagonal do quadrado é de %g m.\n",diagonal);

	perimetro = lado * 4;
	printf("O perímetro do quadrado é de %g m².",perimetro);

	return 0;
}
