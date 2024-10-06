#include <stdio.h>
#include <stdlib.h>

float calcularVelocidadeMedia(float* espacoInicial, float* espacoFinal, float tempo) {
    return (*espacoFinal - *espacoInicial) / tempo;
}

int main() {
    float* espacoInicial = (float*)malloc(sizeof(float)); 
    float* espacoFinal = (float*)malloc(sizeof(float));
    float tempo;

    if (espacoInicial == NULL || espacoFinal == NULL) {
        printf("Erro ao alocar memória.");
        return 1;
    }

    printf("Digite o valor do espaço inicial: ");
    scanf("%f", espacoInicial);

    printf("Digite o valor do espaço final: ");
    scanf("%f", espacoFinal);

    printf("Digite o valor do tempo: ");
    scanf("%f", &tempo);

    float velocidadeMedia = calcularVelocidadeMedia(espacoInicial, espacoFinal, tempo);
    printf("A velocidade média é: %.2f\n", velocidadeMedia);

    free(espacoInicial);
    free(espacoFinal);

    return 0;
}
