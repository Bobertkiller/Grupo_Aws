#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 100

typedef struct {
    int saldo;
} conta;

conta from, to;
int valor;
pthread_mutex_t lock;

void *transferencia(void *arg) {
    int *params = (int *)arg;
    int index = params[0];
    int direcao = params[1];

    pthread_mutex_lock(&lock);

    if (direcao == 1) {
        if (from.saldo >= valor) {
            from.saldo -= valor;
            to.saldo += valor;

            printf("Thread %d:\n", index);
            printf("Saldo de to: %d\n", to.saldo);
            printf("Saldo de from: %d\n", from.saldo);
            printf("Transferencia feita com sucesso\n");
        } else {
            printf("Thread %d: Transferência falhou por saldo insuficiente!\n", index);
        }
    } else if (direcao == 2) {
        if (to.saldo >= valor) {
            to.saldo -= valor;
            from.saldo += valor;

            printf("Thread %d:\n", index);
            printf("Saldo de to: %d\n", to.saldo);
            printf("Saldo de from: %d\n", from.saldo);
            printf("Transferencia feita com sucesso\n");
        } else {
            printf("Thread %d: Transferência falhou por saldo insuficiente!\n", index);
        }
    } else {
        printf("Thread %d: Direção de transferência inválida!\n", index);
    }

    pthread_mutex_unlock(&lock);

    free(params);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];

    pthread_mutex_init(&lock, NULL);

    from.saldo = 100;
    to.saldo = 100;

    int num_transferencias, direcao;

    printf("Informe o número de transferências desejadas: ");
    scanf("%d", &num_transferencias);

    if (num_transferencias > MAX_THREADS) {
        printf("O número de transferências não pode exceder %d.\n", MAX_THREADS);
        exit(1);
    }

    printf("Informe o valor da transação: ");
    scanf("%d", &valor);
    
    printf("\n*****1- Vai de from para to*****\n");
    printf("*****2 - vai de to para from*****\n");
    printf("\nEscolha a direção para as transferências (1 ou 2): ");
    scanf("%d", &direcao);

    for (int i = 0; i < num_transferencias; i++) {
        int *params = malloc(2 * sizeof(int));
        params[0] = i;
        params[1] = direcao;

        if (pthread_create(&threads[i], NULL, transferencia, (void *)params) != 0) {
            perror("pthread criado");
            exit(2);
        }
    }

    for (int i = 0; i < num_transferencias; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    printf("Transferências concluídas e memória liberada.\n");
    printf("Saldo final de to: %d\n", to.saldo);
    printf("Saldo final de from: %d\n", from.saldo);
    return 0;
}
