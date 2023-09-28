#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 100 

typedef struct { 
    int saldo;
} conta;

conta banco_1, banco_2; 

int pix;

pthread_mutex_t lock; 


void *transferencia(void *arg) {
    int aux = *(int *)arg;    
    int direcao = *((int *)arg+1);    
    pthread_mutex_lock(&lock);


    switch (direcao) { 
        case 1: 
            if (banco_1.saldo >= pix) { 
                banco_1.saldo -= pix; 
                banco_2.saldo += pix; 

                printf("Thread %d:\n", aux); 
                printf("Saldo de banco_1: %d\n", banco_1.saldo); 
                printf("Saldo de banco_2: %d\n", banco_2.saldo); 
                printf("Transferencia feita com sucesso\n"); 
            } else {
                printf("Thread %d: Transferência falhou por saldo insuficiente!\n", aux); 
            }
            break; 
        
        case 2: 
            if (banco_2.saldo >= pix) {  
                banco_2.saldo -= pix; 
                banco_1.saldo += pix; 

                printf("Thread %d:\n", aux); 
                printf("Saldo de banco_1: %d\n", banco_1.saldo);
                printf("Saldo de banco_2: %d\n", banco_2.saldo); 
                printf("Transferencia feita com sucesso\n"); 
            } else {
                printf("Thread %d: Transferência falhou por saldo insuficiente!\n", aux);
            }
            break;

        default:
            printf("Direção de transferência inválida!\n"); 
            break;
    }

    pthread_mutex_unlock(&lock); 


    pthread_exit(NULL); 
}


int main() {
    pthread_t threads[MAX_THREADS]; 

    pthread_mutex_init(&lock, NULL);    

    int num_transferencias, transacao; 

    banco_1.saldo = 100; 
    banco_2.saldo = 100; 

    
    printf("Quantas transacoes quer fazer? ");
    scanf("%d", &num_transferencias);

    if (num_transferencias > MAX_THREADS) { 
        printf("O número de transacoes muito alto. Maximo 100 transacoes\n");
        exit(1);
    }

    printf("Informe o valor: ");
    scanf("%d", &pix); 
    
    printf("\n*****1- Vai de banco_1 para banco_2*****\n");
    printf("*****2 - Vai de banco_2 para banco_1*****\n");
    printf("\nEscolha a direção para as transferências (1 ou 2): ");
    scanf("%d", &transacao); 

    for (int i = 0; i < num_transferencias; i++) {
        int args[2]; 
        args[0] = i; 
        args[1] = transacao; 

        if (pthread_create(&threads[i], NULL, transferencia, (void *)args) != 0) {
            perror("pthread criado");
            exit(2);
        }

    }   

    for (int i = 0; i < num_transferencias; i++) {
        pthread_join(threads[i], NULL); 
    }

    pthread_mutex_destroy(&lock); 

    printf("Transferências concluídas e memória liberada.\n");
    printf("Saldo final de banco_1: %d\n", banco_1.saldo);
    printf("Saldo final de banco_2: %d\n", banco_2.saldo);
    return 0;
}
