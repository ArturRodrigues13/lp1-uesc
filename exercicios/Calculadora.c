#include <stdio.h>

int main(void) {

	//Primeiro valor;
	float n1 = 0;

	//Segundo valor;
	float n2 = 0;

	//Tipo de operação.
	int operacao = 0;

	//Resultado da operação;
	float resultado = 0;

	printf("Escolha uma operação:\n\n");
	printf("1: Adição \n2: Subtração \n3: Multiplicação \n4: Divisão\n\n");

	scanf("%d", (&operacao));

	if (operacao < 1 || operacao > 4) {
		printf("\n\nOperação inválida.\nTente novamente.");
		return 1;
	}

	printf("\n\nValor 1: ");
	scanf("%g", (&n1));


	printf("\n\nValor 2: ");
	scanf("%g", (&n2));

	if (operacao == 1) {
		printf("\n\nOperacão: Adição");
		resultado = n1 + n2;
	}

	else if (operacao == 2) {
		printf("\n\nOperacão: Subtração");
		resultado = n1 - n2;
	}

	else if (operacao == 3) {
		printf("\n\nOperacão: Multiplicação");
		resultado = n1 * n2;
	}

	else {
		if(n2 == 0) {
			printf("Não é possível dividir por 0, cálculo inválido");
			return 1;
		}
		printf("\n\nOperacão: Divisão");
		resultado = n1 / n2;
	}

	printf("\n\nResultado: %g", resultado);

	return 0;
}
