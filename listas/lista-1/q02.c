/*
Artur Rodrigues Santos
Lista I - Questão 02

Escreva um programa que:

-> Declare três variáveis de tipo caractere, vamos chamar de ch1, ch2 e ch3 mas você pode escolher outro
identificador se achar mais apropriado;

-> O usuário deve digitar um caractere, obtenha o mesmo da entrada padrão, usando scanf, e atribua o valor
digitado à variável ch1;

-> Verifique, utilizando o operador condicional (?) se se trata de:

a) uma letra maiúscula;
b) uma letra minúscula;
c) um dígito;
d) outro tipo de caractere;

-> Atribua à variável ch2 o caractere 81, identifique e imprima na tela, utilizando printf, o caractere
em formato numérico decimal, octal, hexadecimal e como caractere;

-> Dado que o caractere ch2 é uma letra maiúscula, atribua à variável ch3 o caractere que corresponde à
mesma letra minúscula (não pode procurar na tabela ASCII) e imprima ch3 na tela, utilizando printf, em
formato numérico decimal, octal, hexadecimal e como caractere.
*/

#include <stdio.h>

int main() {

	char ch1,ch2,ch3;
	int resp = 0;

	ch2 = 81;
	ch3 = 113;

	scanf("%c",&ch1);

	resp = (ch1 >= 97 && ch1 <= 122) ? 1 : resp;
 	resp = (ch1 >= 65 && ch1 <= 90) ? 2 : resp;
 	resp = (ch1 >= 48 && ch1 <= 57) ? 3 : resp;
 	if (resp == 0)
   		resp = 4;

	if(resp == 1) {
		printf("Você escreveu a letra minuscula %c, localizado entre a e z",ch1);
	}
	else if(resp == 2) {
		printf("Você escreveu a letra maiuscula %c, localizado entre A e Z",ch1);
	}
	else if(resp == 3) {
		printf("Você escreveu o dígito %c, localizado entre 0 e 9",ch1);
	}
	else if(resp == 4) {
		printf("Você escreveu o símbolo %c",ch1);
	}

	printf("\n\nch2:\n\nInteiro decimal: %u\nOctal: %o\nHexadecimal: %x\nCaractere: %c",ch2,ch2,ch2,ch2);

 	printf("\n\nch3:\n\nInteiro decimal: %u\nOctal: %o\nHexadecimal: %x\nCaractere: %c",ch3,ch3,ch3,ch3);

	return 0;
}
