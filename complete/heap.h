
struct HEAP{
	int size;
	int array[100];
}typedef(HEAP);


HEAP createHeap();
int findMin(HEAP );
int isFullHeap(HEAP);
int isEmptyHeap(HEAP);
HEAP extractMin(HEAP);
HEAP insertHeap(HEAP ,int );
void printHeap(HEAP );
