#include <stdio.h>


void transposta(int linha, int coluna, int [linhas][coluna]) {
    int temp;
    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            if(m[i][j]<0){
                m[i][j] = -m[i][j];
            }
        }
    }
}