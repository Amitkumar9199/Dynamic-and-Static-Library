#include<stdio.h>
#include "stack.h"
STACK createStack(){
	STACK S;
	S.size=0;
	S.L=createList();
	return S;
}

int isEmptyStack(STACK S){
	if(S.size==0){
		return 1;
	}else{
		return 0;
	}
}

STACK push(STACK S,int k){
	S.L=insertAtFront(S.L,k);
	(S.size)++;
	return S;
}

STACK pop(STACK S, int *k){
	S.L=deleteFromFront(S.L,k);
	(S.size)--;
	return S;
}
void printStack(STACK S){
	printf("SIZE: %d\t: ",S.size);
	printList(S.L);
}
