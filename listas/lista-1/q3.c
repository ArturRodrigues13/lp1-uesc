#include <stdio.h>

/*
Artur Rodrigues Santos
Lista I - Questão 03

Escreva um programa, usando quando necessário o operador (?), que:

-> Declare três variáveis de tipo int, vamos chamar de a, b e c mas você pode escolher outro identificador se achar mais apropriado;

-> Peça ao usuário para digitar dois números inteiros, obtenha-os da entrada padrão, usando scanf, e atribua os valores digitados às variáveis a e b respectivamente;

-> Atribua à variável c a somas das variáveis a e b, imprima o resultado na tela em formato hexadecimal;

-> Atribua à variável c o produto das variáveis a e b, imprima o resultado na tela em formato octal;

-> Atribua à variável c o módulo (valor absoluto) da diferença entre as variáveis a e b, imprima o resultado na tela; (valor absoluto: se c < 0 imprimir -c, caso contrário imprima c);

-> Atribua à variável c o quociente entre variáveis a e b, imprima o resultado na tela; (se b = 0 a divisão não é possível e um aviso deve ser apresentado ao usuário);

-> Se a divisão anterior for possível, determinar se a é divisível de forma exata por b, mostrar o resultado na tela.
*/

int main()
{
	int a,b,c;

	printf("Me dê dois valores inteiros por favor: ");

	scanf("%d",&a);
	scanf("%d",&b);

	c = a + b;
	printf("A soma dos números que você digitou é %d, ou em hexadecimal %x\n",c,c);

	c = a * b;
	printf("O produto dos números que você digitou é %d, ou em octal %o\n",c,c);

	c = a - b;
	( c < 0) ? c = (-c) : c;
	printf("O valor absoluto da diferença entre os números que você digitou é %d\n",c);

	// Nesse ponto é impossível realizar o que a questão pede pois um operador ternário não pode retornar diretamente um valor para a função, logo se faz necessário o uso de um "if" como corrigido posteriormente pelo professor;

	if (b == 0)
	{
		printf("Não foi possível progredir no código pois o segundo valor digitado foi igual a 0, caso queira prosseguir, coloque um segundo valor diferente de 0\n");

		return 1;
	}

	c = a / b;
	int d = a % b;
	printf("O quociente da divisão entre os números que você digitou é %d\n",c);
	( d == 0) ? printf("A divisão é exata") : printf("A divisão não é exata");

	return 0;
}
