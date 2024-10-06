//Inserção de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Função para calcular a velociade média
float calcularVelocidadeMedia(float* espacoInicial, float* espacoFinal, float tempo) {
    return (*espacoFinal - *espacoInicial) / tempo;
}

//Função Principal
int main() {
    //Declaração de variáveis alocando memória dinâmica
    float* espacoInicial = (float*)malloc(sizeof(float)); 
    float* espacoFinal = (float*)malloc(sizeof(float));
    float tempo;

    //Verficando se há erro na alocação de memória dinâmica
    if (espacoInicial == NULL || espacoFinal == NULL) {
        printf("Erro ao alocar memória.");
        return 1;
    }

    //Entrada do s0
    printf("Digite o valor do espaço inicial: ");
    scanf("%f", espacoInicial);
    
    //Entrada do sf
    printf("Digite o valor do espaço final: ");
    scanf("%f", espacoFinal);

    //Entrada do t
    printf("Digite o valor do tempo: ");
    scanf("%f", &tempo);

    //Armazena o resultado da fução na variável velocidadeMedia e exibe seu resultado 
    float velocidadeMedia = calcularVelocidadeMedia(espacoInicial, espacoFinal, tempo);
    printf("A velocidade média é: %.2f\n", velocidadeMedia);

    //Libera as variáveis 
    free(espacoInicial);
    free(espacoFinal);

    return 0;
}
