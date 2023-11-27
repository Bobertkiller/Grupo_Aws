#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição da estrutura Pessoa
typedef struct Pessoa {
    int chegada;
    int sentido;
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

void limpalista(Pessoa* head){
    while (head != NULL) {
        removerDoInicio(&head);
    }
}

Pessoa* verificarInicioFila(Pessoa* head) {
    if (head != NULL) {
        return head;
    } else {
        return NULL;
    }
}

int main() {
    int N, i;
    int chegada[1000]; // Assumindo um tamanho máximo de 1000 para os arrays
    int sentido[1000];
    int tempofinal, direcao;

    srand(time(NULL));

    printf("Digite o número de pessoas: ");
    scanf("%d", &N);

    printf("Digite os tempos de chegada e direções para cada pessoa:\n");

    for (i = 0; i < N; i++) {
        printf("Tempo de chegada para a pessoa %d: ", i + 1);
        scanf("%d", &chegada[i]);

        printf("Sentido para a pessoa %d (0 para esquerda, 1 para direita): ", i + 1);
        scanf("%d", &sentido[i]);
    }

    tempofinal = 0;
    direcao = -1;

    Pessoa* atual = NULL;   // Lista das pessoas atuais na escada
    Pessoa* aguardo = NULL; // Lista das pessoas em espera

    for (i = 0; i < N; i++) {

        if (direcao == -1){
            direcao = sentido[i];
            adicionarAoFim(&atual, chegada[i], sentido[i]);
            tempofinal = chegada[i] + 10;
        }
        else if (direcao == sentido[i] && tempofinal >= chegada[i]){

            adicionarAoFim(&atual, chegada[i], sentido[i]);
            tempofinal = chegada[i] + 10;
        }
        else {
            Pessoa* elem = verificarInicioFila(aguardo);
            if (elem != NULL && chegada[i] > tempofinal) {
                limpalista(atual);
                adicionarAoFim(&atual, elem->chegada, elem->sentido);
                tempofinal += 10;
                direcao = elem->sentido;
                adicionarAoFim(&aguardo, chegada[i], sentido[i]);
            } else if (tempofinal < chegada[i] && aguardo == NULL) { // começa do inicio a lista
                limpalista(atual);
                adicionarAoFim(&atual, chegada[i], sentido[i]);
                tempofinal = chegada[i] + 10;
                direcao = sentido[i];
            }
            else {
                adicionarAoFim(&aguardo, chegada[i], sentido[i]);
            }
        }
    }

    imprimirLista(atual);
    imprimirLista(aguardo);


    for (i = 0; i < N; i++) {
        printf("Pessoa %d: Chegada: %d, Sentido: %d\n", i + 1, chegada[i], sentido[i]);
    }

    printf("Tempo final: %d\n", tempofinal);

    // Liberando a memória alocada para as listas
    limpalista(atual);
    limpalista(aguardo);

    return 0;
}
