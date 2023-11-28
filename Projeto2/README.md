# Grupo_Aws
É o grupo Milf Hunters Sistemas Operacionais

# Integrantes

- Matteo Domiciano Varnier
- Felipe Mazzeo Barbosa
- Daniel Reis Raske

# Sobre o Projeto

Devemos simular o funcionamento da escada rolante dupla com base nas informações fornecidas sobre a chegada das pessoas, o momento em que elas chegam e a direção em que desejam se mover. O objetivo é determinar o momento em que a última pessoa sai da escada rolante.



# Como foi resolvido o problema

A estrutura central do programa é a definição da estrutura de dados Pessoa, que representa cada indivíduo na simulação. Cada instância dessa estrutura contém informações essenciais, tais como o tempo de chegada (chegada), o sentido em que a pessoa se desloca (0 ou 1) (sentido), e um indicador se ela já chegou ao outro lado da escada (chegou).

A alocação dinâmica de memória é empregada para armazenar as informações de todas as pessoas envolvidas na simulação.

A lógica principal do código está na determinação do tempo total necessário para que todas as pessoas utilizem a escada sem conflitos. O programa percorre cada pessoa e, para cada uma, verifica se há outras pessoas na escada que possam causar conflitos de movimento. Se existirem, o tempo total é ajustado para garantir que a pessoa atual possa utilizar a escada sem colidir com outras.

O tempo total é calculado passando por cada pessoa na escada. O tempo que cada pessoa leva para se mover é calculado com base em condições específicas. Se for a primeira pessoa, o tempo é o momento em que chegou mais 10 segundos. Para as pessoas seguintes, o tempo depende de quando a pessoa anterior chegou e é aumentado em 10 segundos.

O programa também verifica as pessoas subsequentes, levando em consideração o sentido do movimento e o espaço disponível entre elas. Se duas pessoas estiverem se movendo no mesmo sentido e a segunda puder iniciar imediatamente após a primeira, o tempo total é ajustado. Se as pessoas estiverem se movendo em sentidos opostos, o programa reduz o contador com base no tempo entre elas.

No final, o código informa quanto tempo levará para que todos usem a escada rolante de forma eficiente e sem conflitos.


# Sistema Operacional
![alt](assets/Sistema.png)

## Compilar
1. Clone o repositorio com o seguinte comando:
    https://github.com/Bobertkiller/Grupo_Aws.git
2. Acesse a pasta onde foi escolhido para dar o clone do git. Use `cd` para acessar a pasta.

    *Exemplo*:

    ![alt](/Projeto2/assets/cd.png)

    ***feito no prompt de comando do linux***
3. Digite `gcc` para poder compilar o codigo

    *Exemplo*:

    ![alt](/Projeto2/assets/gcc.png)

    ***feito no prompt de comando do linux***
3. Digite `./nome do arquivo` para poder rodar o codigo

    *Exemplo*:

    ![alt](/Projeto2/assets/barra.png)

    ***feito no prompt de comando do linux***
# Testes de mesa
###  Teste de mesa com 5 pessoas
![alt](/Projeto2/assets/print4.png)

###  Teste de mesa com 10 pessoas 
![alt](/Projeto2/assets/print1.png)

### Teste de mesa com 100 pessoas

![alt](/Projeto2/assets/print2.png)
![alt](/Projeto2/assets/print3.png)