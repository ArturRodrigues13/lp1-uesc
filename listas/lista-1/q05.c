/*
Artur Rodrigues Santos
Lista I - Questão 05

Escreva um programa que peça ao usuário para fornecer um número inteiro, obtenha-o da entrada padrão, usando
scanf, e determine se o valor fornecido pode ser representado, sem perda de informação como um short int.

Imprima na tela o valor fornecido, seguido das palavras “é maior que um short int” ou “este valor pertence ao
intervalo dos short int”. Use apenas o operador condicional (?).
*/

#include <stdio.h>

int main(void) {

	int valor = 0;

	scanf("%d",&valor);


	(valor >= -32768 && valor <= 32767) ? printf("\nEsse valor, %d, pertence ao intervalo dos short int",valor) : printf("\nEsse valor, %d, não pertence ao intervalo dos short int",valor);

	return 0;
}
