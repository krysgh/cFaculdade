//Inserção de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaração de Estrutura VOO
typedef struct {
    char origem[30];
    char destino[30];
    char data[11]; //DD/MM/AAAA + \n
    char horario[6]; //HH:MM + \n
    int assentosDisponiveis;
}Voo;

//Declaração de Estrutura PASSAGEIRO
typedef struct {
    char nome[50];
    char numDocumento[20];
    int vooId;
}Passageiro;

//Declaração de Estrutura RESERVAS
typedef struct {
    Voo voos[100];
    Passageiro passageiros[100];
    int numVoos;
    int numPassageiros;
}Reservas;

//Função interna do sistema que armazena dados de voos já definidos na Função Principal
void armazenarVoo(Reservas *sistema, char *origem, char *destino, char *data, char *horario, int assentosDisponiveis) {
    if (sistema->numVoos < 100) {
        Voo *voo = &(sistema->voos[sistema->numVoos++]);
        strcpy(voo->origem, origem);
        strcpy(voo->destino, destino);
        strcpy(voo->data, data);
        strcpy(voo->horario, horario);
        voo->assentosDisponiveis = assentosDisponiveis;
    } else {
        printf("Número máximo de voos atingido.\n");
    }
}
//Função interativa com o usuário, permitindo que o mesmo consulte o número de assentos e o horário do voo escolhido(OPCAO 1)
void consultarVoos(Reservas *sistema, char *origem, char *destino, char *data) {
    printf("Voos disponíveis:\n");
    for (int i = 0; i < sistema->numVoos; i++) {
        Voo *voo = &(sistema->voos[i]);
        if (strcmp(voo->origem, origem) == 0 && strcmp(voo->destino, destino) == 0 && strcmp(voo->data, data) == 0) {
            printf("ID: %d\nHorário: %s\nAssentos Disponíveis: %d\n", i, voo->horario, voo->assentosDisponiveis);
        }
    }
}

//Função interativa com o usuário, permitindo que o mesmo reserve um voo, inserindo seu NOME, DOCUMENTO, e o ID do voo escolhido, que deve ser consultado na opção 1(OPCAO 2)
void reservarVoo(Reservas *sistema, char *nome, char *numDocumento, int vooId) {
    if (vooId >= 0 && vooId < sistema->numVoos) {
        Voo *voo = &(sistema->voos[vooId]);
        if (voo->assentosDisponiveis > 0) {
            Passageiro *passageiro = &(sistema->passageiros[sistema->numPassageiros++]);
            strcpy(passageiro->nome, nome);
            strcpy(passageiro->numDocumento, numDocumento);
            passageiro->vooId = vooId;
            voo->assentosDisponiveis--;
            printf("Reserva efetuada com sucesso.\n");
        } else {
            printf("Não há assentos disponíveis para este voo.\n");
        }
    } else {
        printf("Esse voo não existe..\n");
    }
}

//Função interativa com o usuário que cancela uma reserva de voo do mesmo, requer DOCUMENTO (OPCAO 3)
void cancelarVoo(Reservas *sistema, char *numDocumento) {
    int encontrarReserva = 0;
    for (int i = 0; i < sistema->numPassageiros; i++) {
        if (strcmp(sistema->passageiros[i].numDocumento, numDocumento) == 0) {
            Voo *voo = &(sistema->voos[sistema->passageiros[i].vooId]);
            voo->assentosDisponiveis++;
            sistema->passageiros[i] = sistema->passageiros[--sistema->numPassageiros];
            encontrarReserva = 1;
            printf("Reserva cancelada com sucesso.\n");
            break;
        }
    }
    if (!encontrarReserva) {
        printf("Reserva não encontrada.\n");
    }
}

//Função interativa com o usuário, permitindo que o mesmo consulte seus voos reservados, requer DOCUMENTO (OPCAO 4) 
void consultarVoo(Reservas *sistema, char *numDocumento) {
    printf("Reservas do passageiro %s:\n", numDocumento);
    for (int i = 0; i < sistema->numPassageiros; i++) {
        if (strcmp(sistema->passageiros[i].numDocumento, numDocumento) == 0) {
            Voo *voo = &(sistema->voos[sistema->passageiros[i].vooId]);
            printf("\nVoo ID: %d\nOrigem: %s\nDestino: %s\nData: %s\nHorário: %s\n\n", sistema->passageiros[i].vooId, voo->origem, voo->destino, voo->data, voo->horario);
        }
    }
}

//Função Principal, contém a inicialização de variáveis, alocação de memória dinâmica no processo de 
//armazenar voos definidos pelo sistema, menu interativo que cumpre com as funcionalidades e requisitos
//pedidos, assim como uma tabela informativa dos voos armazenados no sistema para facilitar o uso das funções.
//Ao final, há a liberação de memória alocada dinamicamente das variáveis antes declaradas. 
int main() {
    Reservas sistema = {0}; 
    int opcao;
    char *origem = (char *)malloc(30 * sizeof(char));
    char *destino = (char *)malloc(30 * sizeof(char));
    char *data = (char *)malloc(11 * sizeof(char));

    if (origem == NULL || destino == NULL || data == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    char horario[6];
    char nome[50], numDocumento[20];
    int vooId;

    armazenarVoo(&sistema, "São Paulo", "Moscou", "15/07/2024", "08:00", 10);
    armazenarVoo(&sistema, "Londres", "Tóquio", "14/08/2024", "11:00", 10);
    armazenarVoo(&sistema, "Chicago", "Paris", "13/09/2024", "12:30", 10);

    do {
        printf("\n-------------------------------------");
        printf("\n       Voos Definidos pelo Sistema: |\n|  ORIGEM |    DESTINO   |   DATA   |\n|São Paulo|    Moscou    |15/07/2024|\n|Londres  |     Tóquio   |14/08/2024|\n|Chicago  |     Paris    |13/09/2024|\n");
        printf("\n------------------MENU---------------\n");
        printf("1-Consultar reservas disponíveis\n2-Reservar um voo\n3-Cancelar um voo\n4-Consultar reservas\n5-Encerrar Programa\nEscolha uma opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');
        switch (opcao) {
            case 1:
                printf("\n------------CONSULTAR VOO------------\n");
                printf("Origem: ");
                fgets(origem, 30, stdin);
                origem[strcspn(origem, "\n")] = '\0'; 
                printf("Destino: ");
                fgets(destino, 30, stdin);
                destino[strcspn(destino, "\n")] = '\0'; 
                printf("Data (DD/MM/AAAA): ");
                fgets(data, 11, stdin);
                data[strcspn(data, "\n")] = '\0'; 
                consultarVoos(&sistema, origem, destino, data);
                break;
            case 2:
                printf("\n-------------RESERVAR VOO------------\n");
                printf("Nome: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0'; 
                printf("Número do documento: ");
                scanf("%s", numDocumento);
                printf("ID do voo: ");
                scanf("%d", &vooId);
                while (getchar() != '\n'); 
                reservarVoo(&sistema, nome, numDocumento, vooId);
                break;
            case 3:
                printf("\n------------CANCELAR VOO-------------\n");
                printf("Número do documento: ");
                scanf("%s", numDocumento);
                cancelarVoo(&sistema, numDocumento);
                break;
            case 4:
                printf("\n------------CONSULTAR VOO------------\n");
                printf("Número do documento: ");
                scanf("%s", numDocumento);
                consultarVoo(&sistema, numDocumento);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção Inválida.\n");
        }
    } while (opcao != 5);

    free(origem);
    free(destino);
    free(data);

    return 0;
}