#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int thread_count;
int n;
double sum = 0.0;

void *Thread_sum(void *rank) {
    long my_rank = (long) rank;
    long long i;
    long long my_n = n / thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;
    double factor;

    if (my_first_i % 2 == 0)
        factor = 1.0;
    else
        factor = -1.0;

    for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
        sum += factor / (2.0 * i + 1);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <n>(número de iterações) <num_threads>\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);
    thread_count = atoi(argv[2]);

    if (thread_count > n) {
        printf("Error: O numero de threds não deve ser superior ao numero de iterações (n).\n");
        return 1;
    }

    pthread_t *thread_handles;
    thread_handles = (pthread_t *) malloc(thread_count * sizeof(pthread_t));

    for (long thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Thread_sum, (void *) thread);
    }

    for (long thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    double pi = 4.0 * sum;
    printf("Quantidade de threads: %d\n", thread_count);
    printf("Valor de pi calculado pelo algoritmo: %.15f\n", pi);

    free(thread_handles);

    return 0;
}
