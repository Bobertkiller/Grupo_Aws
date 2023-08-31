#include <stdio.h>


void transposta(int linha, int coluna, int m[linha][coluna]) {

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if(m[i][j]<0){
                m[i][j] = -m[i][j];
            }
        }
    }
}

int main() {

  int m[3][3] = { {1, -2, 3}, {4, 5, -6}, {7, 8, 9} };
  
  int linha = 3;
  int coluna = 3;

  printf("Matriz original:\n");
  for(int i = 0; i < linha; i++) {
    for(int j = 0; j < coluna; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }

  transposta(linha, coluna, m);

  printf("Matriz modificada:\n");
  for(int i = 0; i < linha; i++) {
    for(int j = 0; j < coluna; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }

  return 0;
}