#include <stdio.h>
#include <string.h>
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/escalonador.h"

#define APTO 1
#define EXCEUTANDO 2
#define BLOQUEADO 3

TCB_t *executing = NULL;
ucontext_t *context = malloc(sizeof(ucontext_t));
int tid = 0;
csem_t csem;

int SchedulerInitializer()
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

    //inicializar a thread main

    return status;
}

int GetTid()
{
    tid++;
}
