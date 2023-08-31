#include <stdio.h>
#include <stdlib.h>

int menor_m(int matriz[3][3]){
    int a = matriz[0][0];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (matriz[i][j] < a) {
                a = matriz[i][j];
            }
        }
    }
    return a;
}

int main(void){
    int matriz[3][3], i, j;
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3; j++){
            printf("Insira o elemento m[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    printf("Menor numero da matriz: %d\n", menor_m(matriz));
    
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (matriz[i][j] == menor_m(matriz)) {
                printf("Linha com o menor numero: %d\n", i );
                break; // Sair do loop interno após encontrar o primeiro elemento igual ao menor
            }
        }
    }

    return 0;
}
