#include <stdio.h>

#define LINHAS 3
#define COLUNAS 4 

void multiplicaLinha(int m[][COLUNAS], int linha, int num, int colunas){
  for(int j = 0; j < colunas; j++){
    m[linha][j] *= num;
  }
}

void multiplicaColuna(int m[][COLUNAS], int coluna, int num, int linhas){
  for(int i = 0; i < linhas; i++){
    m[i][coluna] *= num; 
  }
}

int main() {
  int matriz[LINHAS][COLUNAS] = { {1, 2, 3, 4}, 
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12} };
  printf("Multiplicar a linha [1] por 2");
  printf("\nMultiplicar a coluna [2] por 3\n");
 
  int linha = 1;
  int num = 2;
  multiplicaLinha(matriz, linha, num, COLUNAS);


  int coluna = 2;
  num = 3;
  multiplicaColuna(matriz, coluna, num, LINHAS);

  
  for(int i = 0; i < LINHAS; i++) {
    for(int j = 0; j < COLUNAS; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}