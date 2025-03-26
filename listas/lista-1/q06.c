/*
Artur Rodrigues Santos
Lista I - Questão 06

Escreva um programa que peça ao usuário para fornecer um número inteiro longo sem sinal, obtenha-o da entrada
padrão, usando scanf, e determine se o valor fornecido pode ser representado, sem perda de informação como um int.

Imprima na tela o valor fornecido, seguido das palavras “e maior que um int” ou “este valor pertence ao intervalo
dos int”. Use apenas o operador condicional (?).
*/

#include <stdio.h>

int main(void) {

	long unsigned int valor;

	scanf("%lu",&valor);

	(valor > 0 && valor <= 2147483647) ? printf("\nEsse valor, %lu, pertence ao intervalo dos int",valor) : printf("\nEsse valor, %lu, é maior do que o intervalo dos int",valor);

	return 0;
}
