/*
Artur Rodrigues Santos
Lista I - Questão 07

Escreva um programa que leia um número inteiro e, utilizando o operador %, converta ele num valor entre 1 e 6.
Imprima o resultado na tela;
*/

#include <stdio.h>

int main() {

    int valor;

    scanf("%d", &valor);

    int valor_2 = valor % 6;

    if (valor_2 == 0)
		valor_2 = 6;

    printf("O número %d convertido para um valor entre 1 e 6 é: %d", valor, valor_2);

    return 0;
}
