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
void adicionarAoFim(Pessoa** head, int chegada, int sentido) {
    Pessoa* novaPessoa = criarPessoa(chegada, sentido);
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

Pessoa* verificarInicioFila(Pessoa* head) {
    return head;
}

int contarSentidosDiferentes(Pessoa* head) {
    int sentido0Encontrado = 0;
    int sentido1Encontrado = 0;

    Pessoa* atual = head;

    while (atual != NULL) {
        if (atual->sentido == 0) {
            sentido0Encontrado = 1;
        } else if (atual->sentido == 1) {
            sentido1Encontrado = 1;
        }

        atual = atual->next;
    }

    if (sentido0Encontrado && sentido1Encontrado) {
        // Ambos os sentidos estão presentes
        return 2;
    } else if (sentido0Encontrado || sentido1Encontrado) {
        // Apenas um sentido está presente
        return 1;
    } else {
        // Nenhum sentido está presente (lista vazia)
        return 0;
    }
}

int main() {
    int N, i;
    int tempofinal, direcao;
    Pessoa* pessoas;

    srand(time(NULL));

    printf("Digite o número de pessoas: ");
    scanf("%d", &N);

    pessoas = (Pessoa*)malloc(N * sizeof(Pessoa));

    printf("Digite os tempos de chegada e direções para cada pessoa:\n");

    for (i = 0; i < N; i++) {
        printf("Tempo de chegada para a pessoa %d: ", i + 1);
        scanf("%d", &pessoas[i].chegada);

        printf("Sentido para a pessoa %d (0 para esquerda, 1 para direita): ", i + 1);
        scanf("%d", &pessoas[i].sentido);
        pessoas[i].chegou = 0;
    }

    tempofinal = 0;
    direcao = -1;

    Pessoa* atual = NULL;   // Lista das pessoas atuais na escada
    Pessoa* aguardo = NULL; // Lista das pessoas em espera

    for (i = 0; i < N; i++) {

        if (direcao == -1 ){
            adicionarAoFim(&atual, pessoas[i].chegada, pessoas[i].sentido);
            tempofinal = pessoas[i].chegada + 10;
            direcao = pessoas[i].sentido;
        }
        else if (direcao == pessoas[i].sentido && tempofinal >= pessoas[i].chegada){
            adicionarAoFim(&atual, pessoas[i].chegada, pessoas[i].sentido);
            tempofinal = pessoas[i].chegada + 10;
        }else {
            Pessoa* elem = verificarInicioFila(aguardo);
            if (direcao != pessoas[i].sentido && tempofinal < pessoas[i + 1].chegada && pessoas[i].sentido == pessoas[i].sentido) {

                limpaLista(&atual);
                adicionarAoFim(&atual, pessoas[i].chegada, pessoas[i].sentido);
                tempofinal += 10;

            } else if (elem != NULL && pessoas[i].chegada > tempofinal) {

                limpaLista(&atual);
                adicionarAoFim(&atual, elem->chegada, elem->sentido);
                tempofinal += 10;
                direcao = elem->sentido;
                removerDoInicio(&aguardo);

            } else if (tempofinal < pessoas[i].chegada && aguardo == NULL) {

                limpaLista(&atual);
                adicionarAoFim(&atual, pessoas[i].chegada, pessoas[i].sentido);
                tempofinal = pessoas[i].chegada + 10;
                direcao = pessoas[i].sentido;

            } else {
                adicionarAoFim(&aguardo, pessoas[i].chegada, pessoas[i].sentido);
            }
        }
    }

    if (contarSentidosDiferentes(aguardo) == 1){
        tempofinal += 10;
    } else if(contarSentidosDiferentes(aguardo) == 2) {
        tempofinal += 20;
    }

    for (i = 0; i < N; i++) {
        printf("Pessoa %d: Chegada: %d, Sentido: %d\n", i + 1, pessoas[i].chegada, pessoas[i].sentido);
    }

    printf("Tempo final: %d\n", tempofinal);

    free(pessoas);

    // Liberando a memória alocada para as listas
    limpaLista(&atual);
    limpaLista(&aguardo);

    return 0;
}
