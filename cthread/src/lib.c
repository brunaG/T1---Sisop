
#include <stdio.h>
#include <string.h>
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/escalonador.h"
#define ERROR -9;
#define SUCCESS 0;

#define TAMANHO_PILHA SIGSTKSZ

//Threads

//Contexto
ucontext_t threadTerminada;
ucontext_t contextoYield;


int ccreate (void* (*start)(void*), void *arg, int prio) {

	//Inicializa o escalonador
	InitEscalonador();

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
	return ERROR;
}

int cjoin(int tid) {
	return ERROR;
}

int csem_init(csem_t *sem, int count) {
	return ERROR;
}

int cwait(csem_t *sem) {
	return ERROR;
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
