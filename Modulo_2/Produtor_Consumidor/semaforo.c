#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "buffer.c"

// threads produtor e consumidor
pthread_t thr_produtor;
pthread_t thr_consumidor;

// semaforos
static sem_t exclusao;
static sem_t vazio_slot;
static sem_t cheio_slot;

//funções produtor x consumidor
void*produtor(void *p);
void*consumidor(void *p);

int main(int argc, char*argv[]){
	// cria o buffer
	buffer buf;
	inicializa_buffer(&buf);
	
  	// Inicializa os semáforos com as posições do buffer
	sem_init(&exclusao,0,1);
	sem_init(&cheio_slot,0,0);
	sem_init(&vazio_slot,0,ITENS);
	
  	// Cria as threads de produtor e consumidor
	pthread_create(&thr_produtor,NULL,produtor,&buf);
	pthread_create(&thr_consumidor,NULL,consumidor,&buf);

  	// Thread principal espera a thread produtor e consumidor acabarem 
	pthread_join(thr_produtor, NULL);
  	pthread_join(thr_consumidor, NULL);

	// destroy os semáforos
	sem_destroy(&exclusao);
	sem_destroy(&cheio_slot);
	sem_destroy(&vazio_slot);
	
	return 0;
}

// Função Produtor
void* produtor(void *p){
	int data=0;
  	// região critica
	for(int i = 0; i < ITENS; i++){
		data++;
		sem_wait(&vazio_slot);
		sem_wait(&exclusao);
    		printf("Produtor, processo = %d.\n", i);
		insere_buffer(data,p);
		sem_post(&exclusao);
		sem_post(&cheio_slot);
    	sleep(random() % 3);
	}
}

// Função Consumidor
void* consumidor(void *p){
	int data;
  	// região critica
	for(int i = 0; i < ITENS; i++){
		sem_wait(&cheio_slot);
		sem_wait(&exclusao);
		remove_buffer(&data,p);
    		printf("Consumidor, processo = %d.\n", data);
		sem_post(&exclusao);
		sem_post(&vazio_slot);
    		sleep(random() % 3);
	}
}
