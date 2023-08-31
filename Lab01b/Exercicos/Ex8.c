#include <stdio.h>


void transposta(int linha, int coluna, int [*m][coluna]) {
    int temp;
    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            temp = m[i][j]
            m[i][j] = m[j][i]; 
            m[i][j] = temp;

        }
    }
}