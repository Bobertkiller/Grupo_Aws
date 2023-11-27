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

    printf("Digite os tempos de chegada e direções para cada pessoa:\n");

    for (i = 0; i < N; i++) {
        printf("Tempo de chegada para a pessoa %d: ", i + 1);
        scanf("%d", &tp[i]);

        printf("Direção para a pessoa %d (0 para esquerda, 1 para direita): ", i + 1);
        scanf("%d", &di[i]);
    }

    tempofinal = 0;
    direcao = -1;
    aguardando = 0;

    for (i = 0; i < N; i++) {
        if (direcao == -1) { //verifica se é a primeira pessoa que chegou
            direcao = di[i]; // coloca no sentido da primeira pessoa
            tempofinal = tp[i] + 10;
        } else if (direcao == di[i]) { // verifica se o sentido é o mesmo
            tempofinal = tp[i] + 10;
        } else if (direcao != di[i] && direcao == di[i + 1] && tp[i + 1] <= tempofinal){
            aguardando += tempofinal - tp[i + 1];
            tempofinal = tp[i + 1] + 10;
        }
        else {
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
        printf("Pessoa %d: Tempo de chegada: %d, Direção: %d\n", i + 1, tp[i], di[i]);
    }

    printf("Tempo final: %d\n", tempofinal);

    return 0;
}
