#include<stdio.h>
#include<stdlib.h>
#include "llist.h"


LLIST createList(){
	LLIST l;
	l.length=0;
	l.head=NULL;
	return l;
}

//search a node in list
int searchList(LLIST H,int k){
	NODE *temp=H.head;
	while(temp!=NULL){
		if(temp->value==k){
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}

//inserts a node in the front
LLIST insertAtFront(LLIST H,int k){
	NODE *temp=(NODE *)malloc(sizeof(NODE));
	temp->value=k;
	temp->next=H.head;
	H.head=temp;
	(H.length)++;
	return H;
}

//inserts a node in the end
LLIST insertAtEnd(LLIST H,int k){

    NODE *temp=(NODE *)malloc(sizeof(NODE));
    temp->value=k;
    temp->next=NULL;

    // if its the first element
    if(H.length==0){
        H.head=temp;
        (H.length)++;
        return H;
    }

    // finding last node 
    NODE *NEXT=H.head;
    for(int i=0;i<H.length-1 && NEXT!=NULL;i++){
        NEXT=NEXT->next;
    }
    NEXT->next=temp;
    (H.length)++;
    return H;
}

//deldete front element
LLIST deleteFromFront(LLIST H,int *k){
	// if there are no nodes
	if(H.length==0){
		return H;
	}
	*k=H.head->value;
	// node next to the deleted node
	NODE *temp=H.head->next;
	free(H.head);
	H.head=temp;
	(H.length)--;
	return H;
}

//delete last element
LLIST deleteFromEnd(LLIST H,int *k){
	// if there are no nodes
	if(H.length==0){
		return H;
	}
	//position of node to be deleted
	int index=H.length-1;
	NODE *temp=H.head;
	for(int i=0;i<index-1 && temp!=NULL;i++){
		temp=temp->next;
	}
	//getting value
	*k=temp->next->value;
	
	//pointer to next node(deleted)
	NODE *Next=temp->next->next;
	free(temp->next);
	temp->next=Next;
	(H.length)--;
	return H;
}

//delete a particular element
LLIST deleteList(LLIST H,int k){
	//if linked list is empty
	if(H.length==0){
		return H;
	}

	NODE *temp=H.head;
	//find index of node to be deleted 
	int pos=0;int index=-1;
	while(temp!=NULL){
		if(temp->value==k){
			index=pos;break;
		}
		pos++;
		temp=temp->next;
	}
	// if no such node exist
	if(index==-1){
		return H;
	}
	temp=H.head;
	// find previous node of the node to be deleted
	for(int i=0;i<index-1 && temp!=NULL;i++){
		temp=temp->next;
	}
	// if position is more than no of nodes
	if(temp==NULL || temp->next==NULL){
		return H;
	}

	//pointer to next node(deleted)
	NODE *Next=temp->next->next;
	free(temp->next);
	temp->next=Next;
	(H.length)--;
	return H;
}

void printList(LLIST H)
{
	NODE *temp=H.head;
    while ( temp!= NULL) {
        printf("%d ",temp->value);
        temp = temp->next;
    }
    printf("\n");
}
