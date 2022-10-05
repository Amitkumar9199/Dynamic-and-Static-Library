#include "llist.h"
#include "stack.h"
#include "queue.h"
#include "union_find.h"
struct EDGE{
	int a,b,w;		
}typedef(EDGE);

struct GRAPH{
	int n; //# nodes
	int m; //# edges

	int max_size;
	int adjacency_matrix[100][100];
	EDGE *edge;

}typedef(GRAPH);


GRAPH createGraph(int ,int );
GRAPH readGraph(char *);
void DFS(GRAPH );
void BFS(GRAPH );
void sort_edge(EDGE [],int );
void MST(GRAPH );