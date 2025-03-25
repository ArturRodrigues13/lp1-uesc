#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


int main(void) {

  	srand(time(NULL));

  	float x,y,d,api;
  	int n,i,cp = 0;

  	printf("Digite a quantidade de pontos que você deseja marcar: ");
  	scanf("%d",&n);

  	for(i = 0;i < n;i++) {
		x = (float) rand() / RAND_MAX;
		y = (float) rand() / RAND_MAX;

		d = x*x + y*y;

		if(d <= 1) {
			cp++;
		}
  	}

  	api = 4.0 * cp / n;

	printf("Nossa aproximação de PI é: %f\n",api);
	printf("Nossa taxa de erro é: %f\n",M_PI - api);

  	return 0;
}
