#include<stdio.h>
#include "heap.h"

HEAP createHeap(){
	HEAP H;
	H.size=0;
	for(int i=0;i<100;i++){
		//not filled denoted by -1;
		// no use nut still may be alter gets in use
		H.array[i]=-1;
	}
	return H; //heap
}

// returns the minimum value in the heap H
int findMin(HEAP H){
	if(H.size==0){
		printf("Heap is empty.\n");
		return -1;
	}
	return H.array[0];  //min
}

int isFullHeap(HEAP H){
	if(H.size==100){
		return 1;
	}
	return 0;  //1 0
}

int isEmptyHeap(HEAP H){
	if(H.size==0){
		return 1;
	}
	return 0; //1 0
}

//deletes the minimum value from the heap
HEAP extractMin(HEAP H){
	// what if heap is empty
	if(isEmptyHeap(H)){
		printf("Heap is empty\n");
		return H;
	}

	// if size is 1
	if(H.size==1){
		H.array[0]=-1;
		(H.size)--;
		return H;
	}

	H.array[0]=H.array[H.size-1];
	H.array[H.size-1]=-1;
	int index=0;
	int left=index*2+1;
	int right=left+1;

	(H.size)--;
	while(left<H.size ){//heapify
		int swap=left;
		if(right<H.size){
			if(H.array[right]<H.array[left]){
				swap=right;
			}
		}
		if(H.array[index]>H.array[swap]){
			int temp=H.array[index];
			H.array[index]=H.array[swap];
			H.array[swap]=temp;

			index=swap;
			left=2*index+1;
			right=2*index+2;
		}else{
			break;
		}
	}

	
	return H;  //HEAP
}

//inserts the value k in the heap H,
HEAP insertHeap(HEAP H,int k){
	// heap is full
	if(isFullHeap(H)){
		printf("No space is left in Heap\n");
		return H;
	}

	// if empty
	if(H.size==0){
		H.array[0]=k;
		(H.size)++;
		return H;
	}

	int index=H.size;
	H.array[index]=k;
	int parent=(index-1)/2;
	
	//swapping values if parent node has a larger value than its cild
	while(H.array[parent]>H.array[index] && index>0){//heapify
		int temp=H.array[parent];
		H.array[parent]=H.array[index];
		H.array[index]=temp;
		index=parent;
		parent=(index-1)/2;
	}
	(H.size)++;

	return H;  //HEAP;
}

void printHeap(HEAP H){
	printf("Size:%d\tArray: ",H.size);
	for(int i=0;i<H.size;i++){
		printf("%d ",H.array[i]);
	}
	printf("\n");
}
