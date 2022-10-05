#include<stdio.h>
#include<stdlib.h>
#include "union_find.h"
NODE_PTR createNodeptr(int value){
	NODE_PTR nptr=(NODE *)malloc(sizeof(NODE));
	// cout<<"OK";
	nptr->value=value;
	nptr->size=0;
	nptr->next=NULL;
	return nptr;
}
//create a UNION_FIND data structure that
//can store n node pointers. Initially, 
// all these pointers are NULL.
UNION_FIND createUF(int n){
	UNION_FIND UF;
	UF.size=0;
	UF.max_size=n;

	UF.nodes=(NODE_PTR *)malloc(n*sizeof(NODE_PTR));
	// cout<<"1";
	for(int i=0;i<n;i++){
		UF.nodes[i]=createNodeptr(-1);
		// cout<<i;
	}
	
	return UF;
}

// adding a node to UNION_NODE LIST/ARRAY
UNION_FIND makeSetUF(UNION_FIND F,int x,int *i){
	NODE_PTR nptr=createNodeptr(x);
	F.nodes[F.size]->next=nptr;
	*i=F.size;//index assigned
	(F.size)++;
	return F;
}

//finds parent of  a node
NODE_PTR findUF(UNION_FIND F,int i){
	NODE_PTR temp=F.nodes[i]->next;
	while(temp->next!=NULL){//loops goes untill it finds a node with no ancestor
		temp=temp->next;
	}
	return temp;
}

// fn to merge to node in a set
void unionUF(UNION_FIND F,int i, int j){
	NODE_PTR a=findUF(F,i);// parent 1
	NODE_PTR b=findUF(F,j);// parent 2
	if(a->size<=b->size){ // comapre sizes and merge smaller one into larger level
		b->next=a;
		a->size=a->size+1;
	}else{
		a->next=b;
		b->size=b->size+1;
	}
}

// debugging using printf
void printUnion_Find(UNION_FIND F){

	for(int i=0;i<F.size;i++){
		printf("index: %d::",i);
		NODE_PTR p=F.nodes[i];
		while(p->next!=NULL){
			printf("%d, ",p->value);
			p=p->next;
		}
		printf("%d \n",p->value);

	}
}
