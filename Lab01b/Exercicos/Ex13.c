#include <stdio.h>
#include <string.h>

void removerCaractere(char *string, int posicao) {
    int tamanho = strlen(string);
    
    if (posicao >= 0 && posicao < tamanho) {
        for (int i = posicao; i < tamanho - 1; i++) {
            string[i] = string[i + 1];
        }
        
        string[tamanho - 1] = '\0'; 
    }
}

int main(void) {
    char minhaString[100] = "Exemplo";
    int posicao = 3; 
    
    printf("String antes da remoção: %s\n", minhaString);
    removerCaractere(minhaString, posicao);
    printf("String depois da remoção: %s\n", minhaString);

}
