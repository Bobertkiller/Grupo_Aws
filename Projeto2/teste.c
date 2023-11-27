#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição da estrutura Pessoa
typedef struct Pessoa {
    int chegada;
    int sentido;
    int chegou;
    struct Pessoa* next;
} Pessoa;

// Função para criar um novo nó (Pessoa)
Pessoa* criarPessoa(int chegada, int sentido) {
    Pessoa* novaPessoa = (Pessoa*)malloc(sizeof(Pessoa));
    if (novaPessoa == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    novaPessoa->chegada = chegada;
    novaPessoa->sentido = sentido;
    novaPessoa->next = NULL;
    return novaPessoa;
}

// Função para adicionar um nó (Pessoa) no final da lista
void adicionarAoFimLista(Pessoa** head, Pessoa* novaPessoa) {
    if (*head == NULL) {
        *head = novaPessoa;
    } else {
        Pessoa* atual = *head;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = novaPessoa;
    }
}

// Função para remover o nó (Pessoa) no início da lista
void removerDoInicio(Pessoa** head) {
    if (*head != NULL) {
        Pessoa* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Função para imprimir os elementos da lista
void imprimirLista(Pessoa* head) {
    Pessoa* atual = head;
    while (atual != NULL) {
        printf("Chegada: %d, Sentido: %d -> ", atual->chegada, atual->sentido);
        atual = atual->next;
    }
    printf("NULL\n");
}

void limpaLista(Pessoa** head) {
    while (*head != NULL) {
        removerDoInicio(head);
    }
}

int main() {
    int N, i;
    int tempofinal, limite;
    Pessoa* pessoas = NULL;

    srand(time(NULL));

    printf("Digite o número de pessoas: ");
    scanf("%d", &N);

    printf("Digite os tempos de chegada e direções para cada pessoa:\n");

    for (i = 0; i < N; i++) {
        int chegada, sentido;
        printf("Tempo de chegada para a pessoa %d: ", i + 1);
        scanf("%d", &chegada);

        printf("Sentido para a pessoa %d (0 para esquerda, 1 para direita): ", i + 1);
        scanf("%d", &sentido);

        Pessoa* novaPessoa = criarPessoa(chegada, sentido);
        adicionarAoFimLista(&pessoas, novaPessoa);
    }

    tempofinal = 0;
    limite = 0;

    Pessoa* atual = pessoas;

    while (atual != NULL) {
        if (atual->chegou == 0) {
            if (tempofinal == 0) {
                tempofinal = atual->chegada + 10;
            } else {
                tempofinal += 10;
            }
            atual->chegou = 1;
        }

        for (Pessoa* j = atual->next; j != NULL; j = j->next) {
            int diff = j->chegada - atual->chegada;
            if (limite - diff > 0 || tempofinal > j->chegada) {
                if (atual->sentido == j->sentido && j->chegou == 0) {
                    if (tempofinal > j->chegada + 10) {
                        continue;
                    } else {
                        tempofinal = j->chegada + 10;
                    }
                    limite = 10;
                    j->chegou = 1;
                } else {
                    limite -= diff;
                }
            } else {
                break;
            }
        }

        atual = atual->next;
    }

    imprimirLista(pessoas);
    printf("Tempo final: %d\n", tempofinal);

    // Liberando a memória alocada para as listas
    limpaLista(&pessoas);

    return 0;
}
