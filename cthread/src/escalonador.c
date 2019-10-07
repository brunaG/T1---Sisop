#include <stdio.h>
#include <string.h>
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/escalonador.h"

#define APTO 1
#define EXCEUTANDO 2
#define BLOQUEADO 3
#define TAMANHO_PILHA SIGSTKSZ

TCB_t *executing = NULL;
ucontext_t *context = malloc(sizeof(ucontext_t));
int tid = 0;
csem_t csem;

int InitEscalonador()
{
    if (executing != NULL)
        return APTO;

    int status = 0;

    csem.count = 1;
    csem.fila = (PFILA2)malloc(sizeof(PFILA2));

    PFILA2 filaApto = PFILA2)malloc(sizeof(PFILA2));
    PFILA2 filaExecutando = PFILA2)malloc(sizeof(PFILA2));
    PFILA2 filaBloqueado = PFILA2)malloc(sizeof(PFILA2));

    CreateFila2(filaApto);
    CreateFila2(filaExecutando);
    CreateFila2(filaBloqueado);

    status += AppendFila2(cpuSem.fila, filaApto);
    status += AppendFila2(cpuSem.fila, filaExecutando);
    status += AppendFila2(cpuSem.fila, filaBloqueado);

    InitThreadMain();

    return status;
}

int GetTid()
{
    tid++;
}

void InitThreadMain()
{
    TCB_t * threadMain = (TCB_t *)malloc(sizeof(TCB_t));
    threadMain->tid = 0;
    threadMain->state = 1;
    threadMain->prio = 0;

    getcontext(&threadMain->context);

    threadMain->context.uc_link = &threadTerminada;
    threadMain->context.uc_stack.ss_sp = (char*) malloc(TAMANHO_PILHA);
    threadMain->context.uc_stack.ss_size = TAMANHO_PILHA;


    makecontext(&threadMain->context, (void (*)(void))start, 1, arg);

    executing = threadMain;
}
