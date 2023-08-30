#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char nome[50];
  int idade;
  float peso;
  float altura;  
}sistema;

int main(void){

  int regist;
  sistema alunos[3];

  for (int i = 0; i < 3; i++){
    
    printf("Insira o nome do aluno %d: ",i+1);
    scanf("%s", alunos[i].nome);
    
    printf("Agora insira a idade: ");
    scanf("%d", &alunos[i].idade);

    printf("Agora insira o peso: ");
    scanf("%f", &alunos[i].peso);

    printf("Agora insira a atura: ");
    scanf("%f", &alunos[i].altura);

  }
    
  printf("Dados Digitados\n");

  for (int i = 0; i < 3; i++){
    printf("---------Dado do aluno %d--------", i+1);
    printf("Nome : %s\n", alunos[i].nome);
    printf("Idade : %d\n", alunos[i].idade);
    printf("Peso : %.2f\n", alunos[i].peso);
    printf("Altura : %.2f\n", alunos[i].altura);

  }

  return 0;

}
