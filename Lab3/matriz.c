    #include <pthread.h>
    #include <stdlib.h>
    #include <stdio.h>

    int m;
    int n;
    int thread_count;
    int **A;
    int *x;
    int *y;

    void *Pth_math_vect(void *rank) {
        long my_rank = (long) rank;
        int i, j;
        int local_m = m / thread_count;
        int my_first_row = my_rank * local_m;
        int my_last_row = (my_rank + 1) * local_m - 1;

        printf("Thread %ld esta funcionado da liha %d a %d\n", my_rank, my_first_row, my_last_row);

        for (i = my_first_row; i <= my_last_row; i++) {
            y[i] = 0;
            for (j = 0; j < n; j++) {
                y[i] += A[i][j] * x[j];
            }
        }

        return NULL;
    }

    int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero_de_threads>\n", argv[0]);
        return 1;
    }

    thread_count = atoi(argv[1]);

    m = 10; 
    n = 10;

    A = (int **) malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        A[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            A[i][j] = i + j + 1; 
        }
    }

    x = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        x[i] = i + 1; 
    }

    y = (int *) malloc(m * sizeof(int));

    pthread_t *thread_handles;
    thread_handles = (pthread_t *) malloc(thread_count * sizeof(pthread_t));

    for (long thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Pth_math_vect, (void *) thread);
    }

    for (long thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }
        printf("\nMatrix A:\n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d\t", A[i][j]);
            }
            printf("\n");
        }

        printf("\nMAtriz x:\n");
        for (int i = 0; i < n; i++) {
            printf("%d\n", x[i]);
        }

        printf("\nResultado da multiplicacao da matriz y:\n");
        for (int i = 0; i < m; i++) {
            printf("%d\n", y[i]);
        }

        free(thread_handles);
        for (int i = 0; i < m; i++) {
            free(A[i]);
        }
        free(A);
        free(x);
        free(y);

        return 0;
    }
