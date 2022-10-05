#include "llist.h"
struct QUEUE{
    int size;
    LLIST L;
}typedef(QUEUE);


QUEUE createQueue();
int isEmptyQueue(QUEUE );
QUEUE enqueue(QUEUE ,int );
QUEUE dequeu(QUEUE ,int *);
void printQueue(QUEUE );
