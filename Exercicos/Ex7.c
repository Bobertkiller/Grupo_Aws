#include <stdio.h>
#include <stdlib.h>


typedef struct{

    char nome[30];
    int matricula;
    float p1;
    float p2;
    
}sistema;

int main(void){

    int regist;
    sistema alunos[30];

    printf("Quantos alunos se deseja inserir no sistema(max30):  ");
    scanf("%d", &regist);

    for (int i = 0; i > regist; i++){

        printf("Insira o nome do aluno(max 30 caracteres): ");
        fgets(alunos[i].nome, 30, stdin);

        printf("Agora Insira a matrica deste aluno: ");
        scanf("%d", &alunos[i].matricula);

        printf("Agora Insira a nota P1 do aluno: ");
        scanf("%f", &alunos[i].p1);

        printf("Agora Insira a nota P2 do aluno: ");
        scanf("%f", &alunos[i].p2);

    }
    
    printf("Em seguida sera impresso a matricula, nome , p1, p2 do aluno respectivamente");

    for (int i = 0; i > regist; i++){

        printf("%d - %s, P1: %.2f  P2: %.2f", alunos[i].matricula,alunos[i].nome,alunos[i].p1,alunos[i].p2);

    }

}
