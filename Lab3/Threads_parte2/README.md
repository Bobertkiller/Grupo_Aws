# Grupo_Aws
É o grupo Milf Hunters Sistemas Operacionais

# Integrantes

- Matteo Domiciano Varnier
- Felipe Mazzeo Barbosa
- Daniel Reis Raske

## Software

![alt](assets/linux.png)

## Arquivos

- `pi_mut.c`: É o código fonte do execicio utilizando mutex.
- `log_mutex`: É o log do código do arquivo `pi_mut.c`.
- `pi.c`: É o código fonte do execicio sem utiliza mutex.
- `log_sem_mutex`: É o log do código do arquivo `pi.c`.

## Tarefa
- A função utilizada para calcular π (pi) nas implementações é chamada `Thread_sum` Esta função é executada por cada thread e é responsável por calcular uma parte da estimativa de π usando a Série de Leibniz.
- Cada thread calcula uma parte da soma total da série de Leibniz, e a soma total dessas partes é usada para estimar o valor de π. A variável compartilhada `sum` é protegida por um mutex na implementação que utiliza mutex para evitar condições de corrida e garantir que as threads atualizem `sum` de forma segura.

## a)
- **Sem Mutex :** Nesta solução, as threads estão calculando partes diferentes da série sem sincronização explícita entre elas. Cada thread atualiza a variável `sum` sem considerar outras threads que podem estar fazendo o mesmo. O que pode levar a condições de corida e a resultados inconsistentes, ficando cada vez mais inconsistente quanto maior for o número de threads.

- **Com Mutex :** Nesta solução,um mutex foi introduzido para proteger a variável compartilhada `sum`. O que acaba "barrando" os threads, ou seja, apenas uma thread de cada vez pode adquirir o mutex e, portanto, atualizar `sum`. Isso garante que não haja condições de corrida e que o resultado final seja consistente, independentemente do número de threads.

- **Comparação :** A solução com mutex é mais segura e robusta em termos de evitar condições de corrida e garantir resultados consistentes, independentemente do número de threads. 