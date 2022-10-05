#ifndef DEFS_H
#define DEFS_H
struct NODE{  
	int value;
	int size;// size only used in union_find.c 
	struct NODE *next;
}typedef(NODE);

typedef NODE * NODE_PTR; // only used in union_find.c
#endif