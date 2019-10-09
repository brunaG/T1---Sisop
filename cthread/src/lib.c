
#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>
#include <string.h>

#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/escalonador.h"

#define ERROR -9;
#define SUCCESS 0;
#define TAMANHO_PILHA SIGSTKSZ

//Helper vars
bool escalonador = false;
int executando = -1 
int yield = 0;


//Contexto
ucontext_t threadTerminada;
ucontext_t contextoYield;


int ccreate (void* (*start)(void*), void *arg, int prio) {

	//Inicializa o escalonador
	InitEscalonador();
	escalonador = true;

	//Cria o objeto
	TCB_t * newThread = (TCB_t *)malloc(sizeof(TCB_t));
    newThread->tid = GetTid();
    newThread->state = 0;
    newThread->prio = prio;

	//Pegar o contexto
    getcontext(&newThread->context);

    newThread->context.uc_link = &threadTerminada;
    newThread->context.uc_stack.ss_sp = (char*) malloc(TAMANHO_PILHA);
    newThread->context.uc_stack.ss_size = TAMANHO_PILHA;


    makecontext(&newThread->context, (void (*)(void))start, 1, arg);

	return newThread->tid;
}

int cyield(void) {
    if(executando == -1){
        InitThreadMain(); //inicializa
        if(threadMain == -1){
            return -1;
        }
    }

    yield = 1;
    swapcontext(&executing->context,&contextoYield);

    return 0;
	
	return ERROR;
}

int cjoin(int tid) {
	return ERROR;
}

int csem_init(csem_t *sem, int count){


//inicializa e verifica o semafaro


	sem->count = count;
	sem->fila = (PFILA2) malloc(sizeof(FILA2));
	
	 verifica se o recurso esta ocopado.

	if (CreateFila2(sem->fila) == 0) {
    	return 0;
  	} else {
    	return  ERROR;
  	}
	
}

int cwait(csem_t *sem) {

    if (!escalonador)
        InitEscalonador();

    if(sem == null)
        return ERROR;

    if(sem->count > 0)
    {
        sem->count--;
        return SUCCESS;
    }

    if(sem->fila == null)
        return ERROR;

    //bloqueia a thread

	return SUCCESS;
}

int csignal(csem_t *sem) {
	return ERROR;
}

int cidentify (char *name, int size) {

	char *groupNames =
        "Luma Beserra Monteiro - 00268612"
        "Bruna Gonzaga - "
        "Roberta Robert - ";

	if (!strncpy(name, groupNames, size))
	{
	    return ERROR;
	}

	return SUCCESS;
}
