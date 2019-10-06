
#include <stdio.h>
#include <string.h>
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/escalonador.h"
#define ERROR -9;
#define SUCCESS 0;

int ccreate (void* (*start)(void*), void *arg, int prio) {

	//Inicializa o escalonador
	SchedulerInitializer();

	//Cria o objeto
	TCB_t * newThread = (TCB_t *)malloc(sizeof(TCB_t));
    newThread->tid = GetTid();
    newThread->state = 0;
    newThread->prio = prio;

	//Pegar o contexto


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
