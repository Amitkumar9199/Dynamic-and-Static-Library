#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

//function to create graph
GRAPH createGraph(int n,int m){
	GRAPH G;
	G.n=n;//nodes
	G.m=m;//edges
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			G.adjacency_matrix[i][j]=0; // 0 indicates no edge
		}
	}
	G.edge=(EDGE *)malloc(sizeof(EDGE)*m); // this will be specially used in krushal's algorithm
	return G;
}

GRAPH readGraph(char *FName){
	FILE * fPointer=fopen(FName,"r");  //reading file
	int n,m,u,v,w;
	printf("INPUT:\n");
	fscanf(fPointer,"%d",&n); // #nodes
	printf("%d\n",n);
	fscanf(fPointer,"%d",&m); // #edges
	printf("%d\n",m);
	
	GRAPH G=createGraph(n,m); 

	while(m--){
		fscanf(fPointer,"%d\t%d\t%d",&u,&v,&w); //edges
		printf("%d %d %d\n",u,v,w);
		G.adjacency_matrix[u][v]=w;
		G.adjacency_matrix[v][u]=w;
		G.edge[m].a=u;
		G.edge[m].b=v;
		G.edge[m].w=w;
	}

	fclose(fPointer);// close file
	return G;
}

//general dfs function using dfs
void DFS(GRAPH G){

	printf("DFS TRAVERSE: ");
	int visited[G.n];

	//initiating all vertexs as non visited
	for(int i=0;i<G.n;i++){
		visited[i]=0;
	}
	

	STACK S=createStack();//to store vertexs being traversed //FILO
	S=push(S,0);
	int count=0;
	while(isEmptyStack(S)==0){
		// printStack(S);
		int *x=(int *)malloc(sizeof(int));
		S=pop(S,x);
		if(visited[*x]==0){// visiting the node
			if(count==G.n-1){
				printf("%d ",*x);
			}else{
				printf("%d, ",*x);
			}
			visited[*x]=1;
			count++;
		}
		for(int i=0;i<G.n;i++){
			if(visited[i]==0 && G.adjacency_matrix[*x][i]!=0){ // if there exists a edge and new vertex is still to be visited
				S=push(S,i);
		 	}
		}
		if(count==G.n){// just a small check to fast the algorithm
			break;
		}
	}
	// printf("\n");
	// for(int i=0;i<G.n;i++){
	// 	printf("%d ,",visited[i]);
	// }

}

//general bfs function using queue
void BFS(GRAPH G){

	printf("BFS TRAVERSE: ");
	int visited[G.n];
	for(int i=0;i<G.n;i++){//initiating all vertexs as non visited
		visited[i]=0;
	}
	

	QUEUE Q=createQueue();// to get the FIFO
	Q=enqueue(Q,0);
	int count=0;
	while(isEmptyQueue(Q)==0){
		// printQueue(Q);
		int *x=(int *)malloc(sizeof(int));
		Q=dequeu(Q,x);
		if(visited[*x]==0){//visiting
			if(count==G.n-1){
				printf("%d ",*x);
			}else{
				printf("%d, ",*x);
			}
			visited[*x]=1;
			count++;
		}
		for(int i=0;i<G.n;i++){
			if(visited[i]==0 && G.adjacency_matrix[*x][i]!=0){// if there exists a edge and new vertex is still to be visited
				Q=enqueue(Q,i);
		 	}
		}
		if(count==G.n){
			break;
		}
	}
	// printf("\n");
	// for(int i=0;i<G.n;i++){
	// 	printf("%d ,",visited[i]);
	// }	
}

//functiont to sort edges according to weight
void sort_edge(EDGE edges[],int m){
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			if(edges[j].w<edges[i].w){
				EDGE temp=edges[i];
				edges[i]=edges[j];
				edges[j]=temp;
			}
		}
	}
}

//genral mst implemetation using krushals algorithm
void MST(GRAPH G){
	EDGE edges[(G.m)];
	for(int i=0;i<G.m;i++){
		edges[i].a=G.edge[i].a;
		edges[i].b=G.edge[i].b;
		edges[i].w=G.edge[i].w;
	}
	sort_edge(edges,G.m);

	//creating disjoint union for making sets
	UNION_FIND UF=createUF(G.n);

	int **index=(int **)malloc(sizeof(int *)*G.n);//this will store the indexs of vertexs
	
	//making all sets independent first
	for(int i=0;i<G.n;i++){
		index[i]=(int *)malloc(sizeof(int));
		UF=makeSetUF(UF,i,index[i]);
	}


	EDGE ans[G.m];int k=0;int sum=0;
	
	for(int i=0;i<G.m;i++){
		// printf("%d %d %d\n",edges[i].a,edges[i].b,edges[i].w);
		NODE_PTR a=findUF(UF,*index[edges[i].a]);
		NODE_PTR b=findUF(UF,*index[edges[i].b]);
		if(a->value!=b->value){ // if 2 vertexs have different parents then merge them and store the edge
			unionUF(UF,*index[edges[i].a],*index[edges[i].b]);
			sum+=edges[i].w;
			ans[k]=edges[i];
			k++;
		}
	}

	printf("\nEdges included in MST:\na\tb\tw\n");
	for(int i=0;i<k;i++){
		printf("%d\t%d\t%d\n",ans[i].a,ans[i].b,ans[i].w);
	}
	printf("SUM of weights: %d\n",sum);
}

