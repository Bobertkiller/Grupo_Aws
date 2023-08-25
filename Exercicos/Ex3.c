#include <stdio.h>

int main() {

  int num, i, j;

  printf("Entre com um número ímpar: ");
  scanf("%d", &num);

  while(num % 2 == 0) {
    printf("O número precisa ser ímpar!\n");
    printf("Entre novamente com um número ímpar: ");
    scanf("%d", &num);
  }
  
  for(i=0; i<=(num/2)+1; i++) {

    for(j=i+1; j<=num-i; j++) {

      printf("%d ", j);
    }

    printf("\n");

    for ( j = 0; j < (i + 1) * 2; j++ ){
        printf(" ");
    }
  }

  return 0;
}