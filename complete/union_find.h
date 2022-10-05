
// }typedef(NODE_PTR);
#include "defs.h"

// data structure will store only sets of only non negative integers
struct UNION_FIND{
	int size;
	int max_size;
	NODE_PTR *nodes;
}typedef(UNION_FIND);
NODE_PTR createNodeptr(int );
UNION_FIND createUF(int );
UNION_FIND makeSetUF(UNION_FIND ,int ,int *);
NODE_PTR findUF(UNION_FIND ,int );
void unionUF(UNION_FIND ,int , int );
void printUnion_Find(UNION_FIND );
