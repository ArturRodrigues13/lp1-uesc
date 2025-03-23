/*
Artur Rodrigues Santos

Lista II - Questão 06

Crie um programa qual entre com argumentos e desenvolva funções que:

a) Retorne o número sorteado de um dado;

b) Verifique o número de sorteios necessários para que sejam sorteados todos os números,
por pelo menos 1 vez;

c) Em uma quantidade grande de repetições (1 milhão ou mais, informada via argumento),
quantas vezes cada valor foi sorteado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rolar_dado(int lados);

int sorteios_para_todos(int lados);

void contagem_frequencias(int lados, long long repeticoes);

int main(int argc, char *argv[]) {

    int lados = atoi(argv[1]);
    long long repeticoes = atoll(argv[2]);

    if (lados < 2 || repeticoes < 1 || lados > 100) {
        printf("Valores inválidos. O dado deve ter entre 2 e 100 lados e as repetições devem ser positivas.\n");
        return 1;
    }

    srand(time(NULL));

    printf("Número sorteado: %d\n", rolar_dado(lados));
    printf("Número de sorteios para obter todos os valores ao menos uma vez: %d\n", sorteios_para_todos(lados));
    printf("Frequência dos números em %lld sorteios:\n", repeticoes);
    contagem_frequencias(lados, repeticoes);

    return 0;
}

int rolar_dado(int lados) {
    return (rand() % lados) + 1;
}

int sorteios_para_todos(int lados) {
    int sorteados[100] = {0};
    int contador = 0, diferentes = 0;
    while (diferentes < lados) {
        int resultado = rolar_dado(lados);
        contador++;
        if (!sorteados[resultado - 1]) {
            sorteados[resultado - 1] = 1;
            diferentes++;
        }
    }
    return contador;
}

void contagem_frequencias(int lados, long long repeticoes) {
    int frequencia[100] = {0};
    for (long long i = 0; i < repeticoes; i++) {
        frequencia[rolar_dado(lados) - 1]++;
    }
    for (int i = 0; i < lados; i++) {
        printf("Número %d: %d vezes\n", i + 1, frequencia[i]);
    }
}
