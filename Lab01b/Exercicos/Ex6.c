#include <stdio.h>
#include <stdlib.h>

int main(){

  int a, b;

  printf("Insira o número de linhas: ");
  scanf("%d", &a);

  printf("Insira o número de colunas: ");
  scanf("%d", &b);

  int m[a][b];

  for(int i = 0; i < a; i++){
    for(int j = 0; j < b; j++){
      m[i][j] = 0; 
    }
  }

  for(int i = 0; i < a; i++){
    for(int j = 0; j < b; j++){
      printf("Insira o elemento m[%d][%d]: ", i, j);
      scanf("%d", &m[i][j]);
    }
  }

  void transposta(int a, int b, int (*m)[b]){

    int temp;

    for(int i = 0; i < a; i++){
      for(int j = i + 1; j < b; j++){
        temp = m[i][j];
        m[i][j] = m[j][i];
        m[j][i] = temp;
      }
    }
  }

  printf("Matriz Original:\n");
  for(int i = 0; i < a; i++){
    for(int j = 0; j < b; j++){
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }

  transposta(a, b, m);

  printf("Matriz transposta:\n");
  for(int i = 0; i < b; i++){
    for(int j = 0; j < a; j++){
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}