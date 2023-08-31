#include <stdio.h>

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
