#include <stdio.h>
#include <stdlib.h>

void soma_linha(int a,int b, int (*m)[b]){

    int i = 0;
    
    for(int j = 0; j < b; j++){
        m[i+1][j]= m[i+1][j] + m[i][j];
    }
    
}

void multiplica_linha(int a,int b, int (*m)[b]){

    int i = 0;
    
    for(int j = 0; j < b; j++){
        m[i+1][j]= m[i+1][j] * m[i][j];
    }
    
}

int main(void){


    int m[4][4] = {{2,4,6,8},{3,6,9,12},{4,8,12,16},{5,10,15,20}};
    int n[4][4] = {{2,4,6,8},{3,6,9,12},{4,8,12,16},{5,10,15,20}};

    printf("Matriz Original:\n");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }   
    printf("\n");
    
    soma_linha(4,4, m);

    printf("Matriz pós operação:\n");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Matriz Original:\n");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", n[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    multiplica_linha(4,4,n);

    printf("Matriz pós operação:\n");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", n[i][j]);
        }
        printf("\n");
    }

}
