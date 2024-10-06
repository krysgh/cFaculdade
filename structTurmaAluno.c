//Inserção de bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Limite máximo de 100 alunos declarado
#define LIMITE_MAX_ALUNO 100

//Limite máximo de 2 turmas declarado
#define LIMITE_MAX_TURMA 2



//Criação de Struct Aluno
typedef struct{
    int matricula;
    char nome[100];
    char email[100];
    float disciplinas[9];
}Aluno;

//Criação de Struct Turma
typedef struct{
    Aluno alunos[50];
    int id;
}Turma;


//Função para Inserir Aluno (OPCAO 1)
void inserirAluno( Aluno alunos[], int *numAluno,Turma turmas[],int *numTurma,int *numAluno2B,int *numAluno3B){
    int idTurma;
    printf("-----------------------------------INSERIR ALUNO------------------------------------\n");
    if(*numAluno==(LIMITE_MAX_ALUNO)){
        printf("Limite de Alunos Alcançado.\n\n");
    }
    else if(!(*numTurma)){
        printf("Insira uma Turma para liberar essa opção!\n\n");
    }
    else{
        printf("Digite em que Turma o Aluno pertencerá(2 ou 3):");
        scanf("%d",&idTurma);
        while(getchar() != '\n');
    alunos[*numAluno].matricula=(*numAluno);
    printf("Digite o nome do Aluno:");
    fgets(alunos[*numAluno].nome,sizeof(alunos[*numAluno].nome),stdin);
    alunos[*numAluno].nome[strcspn(alunos[*numAluno].nome, "\n")] = '\0';
    printf("Digite o email do Aluno:");
   fgets(alunos[*numAluno].email,sizeof(alunos[*numAluno].email),stdin);
    alunos[*numAluno].email[strcspn(alunos[*numAluno].email, "\n")] = '\0';
    
        printf("Digite a nota da disciplinas abaixo:\n"); 
        printf("ÁLGEBRA LINEAR:");
        scanf("%f", &alunos[*numAluno].disciplinas[0]);
        printf("ALGORÍTMOS E PROGRAMAÇÃO DE COMPUTADORES II:");
        scanf("%f", &alunos[*numAluno].disciplinas[1]);
        printf("ANÁLISE E PROJETO ESTRUTURADO II:");
        scanf("%f", &alunos[*numAluno].disciplinas[2]);
        printf("ARQUITETURA E ORGANIZAÇÃO DE COMPUTADORES II:");
        scanf("%f", &alunos[*numAluno].disciplinas[3]);
        printf("ATIVIDADES DE EXTENSÃO II:");
        scanf("%f", &alunos[*numAluno].disciplinas[4]);
        printf("CÁLCULO I:");
        scanf("%f", &alunos[*numAluno].disciplinas[5]);
        printf("LABORATÓRIO DE PROGRAMAÇÃO II:");
        scanf("%f", &alunos[*numAluno].disciplinas[6]);
        printf("ORGANIZAÇÃO,SISTEMAS E MÉTODOS:");
        scanf("%f", &alunos[*numAluno].disciplinas[7]); 
        printf("PESQUISA OPERACIONAL:");
        scanf("%f", &alunos[*numAluno].disciplinas[8]);
        
        if(idTurma==2){
            turmas[0].alunos[*numAluno2B]=alunos[*numAluno];
            numAluno2B++;
        }
        if(idTurma==3){
            turmas[1].alunos[*numAluno3B]=alunos[*numAluno];
            numAluno3B++;
        }
        
    (*numAluno)++;
    printf("\n");
}
}
//Função para Inserir Turma (OPCAO 2)
void inserirTurma( Turma turmas[], int *numTurma){
    printf("----------------------------------INSERIR TURMA----------------------------------\n");
    if(*numTurma==(LIMITE_MAX_TURMA)){
        printf("Limite de Turmas Alcançado.\n\n");
    }
    else if(*numTurma==0){
        turmas[0].id=2;
        printf("Turma 2B criada.\n");
    }    
    else if(*numTurma==1){
        turmas[1].id==3;
        printf("Turma 3B criada.\n");
    }    
    (*numTurma)++;
    printf("\n");
}

//Função para Mostrar as Turmas(OPÇÃO 3)
void mostrarTurma(Turma turmas[],int *numTurma, int *numAluno){
	int i,j;
    if(!(*numTurma)){
        printf("Insira uma Turma para liberar essa função.\n\n");
    }
    else{
        for(i=0;i<*numTurma;i++){
            printf("------------------------------------TURMA %dB------------------------------------\n",turmas[i].id);
        for(j=0;j<*numAluno;j++){
            printf("Matrícula do Aluno:%d\n", turmas[i].alunos[j].matricula);
            printf("Nome do Aluno:%s\n",turmas[i].alunos[j].nome);
            printf("Email do Aluno:%s\n",turmas[i].alunos[j].email);
            
            
            
        
            
}
            
        }
}
}
//Função Principal
int main()
{
    int numAluno2B=0;
    int numAluno3B=0;
    int opcao;
    Turma turmas[LIMITE_MAX_TURMA];
    Aluno alunos[LIMITE_MAX_ALUNO];
    int numAluno=0;
    int numTurma=0;
    do{
        printf("-----------------------------------MENU DE OPÇÕES-----------------------------------\n");
        printf("1-Inserir Aluno\n");
        printf("2-Inserir Turma\n");
        printf("3-Mostrar Turmas\n");
        printf("4-Encerrar Programa\n");
        printf("Selecione a opção desejada:");
        scanf(" %d", &opcao);
        while(getchar() != '\n');
        printf("\n");
        switch(opcao){
            
            case 1:
                inserirAluno(alunos,&numAluno,turmas, &numTurma,&numAluno2B,&numAluno3B);
                break;
            case 2:
                inserirTurma(turmas,&numTurma);
                break;
            case 3:
                mostrarTurma(turmas,&numTurma,&numAluno);
                break;
            case 4:
                printf("Encerrando Programa...");
                break;
            default:
                printf("Opção Inválida\n\n");
                break;
        }
    }while(opcao!=4);
    return 0;
}
