#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 100 //define quantas trasnferencias maximas pode ser feitas

typedef struct { //estrutura de dados chamado conta, 
    int saldo;
} conta;

conta banco_1, banco_2; //declara as duas variaveis com a conta

int pix;

pthread_mutex_t lock; //sincronizar o acesso concorrente a partes críticas do código,

//Essa função implementa uma transferência bancária entre duas contas 
void *transferencia(void *arg) {
    int aux = *(int *)arg;    // O primeiro argumento, que é o número da thread
    int direcao = *((int *)arg+1);    // O segundo argumento, que é a direção da transferência
    pthread_mutex_lock(&lock); // garante com que apenas uma thread por vez execute, evitando a corrida entre elas.


    switch (direcao) { //faz cada condicao
        case 1: //se for 1
            if (banco_1.saldo >= pix) { // ve se o valor do banco é maior do que o digitado
                banco_1.saldo -= pix; // se for, retira do saldo 
                banco_2.saldo += pix; // adiciona na outra conta

                printf("Thread %d:\n", aux); //mostra qual thread ta
                printf("Saldo de banco_1: %d\n", banco_1.saldo); //mostra saldo do banco apos a retirada
                printf("Saldo de banco_2: %d\n", banco_2.saldo); //mostra saldo do banco apos a retirada
                printf("Transferencia feita com sucesso\n"); //fala que foi feita com sucesso
            } else {
                printf("Thread %d: Transferência falhou por saldo insuficiente!\n", aux); //se o valor for maior, printa erro
            }
            break; //para
        
        case 2: //caso 2
            if (banco_2.saldo >= pix) {  //se o valor do banco 2 for maior que o valor digitado
                banco_2.saldo -= pix; //retira o valor do banco 2
                banco_1.saldo += pix; //adicionat o valor no banco1

                printf("Thread %d:\n", aux); //fala qual transferencia esta fazendo
                printf("Saldo de banco_1: %d\n", banco_1.saldo); //mostra saldo do banco apos a retirada
                printf("Saldo de banco_2: %d\n", banco_2.saldo); //mostra saldo do banco apos a retirada
                printf("Transferencia feita com sucesso\n"); //fala que foi feita com sucesso
            } else {
                printf("Thread %d: Transferência falhou por saldo insuficiente!\n", aux);//se o valor for maior, printa erro
            }
            break;

        default:
            printf("Thread %d: Direção de transferência inválida!\n", aux); //se o usuario nao digitar 1 ou 2, da erro
            break;
    }

    pthread_mutex_unlock(&lock); // permite que outras threads acessem a secao critica, fa


    pthread_exit(NULL); // chama para encerrar as threads
}


int main() {
    pthread_t threads[MAX_THREADS]; //vai criar a array, limitando com tamanho maximo

    pthread_mutex_init(&lock, NULL);    //usado para controlar o acesso em sequencia das operacoes

    int num_transferencias, transacao; //chama variaveis

    banco_1.saldo = 100; //indica os valores iniciais
    banco_2.saldo = 100; //indica os valores iniciais

    
    printf("Informe o número de transferências desejadas: ");
    scanf("%d", &num_transferencias);

    if (num_transferencias > MAX_THREADS) { //se o valor de transferencias for maior que 100, da erro
        printf("O número de transferências não pode exceder %d.\n", MAX_THREADS);
        exit(1);
    }

    printf("Informe o pix da transação: ");
    scanf("%d", &pix); //pede para o usuario digitar o vlaor da transacao
    
    printf("\n*****1- Vai de banco_1 para banco_2*****\n");
    printf("*****2 - Vai de banco_2 para banco_1*****\n");
    printf("\nEscolha a direção para as transferências (1 ou 2): ");
    scanf("%d", &transacao); //pede para escolher qual direcao ele quer ir

    for (int i = 0; i < num_transferencias; i++) {
        int args[2]; // Array para armazenar os argumentos
        args[0] = i; // Número da thread
        args[1] = transacao; // Direção da transferência

        if (pthread_create(&threads[i], NULL, transferencia, (void *)args) != 0) {
            perror("pthread criado");
            exit(2);
        }

    }   

    for (int i = 0; i < num_transferencias; i++) {
        pthread_join(threads[i], NULL); //bloqueia a execucao do programa ate a thread especifica ser executada
    }

    pthread_mutex_destroy(&lock); //Liberar os recursos associados ao mutex após a sua utilizaçã, para nao oculpar recurso

    printf("Transferências concluídas e memória liberada.\n");
    printf("Saldo final de banco_1: %d\n", banco_1.saldo);
    printf("Saldo final de banco_2: %d\n", banco_2.saldo);
    return 0;
}
