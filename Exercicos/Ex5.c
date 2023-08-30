#include <stdio.h>
#include <stdlib.h>

int main(void){
    int a, b, num, i,j;

    printf("Insira o número de colunas: ");
    scanf("%d", &a);

    printf("Insira o número de linhas: ");
    scanf("%d", &b);

    int m[a][b];

    for( i = 0; i < a;i++){
        for( j = 0; j < b; j++){
            m[i][j] = 0;
        }
    }
    
    for( i = 0; i < a;i++){
        for( j = 0; j < b; j++){
            printf("Insira o elemento m[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    printf("Entre com o número para multiplicar: ");
    scanf("%d", &num);
     
    int linha, coluna;

    printf("Entre com a linha a ser multiplicada: ");
    scanf("%d", &linha);

    printf("Entre com a coluna a ser multiplicada: "); 
    scanf("%d", &coluna);

    for(j=0; j<b; j++) {
        m[linha][j] *= num; 
    }
    
    for(i=0; i<a; i++) {
        m[i][coluna] *= num;
    }

    printf("Matriz resultante:\n");

    for(i=0; i<a; i++) {
        for(j=0; j<b; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

  return 0;
}


