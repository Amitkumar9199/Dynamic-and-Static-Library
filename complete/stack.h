#include "llist.h"
struct STACK{
	int size;
	LLIST L;
}typedef(STACK);

STACK createStack();
int isEmptyStack(STACK S);
STACK push(STACK S,int k);
STACK pop(STACK S, int *k);
void printStack(STACK S);
