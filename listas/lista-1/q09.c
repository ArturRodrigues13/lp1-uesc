/*
Artur Rodrigues Santos
Lista I - Questão 09

Escreva um programa que:

-> Declare três variáveis de tipo float, vamos chamar de x, y e z mas você pode escolher outro identificador
se achar mais apropriado;

-> Peça ao usuário para digitar dois números de ponto flutuante, obtenha-os da entrada padrão, usando scanf, e
atribua os valores digitados às variáveis x e y respectivamente;

-> Considerando que x e y são coordenadas num plano cartesiano, identifique em que lado da curva se encontra
(esquerda, direita ou na curva). Imprima o resultado na tela;

-> Atribua à variável z o valor da distância euclidiana do ponto (x, y) ao centro de coordenadas (distância
euclidiana se calcula como? Pode utilizar a função sqrt() fornecida no arquivo de cabeçalho math.h);

-> Atribua à variável z o produto entre as variáveis x e y, imprima o resultado na tela em notação científica.
*/

#include <stdio.h>
#include <math.h>

int main(void) {

	float x;
	float y;
	float z;

	printf("Digite dois números reais: ");
	scanf("%f",&x);
	scanf("%f",&y);

	if (x > 0 && y > 0) {
		printf("O ponto (%.2f, %.2f) está no primeiro quadrante (direita da curva).\n", x, y);
	}
	else if (x < 0 && y > 0) {
		printf("O ponto (%.2f, %.2f) está no segundo quadrante (esquerda da curva).\n", x, y);
	}
	else if (x < 0 && y < 0) {
		printf("O ponto (%.2f, %.2f) está no terceiro quadrante (esquerda da curva).\n", x, y);
	}
	else if (x > 0 && y < 0) {
		printf("O ponto (%.2f, %.2f) está no quarto quadrante (direita da curva).\n", x, y);
	}
	else if (x == 0 && y != 0) {
		printf("O ponto (%.2f, %.2f) está no eixo y (na curva).\n", x, y);
	}
	else if (x != 0 && y == 0) {
		printf("O ponto (%.2f, %.2f) está no eixo x (na curva).\n", x, y);
	}
	else {
		printf("O ponto (%.2f, %.2f) está na origem (na curva).\n", x, y);
	}

	z = sqrt(x * x + y * y);
	printf("Distância euclidiana do ponto (x, y) ao centro de coordenadas: %.2f",z);

	z = x * y;
	printf("\nO produto de %.2f e %.2f é: %e\n", x, y, z);

	return 0;
}
