/*
Artur Rodrigues Santos
Lista I - Questão 08

Escreva um programa que leia um número inteiro positivo e retorne o valor da soma de todos os números inteiros
de zero até o número fornecido. A soma dos números inteiros de 1 até n se calcula como? Imprima um resultado na tela.

Como fazer para lidar com o fato de que o usuário pode fornecer um número negativo? (use apenas o que vimos em sala de aula até agora);
*/

#include <stdio.h>

int main() {

    int valor;
    int valor_soma;

	printf("Digite um valor positivo: ");
	scanf("%d",&valor);

	if (valor < 0) {
		printf("Valor Inválido fornecido");
		return 1;
	}

    valor_soma = valor * (valor + 1) / 2;

    printf("A soma dos números inteiros de 0 até %d é: %d\n", valor, valor_soma);

    return 0;
}
