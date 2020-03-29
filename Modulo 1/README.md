# Relatório Módulo 1

Para este módulo foram desenvolvidos três programas distintos, cada qual com o seu foco entre chamadas de sistema relacionadas a Arquivo, Memória ou Processos. Serão escolhidas ao menos 3 primitivas para cada uma das categorias e estas serão analisadas com relação ao tempo de execução em modo de Kernel e de usuário, à quantidade de trocas de contexto e à quantidade de vezes que ela é chamada em cada um dos programas.

## Identificação e Descrição das Chamadas de Sistema

Por meio do comando strace são identificadas as chamadas de sistemas nas tabelas abaixo, referentes às primitivas de memória, processos e arquivos, respectivamente. As suas breves descrições estão nestas mesmas tabelas. 

### Chamadas de Memória
|syscall| descrição  |
|:--|--|
| brk | desloca o fim do segmento de dados para um valor especificado, desde que o tamanho do processo não exceda o máximo permitido |
| mmap | cria um novo mapeamento no espaço de endereçamento virtual do processo chamado |
| munmap | deleta o mapeamento feito em um intervalo de endereços dado. É feito automaticamente quando o processo termina |
| mprotect | Define uma proteção para uma dada região de memória, como read only, write, etc. |
| time | Retorna o tempo em segundos passados desde 01/01/1970. Caso não seja nulo, o valor de retorno é guardado no valor da memória passado pelo parâmetro. |

### Chamadas de Processos
|syscall|descrição  |
|:--|--|
| execve | Executa o programa apontado no parâmetro, o qual deve ser um executável binário ou um script. |
| kill | Envia um sinal para o procesos ou grupo especificado. No caso utilizado é enviado o sinal SIGKILL, que o mata. |
| clone | Cria um novo processo. É utilizado pelo comando fork do C. Ao contrário da syscall fork ele permite que o processo divida partes da sua execução com o seu pai. |
| getpid | Retorna o identificador (ID) do processo. |
| arch prctl | Defina o processo ou thread específico de determinada arquitetura, selecionando uma subfunção e passando como argumento para a chamada de sistema. |


### Chamadas de E/S e Arquivos
|syscall|descrição  |
|:--|--|
| access | Checa se o processo tem acesso requisitado ao arquivo dado. É feita utilizando o UID e GID real do processo, ao invés do ID virtual, assim determinando com facilidade a autoridade do usuário. |
| read | Lê um número de bytes, passados por parâmetro, de um arquivo e armazena em um buffer. |
| write | Funciona de forma semelhante ao read, mas escrevendo até o número de bytes passados pelo parâmetro com base nos dados do buffer. |
| close | Fecha um dado descritor de arquivo aberto anteriormente, assim fazendo com que ele possa ser reutilizado e qualquer ligação que o arquivo com, ou possuída pelo processo, são removidas. |
| fstat | Retorna o status de um dado arquivo, sendo esse status informações sobre o arquivo, como permissão, id, inode, tamanho do bloco, grupo, etc. |
| lseek | Reposiciona o offset (em bytes) do arquivo para leitura/escrita, podendo ser a partir de um certo local especificado, o tamanho do arquivo ou a referência zero. |
| openat | Abre e, se necessário, cria um arquivo em um endereço dado. Podendo ser utilizado, portanto, em chamadas ao sistema subsequentes. |

## Tempo e Frequência de Chamadas ao Sistema

Por meio do comando `strace -c` é possível obter as seguintes saídas, que mostram o tempo de cada chamada ao sistema e a sua frequência em cada um dos programas.

// todo - colocar prints de cada execução

## Análise de Tempo de Execução

// todo - Utilizando time

```bash
$ time -f "Tempo total: %e\n
Percentual de uso de CPU: %P\n
Tempo em modo de Kernel: %S\n
Tempo em modo de usuário: %U\n
Trocas de contexto involuntárias: %c\n
Trocas de contexto voluntárias: %w\n" ./a.out
```

## Análise CPU/I-O Bound

// todo - Analisar com base no tempo obtido anteriormente