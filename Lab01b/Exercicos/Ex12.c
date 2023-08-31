#include <stdio.h>
#include <string.h>

int encontrarCaractere(const char *string, char caractere) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == caractere) {
            return i; 
        }
    }
    
    return -1; 
}

int main(void) {
    char *minhaString = "Exemplo de string";
    char meuCaractere = 'd';
    
    printf("A frase escolhida foi: Exemplo de string.\nA letra escolhida foi: d\n");

    int posicao = encontrarCaractere(minhaString, meuCaractere);
    
    if (posicao != -1) {
        printf("O caractere '%c' foi encontrado na posição %d da string.\n", meuCaractere, posicao);
    } else {
        printf("O caractere '%c' não foi encontrado na string.\n", meuCaractere);
    }
    
}
