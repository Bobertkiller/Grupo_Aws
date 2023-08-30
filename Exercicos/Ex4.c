#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main(void){
    char str1[MAX_LEN], str2[MAX_LEN];
    char temp[MAX_LEN];

    printf("Digite o primeiro nome: ");
    fgets(str1, MAX_LEN, stdin);

    printf("Digite o segundo nome: ");
    fgets(str2, MAX_LEN, stdin);

    if (strcmp(str1, str2) > 0) {
        strcpy(temp, str1);
        strcpy(str1, str2);
        strcpy(str2, temp);
    }

   printf("%s", str1);
   printf("%s", str2);

}