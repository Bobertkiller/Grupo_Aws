#include <stdio.h>
#include <stdlib.h>

struct escola{
    float N1;
    float N2;
    float N3;
    float media;
    float NA;
    char nota;
};

int main(){
    int quant_alunos = 3;
    struct escola aluno[quant_alunos];
    
    for (int i = 0; i < quant_alunos; i++){
        printf("\n"); 
        printf("Aluno %d\n", i+1);
        
        printf("Digite a nota N1: ");
        scanf("%f", &aluno[i].N1 );
        
        printf("Digite a nota N2: ");
        scanf("%f", &aluno[i].N2 );

        printf("Digite a nota N3: ");
        scanf("%f", &aluno[i].N3 );
        
        aluno[i].media = (aluno[i].N1 + aluno[i].N2 + aluno[i].N3) / 3;

        aluno[i].NA = (+aluno[i].N1 + aluno[i].media + aluno[i].N2 * 2 + aluno[i].N3 * 3) / 7;
        printf("A nota de aproveitamento do aluno %d = %.2f\n", i+1, aluno[i].NA);   

        if (aluno[i].NA >= 9){
            aluno[i].nota = 'A';
        } else if (7.5 <= aluno[i].NA && aluno[i].NA < 9){
            aluno[i].nota = 'B';
        } else if (6 <= aluno[i].NA && aluno[i].NA < 7.5){
            aluno[i].nota = 'C';
        } else if (4 <= aluno[i].NA && aluno[i].NA < 6){
            aluno[i].nota = 'D';
        } else {
            aluno[i].nota = 'E';
        }
        printf("Aluno %d tem a nota %c\n", i+1, aluno[i].nota) ;
    }
    return 0;
}
