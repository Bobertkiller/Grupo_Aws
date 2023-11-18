#include <stdio.h>

int main() {
    int N, tempofinal, direcao, aguardando;

    printf("Digite a quantidade de pessoas e depois os tempos de chegada e direções\n");
    scanf("%d", &N);

    int tp[N], di[N];  // Usar listas para armazenar os tempos e direções

    tempofinal = 0;
    direcao = -1;
    aguardando = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &tp[i], &di[i]);

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

    // Verifica se todos os tempos são para a mesma direção e adiciona 10 ao último tempo
    int mesmaDirecao = 1;
    for (int i = 1; i < N; i++) {
        if (di[i] != di[0]) {
            mesmaDirecao = 0;
            break;
        }
    }

    if (mesmaDirecao) {
        tempofinal += 10;
    }

    printf("Tempo final foi de: %d\n", tempofinal);

    return 0;
}
