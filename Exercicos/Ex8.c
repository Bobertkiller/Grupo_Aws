#include <stdio.h>
#include <stdlib.h>

void transposta(int a, int b, int (*m)[b]) {
    int temp;
    for (int i = 0; i < a; i++) {
        for (int j = i + 1; j < b; j++) {
            temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

int main(void) {
    int linhas;
    int colunas;

    printf("Informe o numero de Linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Informe o numero de colunas da matriz: ");
    scanf("%d", &colunas);

    int matriz[linhas][colunas];

    printf("Informe os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    transposta(linhas, colunas, matriz);

    printf("A matriz transposta e:\n");
    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
