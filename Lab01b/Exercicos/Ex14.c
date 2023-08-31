#include <stdio.h>
#include <string.h>

void inserirCaractere(char *string, int posicao, char caractere) {
    int tamanho = strlen(string);
    
    if (posicao >= 0 && posicao <= tamanho) {
        for (int i = tamanho; i >= posicao; i--) {
            string[i + 1] = string[i];
        }
        
        string[posicao] = caractere;
    }
}

int main(void) {
    char minhaString[100] = "Exemplo";
    int posicao = 2; 
    char caractere = 'a';
    
    printf("String antes da inserção: %s\n", minhaString);
    inserirCaractere(minhaString, posicao, caractere);
    printf("String depois da inserção: %s\n", minhaString);
    
}
