#include <stdio.h>
#include <math.h>

int main(void) {

	int figgeo = 0;
	float a,b,c,d,e = 0;
	float r1,r2,r3 = 0;

	printf("Olá, bem vindo à Calculadora de Figuras Geométricas, por favor, selecione a figura desejada baseado na seguinte tabela:\n\nReta      = 1\nQuadrado  = 2\nTriângulo = 3\nCírculo   = 4\nRetângulo = 5\nTrapézio  = 6\nLosango   = 7\n\n");

	scanf("%d",&figgeo);

  	switch(figgeo) {

	case  1:
		printf("\nPor favor, me diga a posição do ponto A e do ponto B para o cálculo ser feito.\n");
		scanf("%f",&a);
		scanf("%f",&b);
		if (b - a < 0)
			r1 = (b - a) * -1;
		else
    		r1 = b - a;
  		printf("Parabéns, sua reta tem %.2f de comprimento",r1);
 	break;

  	case 2:
		printf("\nPor favor, me diga a medida de um dos lados do Quadrado para o cálculo ser feito.\n");
		scanf("%f",&a);
		r1 = a * a;
		r2 = a * 4;
		r3 = a * sqrt(2);
 	 	printf("\nParabéns, a área do seu quadrado é %.2f, o seu perímetro é %.2f e a diagonal é %.2f\n",r1,r2,r3);
  	break;

  	case 3:
		printf("\nPor favor, me diga os pontos do triângulo, na ordem decrita, para o cálculo ser feito.\n");
		scanf("%f",&a);
		scanf("%f",&b);
		scanf("%f",&c);
  	break;

  	case 4:
		printf("\nPor favor, me diga o valor do raio de seu círculo, para o cálculo ser feito.\n");
		scanf("%f",&a);
		r1 = 3.14 * (a * a);
		r2 = 2 * 3.14 * a;
  		printf("\nParabéns, a área do seu círculo é %.2f e a sua circunferência é %.2f\n",r1,r2);
  	break;

  	case 5:
		printf("\nPor favor, me diga o valor de um dos lados menor e maior, nesta ordem, para o cálculo ser feito.\n");
		scanf("%f",&a);
		scanf("%f",&b);
		r1 = a * b;
		r2 = 2 * (a + b);
		r3 = sqrt(a * a + b * b);
  		printf("\nParabéns, a área do seu retângulo é %.2f, o seu perímetro é %.2f e a sua diagonal é %.2f\n",r1,r2,r3);
  	break;

    case 6:
    	printf("\nPor favor, me diga o valor da base maior, da base menor, dos lados e da altura, nessa ordem, para o cálculo ser feito.\n");
		scanf("%f",&a);
		scanf("%f",&b);
		scanf("%f",&c);
		scanf("%f",&d);
		scanf("%f",&e);
      	r1 = ((a + b) * e) / 2;
      	r2 = a + b + c + d;
    	printf("\nParabéns, a área do seu trapézio é %.2f e o seu perímetro é %.2f\n",r1,r2);
    break;

    case 7:
    	printf("\nPor favor, me diga o valor da diagonal maior, da diagonal menor e dos lados, nessa ordem, para o cálculo ser feito.\n");
      	scanf("%f",&a);
      	scanf("%f",&b);
      	scanf("%f",&c);
      	r1 = (a * b)/2;
      	r2 = c * 4;
    	printf("\nParabéns, a área do seu losango é %.2f e o seu perímetro é %.2f\n",r1,r2);
    break;

  	}

 	return 0;
}
