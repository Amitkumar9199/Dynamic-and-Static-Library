#include<stdio.h>
#include "queue.h"

// all things implmentedd using llists // thus a single line code

//fn to create a queue
QUEUE createQueue(){
    QUEUE Q;
    Q.size=0;
    Q.L=createList();
    return Q;
}

//checks if queue is empoty
int isEmptyQueue(QUEUE Q){
    if(Q.size==0){
        return 1;
    }
    return 0;
}

//pushes a item in queue FIFO
QUEUE enqueue(QUEUE Q,int k){
    Q.L=insertAtEnd(Q.L,k);
    (Q.size)++;
    return Q;
}

//removes a item from queue  FIFO
QUEUE dequeu(QUEUE Q,int *k){
    Q.L=deleteFromFront(Q.L,k);
    (Q.size)--;
    return Q;
}


void printQueue(QUEUE Q){
    printf("Size: %d:\t",Q.size);
    printList(Q.L);
}
