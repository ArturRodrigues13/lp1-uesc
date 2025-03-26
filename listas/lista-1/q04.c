/*
Artur Rodrigues Santos
Lista I - Questão 04

Escreva um programa, usando quando necessário o operador (?), que:

-> Declare uma variável de tipo int, vamos chamar de cha mas você pode escolher outro identificador se achar
mais apropriado;

-> Peça ao usuário para digitar um número inteiro positivo, obtenha-o da entrada padrão, usando scanf, e atribua
os valores digitados à variável cha; (se o valor fornecido for negativo, converter no correspondente valor positivo);

-> Identifique se o valor fornecido pelo usuário faz parte dos valores utilizados para a representação de
caracteres imprimíveis da tabela ASCII e imprima na tela, utilizando printf, o caractere em formato numérico
decimal, octal, hexadecimal e como caractere;

-> Se o valor estiver no intervalo dos caracteres não imprimíveis, menores que 32, converter no caractere 32
e imprima na tela, utilizando printf, o caractere em formato numérico decimal, octal, hexadecimal e como caractere;

-> Se o valor fornecido for maior que o valor máximo do intervalo, 127, utilizar o operador % para converter
num valor do intervalo dos caracteres e aplique c ou d.
*/

#include <stdio.h>

int main(void) {

	int cha = 0;

	printf("Digite um número inteiro positivo: ");
	scanf("%d",&cha);

	if(cha < 0)
		cha = cha * -1;

	if(cha >= 33 && cha <= 126)
		printf("\n\nDecimal: %d\n\nOctal: %o\n\nHexadecimal: %x\n\nCaractere: %c",cha,cha,cha,cha);


	if(cha <= 32) {
		cha = 32;
		printf("\n\nDecimal: %d\n\nOctal: %o\n\nHexadecimal: %x\n\nCaractere: %c ( Espaço )",cha,cha,cha,cha);
	}

	if(cha >= 127) {
		cha = cha % 127;
		printf("\n\nDecimal: %d\n\nOctal: %o\n\nHexadecimal: %x\n\nCaractere: %c ",cha,cha,cha,cha);
	}

	return 0;
}
