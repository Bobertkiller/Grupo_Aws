#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N, i, j;
    int tp[1000]; // Assumindo um tamanho máximo de 100 para os arrays
    int di[1000];
    int tempofinal, direcao, aguardando;

    srand(time(NULL));

    printf("Digite o número de pessoas: ");
    scanf("%d", &N);

    tp[0] = rand() % 10;

    for (i = 1; i < N; i++) {
        tp[i] = tp[i - 1] + (rand() % 10) + 1;
    }

    for (i = 0; i < N; i++) {
        di[i] = rand() % 2;
    }

    tempofinal = 0;
    direcao = -1;
    aguardando = 0;

    for (i = 0; i < N; i++) {
        if (direcao == -1) {
            direcao = di[i];
            tempofinal = tp[i] + 10;
        } else if (direcao == di[i]) {
            tempofinal = tp[i] + 10;
        } else {
            if (tp[i] <= tempofinal) {
                aguardando += tempofinal - tp[i];
                tempofinal += 10;
            } else {
                aguardando = 0;
                tempofinal = tp[i] + 10;
            }
            direcao = di[i];
        }
    }

    for (i = 0; i < N; i++) {
        printf("%d %d\n", tp[i], di[i]);
    }

    printf("Tempo final: %d\n", tempofinal);

    return 0;
}
