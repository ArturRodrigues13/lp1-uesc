/*
<Artur Rodrigues Santos>

Lista II - Questão 01

Crie um programa qual entre com um argumento e desenvolva funções que:

a) Verifique se é um valor numérico ou alfanumérico, e ou nulo;

b) Mostrar na tela os valores sequencialmente, até o valor informado;

c) Mostrar na tela os valores sequencialmente, até o valor informado na ordem inversa;

d) Mostrar na tela os valores até o valor informado, alternando entre primeiro e último;

e) Calcular todos os números primos, até o valor informado. Número primo é aquele que é divisível
somente por 1 e por ele mesmo;

f) Calcular todos os números perfeitos, até o valor informado. Número perfeito é aquele que é a
soma de seus fatores. Por exemplo, 6 é divisível por 1, 2 e 3 ao passo que 6 = 1 + 2 + 3;
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void qual(char tecla);
void sequencia(int num);
void desequencia(int num);
void ciaquense(int num);
void primos(int num);
void perfeitos(int num);

int main(int argc, char *argv[]) {

	int qualfuncao = atoi(argv[1]);
	char qualfucn = *argv[2];
	int sequenciafunc = atoi(argv[2]);
	int primosfunc = atoi(argv[2]);
	int perfeitosfunc = atoi(argv[2]);

	switch(qualfuncao) {

		case 1:
			qual(qualfuncao);
			break;

		case 2:
			sequencia(sequenciafunc);
			break;

		case 3:
			desequencia(sequenciafunc);
			break;

		case 4:
			ciaquense(sequenciafunc);
			break;

		case 5:
			primos(primosfunc);
			break;

		case 6:
			perfeitos(perfeitosfunc);
			break;
		}
	return 0;

}

void qual(char tecla) {

	if ( isalnum(tecla) ) {

		printf("\nVocê digitou um alfanumérico!!!");

		if ( isdigit(tecla) )
		printf("\n\nVocê digitou um número!\n\n");

	else if ( isalpha(tecla) )
		printf("\n\nVocê digitou um caractere!\n\n");

	}

	else if ( isblank(tecla) )
		printf("\nVocê digitou um espaço em branco!\n\n");

	else
		printf("\nVocê não digitou um número ou um caractere!\n\n");

}

void sequencia(int num) {

	printf("\nOs números 0 até %d são:\n\n", num);

	for(int i = 0; i <= num; i++)
	{
		printf("%d   ",i);
	}
}

void desequencia(int num) {

	printf("\nOs números de %d até 0 são:\n\n", num);

	for(int i = num; i >= 0; i--)
	{
		printf("%d   ",i);
	}
}

void ciaquense(int num) {

	printf("\nOs números de 0 até %d, alternando entre o primeiro e o último, são:\n\n", num);

	int final = num;
	int metade = num / 2;
	for(int i = 0; i <= metade; i++)
	{
		printf("%d   ",i);
		for(int j = 0; j < 1; j++)
		{
			if(final != metade)
			{
				printf("%d   ",final);
				final --;
			}
		}
	}
}

void primos(int num) {
	printf("\nOs números primos de 1 até %d são:\n\n", num);

	for (int i = 2; i <= num; i++) {
		int primo = 1;

		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				primo = 0;
				break;
			}
		}

		if (primo) {
			printf("%d ", i);
		}
	}
	printf("\n");
}


void perfeitos(int num) {

	printf("\nOs números perfeitos de 1 até %d são:\n\n", num);

	for ( int i = 1; i < num; i++ ) {

		int soma = 0;

		for ( int j = 1; j < i; j++ )
			if ( i % j == 0 )
				soma += j;

			if ( i == soma )
				printf("%i   ", soma);
	}
}
