#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
int main(){
	char *input=(char *)malloc(sizeof(char)*255);
	scanf("%s",input);//input // name of the file.txt
	GRAPH G=readGraph(input);	
	printf("\n");
	DFS(G);
	printf("\n");
	BFS(G);
	printf("\n");
	MST(G);
	printf("\n");
	return 0;
}