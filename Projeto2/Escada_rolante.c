#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição da estrutura Pessoa
typedef struct Pessoa {
  int chegada; // tempo de chegada da pessoa
  int sentido; // sentido em que ela vai(0 ou 1)
  int chegou;  // se a pessoa chegou ao outro lado
  struct Pessoa *next;
} Pessoa;

// Função para criar um novo nó (Pessoa)
Pessoa *criarPessoa(int chegada, int sentido) {
  // aloca a memoria
  Pessoa *novaPessoa = (Pessoa *)malloc(sizeof(Pessoa));
  if (novaPessoa == NULL) {
    printf("Erro na alocação de memória.\n");
    exit(EXIT_FAILURE);
  }
  // inicializa o ponteiro
  novaPessoa->chegada = chegada;
  novaPessoa->sentido = sentido;
  novaPessoa->next = NULL;
  return novaPessoa;
}

// Função para adicionar um nó (Pessoa) no final da lista
void adicionarAoFimLista(Pessoa **head, Pessoa *novaPessoa) {
  if (*head == NULL) {
    // lista vazia, vira o topo da lista
    *head = novaPessoa;
  } else {
    // se a lista nao estiver vazia, vai ate o final e adiciona o novo no
    Pessoa *atual = *head;
    while (atual->next != NULL) {
      atual = atual->next;
    }
    atual->next = novaPessoa;
  }
}

// Função para remover o nó (Pessoa) no início da lista
void removerDoInicio(Pessoa **head) {
  if (*head != NULL) {
    // remove o no do topo e libera memoria
    Pessoa *temp = *head;
    *head = (*head)->next;
    free(temp);
  }
}

// Função para imprimir os elementos da lista
void imprimirLista(Pessoa *head) {
  Pessoa *atual = head;
  while (atual != NULL) {
    // imprimi os dados. Qual o tempo de chegada e o sentido em que ela vai
    printf("%d %d \n", atual->chegada, atual->sentido);
    atual = atual->next;
  }
}
// limpar toda a lista
void limpaLista(Pessoa **head) {
  while (*head != NULL) {
    removerDoInicio(head);
  }
}

int main() {
  int N, i;
  int tempofinal, limite;
  Pessoa *pessoas = NULL;

  srand(time(NULL));

  printf("Digite o número de pessoas: ");
  scanf("%d", &N); // le o numero de pessoas que ira na esca rolante

  if (N > 100000) {
    printf("Numero de pessoas nao cabe na escada rolante.\n");
    return 1; // Termina o programa com código de erro 1
  }

  int ultimo_valor = 0;

  // loop para gerar pessoas com tempos aleatorios e o sentido variar entre 0 e
  // 1
  for (i = 0; i < N; i++) {
    int chegada, sentido;
    chegada = ultimo_valor + (rand() % 10) + 1; // tempo aleatorio
    ultimo_valor = chegada;

    sentido = rand() % 2;

    Pessoa *novaPessoa = criarPessoa(chegada, sentido);
    adicionarAoFimLista(&pessoas, novaPessoa);
  }

  tempofinal = 0;
  limite = 10;

  Pessoa *atual = pessoas; // inicializa o ponteiro para percorrer a lista
  // loop para processar as chegadas e sentidos e ver o tempo final
  while (atual != NULL) {
    if (atual->chegou == 0) {
      if (tempofinal == 0) {
        tempofinal = atual->chegada + 10;
      } else {
        tempofinal += 10;
      }
      atual->chegou = 1;
    }
    // loop para ver as restricoes do programa
    for (Pessoa *j = atual->next; j != NULL; j = j->next) {
      int diff = j->chegada - atual->chegada;
      if (limite - diff > 0 || tempofinal > j->chegada) {
        if (atual->sentido == j->sentido && j->chegou == 0) {
          if (tempofinal > j->chegada + 10) {
            tempofinal = tempofinal;
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

  // imprime a lista
  imprimirLista(pessoas);
  printf("Tempo final: %d\n", tempofinal); // retorna o tempo final

  // Liberando a memória alocada para as listas
  limpaLista(&pessoas); // libera memoria

  return 0;
}
