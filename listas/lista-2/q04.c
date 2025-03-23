/*
Artur Rodrigues Santos

Lista II - Questão 04

Crie um programa qual entre com argumentos e desenvolva funções que:

a) Calcule o índice de massa corporal (IMC);

b) Deve apresentar resultado determinado pela faixa
*/

#include <stdio.h>
#include <stdlib.h>

float calcula(float peso,float altura);

int main(int argc, char *argv[]) {

	float peso = atof(argv[1]);
	float altura = atof(argv[2]);
	float imc = calcula(peso,altura);

	printf("Peso: %.2f",peso);
	printf("\nAltura: %.2f",altura);

	if (imc < 18.5) {

		printf("\nSeu IMC é de %.2f e sua classificação é: Extrema Magreza\n",imc);

	} else if ( imc >= 18.5 && imc <= 24.9) {

		printf("\n\nSeu IMC é de %.2f e sua classificação é: Normal\n",imc);

	} else if ( imc >= 25 && imc <= 29.9) {

		printf("\n\nSeu IMC é de %.2f e sua classificação é: Sobrepeso\n",imc);

	} else if ( imc >= 30 && imc <= 39.9) {

		printf("\n\nSeu IMC é de %.2f e sua classificação é: Obesidade\n",imc);

	} else {

		printf("\n\nSeu IMC é de %.2f e sua classificação é: Obesidade Grave\n",imc);

	}
}

float calcula(float peso, float altura) {

	float imc = peso / (altura * altura);

	return imc;

}
