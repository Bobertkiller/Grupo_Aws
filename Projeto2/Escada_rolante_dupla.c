#include <stdio.h>

int main() {
  int N, tp, di, tempofinal, direcao, aguardando; //tp = tempo que a pessoa chegou na escada, di é a direcao em que ela vai, tempofinal é o tempo em que ela chegou ao outro lado da escada, 
  //direcao é qual lado ela quer ir, aguardando é o tempo em que ela espera a outra pessoa chegar ao outro lado caso va em direcoes opostas.

  printf("Digite a quantidade de pessoas e depois os tempos de chegada\n");  
  scanf("%d", &N);
  
  tempofinal = 0; // inicia com tempo 0
  direcao = -1; //inicia com direcao como 0
  aguardando = 0;

  
  for(int i = 0; i < N; i++) {
    scanf("%d %d", &tp, &di);
    
    //se a direcai nao foi definida, apenas atualiza o tempo final
    if(direcao == -1) {
        direcao = di;
        tempofinal = tp + 10; 
    } else if(direcao == di) {
        tempofinal = tp + 10; // se ja foi definida e é igual a direcao atual, somente atualiza o tempo
    } else { // se a direcao for diferente a da anterior
        if(tp <= tempofinal) {  // ve se chegou antes da mudanca
            aguardando += tempofinal - tp;  //soma o tempo com a diferenca entre o tempo final da pessoa anterior com o tempo de chegada da pessoa atual
            tempofinal += 10; // ajusta com a ultima pessoa que chegou 
        } else {
            aguardando = 0;  // Reinicia o tempo de espera se a pessoa chegar após a mudança de direção
            tempofinal = tp + 10; // arruma o tempo da ultima pessoa
        }
        direcao = di; // atualiza a direcao da pessoa
    }
  }
  
  printf("Tempo final foi de: %d\n", tempofinal );
  
  return 0;  
}