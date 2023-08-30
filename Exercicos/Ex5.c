#include <stdio.h>
#include <stdlib.h>

void multiplica_matriz(int a, int b, int (*A)[b]) {
    int i, j, k;

    for (i = 0; i < a; i++){
        
    }
}

int main(void){
    int a, b;

    printf("Insira o número de colunas: ");
    scanf("%d", &a);

    printf("Insira o número de linhas: ");
    scanf("%d", &b);

    int m[a][b];

    for(int i = 0; i < a;i++){
        for(int j = 0; j < b; j++){
            m[i][j] = 0;
        }
    }
    
    for(int i = 0; i < a;i++){
        for(int j = 0; j < b; j++){
            printf("Insira o elemento m[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
    
}
