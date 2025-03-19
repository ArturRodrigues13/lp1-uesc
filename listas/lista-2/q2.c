/*
temp_inicial Rodrigues Santos
Lista II - Questão 02

Crie um programa qual entre com argumentos e desenvolva funções que:

-> Transforme Celsius e Farenheit a depender da escolha;
*/

#include <stdio.h>
#include <string.h>

double temp(double calor,int desse,int praesse);

int main(void)
{
	int temp_inicial = 0;
	char antes[10];
	int temp_final = 0;
	char depois[10];
	double calor1;
	double calor2;

	printf("Olá, por favor, diga o tipo da temperatura inicial que você quer converter\n");
	printf("1 = Celsius\n2 = Farenheit\n3 = Kelvin\n");

	while(temp_inicial != 1 && temp_inicial != 2 && temp_inicial != 3)
	{
		printf("\nPor favor, digite um dos números previstos na tabela acima: ");
		scanf("%i",&temp_inicial);
	}

	switch (temp_inicial)
	{
		case 1:
		strcpy(antes, "Celsius");
		break;
		case 2:
		strcpy(antes, "Farenheit");
		break;
		case 3:
		strcpy(antes, "Kelvin");
		break;
	}

	printf("\nAgora, me diga o seu valor: ");
	scanf("%lf",&calor1);

	printf("\nAgora, me diga para qual tipo você quer converter a temperatura atual\n");
	printf("1 = Celsius\n2 = Farenheit\n3 = Kelvin\n");

	while(temp_final != 1 && temp_final != 2 && temp_final != 3)
	{
		printf("\nPor favor, digite um dos números previstos na tabela acima: ");
		scanf("%i",&temp_final);
	}

	if(temp_inicial == temp_final)
	{
		printf("\n\nVocê escolheu o mesmo tipo de temperatura para fazer a conversão, tente novamente");
		return 0;
	}

	switch (temp_final)
	{
		case 1:
		strcpy(depois, "Celsius");
		break;
		case 2:
		strcpy(depois, "Farenheit");
		break;
		case 3:
		strcpy(depois, "Kelvin");
		break;
	}

	calor2 = temp(calor1,temp_inicial,temp_final);

	printf("A temperatura %.2lf foi convertida de %s para %s, resultando em %.2lf",calor1,antes,depois,calor2);

	return 0;
}

double temp(double calor,int desse,int praesse)
{
	if(desse == 1 && praesse == 3)
	{
		calor += 273;
	}
	else if(desse == 3 && praesse == 1)
	{
		calor -= 273;
	}
		else if(desse == 1 && praesse == 2)
	{
		calor = 1.8 * calor + 32;
	}
		else if(desse == 2 && praesse == 1)
	{
		calor = (calor - 32) / 1.8;
	}
		else if(desse == 2 && praesse == 3)
	{
		calor = (calor + 459.67) / 1.8;
	}
	else
	{
		calor = calor * 1.8 - 459.67;
	}
	return calor;
}
