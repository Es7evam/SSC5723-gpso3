#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// buffer para inserção de informações
#define ITENS 20
int buffer[ITENS];
int ini_buffer = 0, fin_buffer = 0;

// criação de duas thread
pthread_t thr_produtor, thr_consumidor;

// semaforo de posições
sem_t pos_livre;
sem_t pos_ocupada;


//funções produtor x consumidor
void* produtor(void *p);
void* consumidor(void *p);


int main(int argc, char *argv[]) {

  // Inicializa os semáforos com as posições do buffer
  sem_init(&pos_livre, 0, ITENS);
  sem_init(&pos_ocupada, 0, 0);

  // Cria as threads de produtor e consumidor
  pthread_create(&thr_produtor, NULL, produtor, NULL);
  pthread_create(&thr_consumidor, NULL, consumidor, NULL);

  // Thread principal espera a thread produtor e consumidor acabarem 
  pthread_join(thr_produtor, NULL);
  pthread_join(thr_consumidor, NULL);

  // destroy os semáforos
  sem_destroy(&pos_livre);
  sem_destroy(&pos_ocupada);

  return 0;
}

// Função Produtor
void* produtor(void *p) {
  int i;

  //Região critica
  for (i = 0; i < ITENS; i++) {
    sem_wait(&pos_livre);
    printf("Produtor, processo = %d.\n", i);
    fin_buffer = (fin_buffer + 1) % ITENS;
    buffer[fin_buffer] = i;
    sem_post(&pos_ocupada);
    sleep(random() % 3);
  }
  return NULL;
}

// Função Consumidor
void* consumidor(void *p) {
  int i;

  // região critica
  for(i = 0; i < ITENS; i++){
    sem_wait(&pos_ocupada);
    ini_buffer = (ini_buffer + 1) % ITENS;
    printf("Consumidor, processo = %d.\n", buffer[ini_buffer]);
    sem_post(&pos_livre);
    sleep(random() % 3);
  }
  return NULL;
}

