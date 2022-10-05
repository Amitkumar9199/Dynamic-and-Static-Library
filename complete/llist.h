// struct NODE{
// 	int value;
// 	int size;
// 	struct NODE *next ;
// }typedef(NODE);
// typedef NODE * NODE_PTR;
#ifndef LLIST_H
#define LLIST_H
#include "defs.h"
typedef struct LLIST{
	int length;
	NODE *head;
}LLIST;

LLIST createList();
int searchList(LLIST ,int );
LLIST insertAtFront(LLIST ,int );
LLIST insertAtEnd(LLIST ,int );
LLIST deleteFromFront(LLIST ,int *);
LLIST deleteFromEnd(LLIST ,int *);
LLIST deleteList(LLIST ,int );
void printList(LLIST );
#endif