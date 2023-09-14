#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <pthread.h>
// 64kB stack
#define FIBER_STACK 1024*64
struct c {
    int saldo;
};

typedef struct c conta;
conta from, to;
int valor;

pthread_mutex_t lock;

// The child thread will execute this function
void * transferencia( void* arg){
    int* index = (int*)arg;
    pthread_mutex_lock(&lock);


    if (from.saldo >= valor){ // 2
        from.saldo -= valor;
        to.saldo += valor;
        printf("Transferência concluída com sucesso!\n");
        printf("Saldo de c1: %d\n", from.saldo);
        printf("Saldo de c2: %d\n", to.saldo);
    }

    pthread_mutex_unlock(&lock);

 
    return NULL;
}
int main() {
    void* stack;
    pthread_t threads[100]; // Array de threads
    int i;

    // Inicializa o mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("Mutex initialization failed");
        exit(1);
    }

    // Aloca a pilha
    stack = malloc(FIBER_STACK);
    if (stack == NULL) {
        perror("malloc: could not allocate stack");
        exit(1);
    }

    // Ambas as contas começam com saldo 100
    from.saldo = 100;
    to.saldo = 100;

    printf("Transferindo 10 para a conta c2\n");
    valor = 10;

    for (i = 0; i < 10; i++) {
        int* index = malloc(sizeof(int));
        *index = i;

        // Cria as threads
        if (pthread_create(&threads[i], NULL, transferencia, (void*)index) != 0) {
            perror("pthread_create");
            exit(2);
        }
    }

    // Aguarda as threads terminarem
    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Libera a pilha e o mutex
    free(stack);
    pthread_mutex_destroy(&lock);

    printf("Transferências concluídas e memória liberada.\n");
    return 0;
}