#include <stdlib.h>
#include <stdio.h>


#include "merge_k.h"  // includes list.h


/*  Sorts linked list L in pace using insertion sort. 
*/

/*
typedef struct node * nodePT;  // POINTER to NODE (memory address of NODE)
struct node {
    int data;
    struct node * next;  // it is the same as: nodePT next;
};
*/

nodePT sort_list(nodePT L){
	// implement insertion sort for linked list
	
	nodePT current = L;
	nodePT nextNode;
	
	nodePT newL = (nodePT)malloc(sizeof(struct node));
	newL->next = NULL;
	
	nodePT prev = newL;
	
	while(current != NULL)
	{
		while(prev->next != NULL && prev->next->data < current->data)
		{
			prev = prev->next;
		}
		nextNode = current->next;
		current->next = prev->next;
		prev->next = current;
		current = nextNode;
		
		prev = newL;
	}
	
	return newL->next;
}

/* It is recommended to implement a sinkDown function in this file. 
You can declare its header at the top of this file (after include) 
write the implementation anywhere in this file. 
(You cannot modify any of the list.h or merge_k.h files) 
*/

void sinkDown(nodePT A[], int p, int N) {
	int left = 2*p;
	int right = (2*p)+1;
	int imv = p;
	if((left <= N) && (A[left] > A[imv])) {imv = left;}
	if((right <= N) && (A[right] > A[imv])) {imv = right;}
	
	while(imv != p && imv <= N)
	{
		nodePT temp = A[p];
		A[p] = A[imv];
		A[imv] = temp;
		
		p = imv;
		left = 2*p;
		right = (2*p)+1;
		if(left <= N && A[left] > A[imv]) {imv = left;}
		if(right <= N && A[right] > A[imv]) {imv = right;}
	}
}

/* Turns the given array (named heap) into an actual Min-Heap
   using the bottom-up method to build the heap. 
   (See buidMaxHeap pseudocode in slides)
*/
void make_heap(int k, nodePT heap[]){
	// write your code in here
	
	int p;
	
	for(p = k/2; p >= 1; p--) {sinkDown(heap, p, k);}
	
}



/*  heap is a Min-Heap of linked lists
	remove_min will remove AND RETURN the first node of the list at index 0.
	k (size of heap) will only change when that removal leaves that list empty.
*/
nodePT remove_min(int* k, nodePT heap[]){
	
	nodePT min = heap[0];
	heap[0] = heap[(*k)];
	(*k) = (*k) - 1;
	
	sinkDown(heap,0,*k);
	
	return min;
	
}


/*
Input
   heap - is a Min-Heap array of SORTED single linked lists. 
   k - size of array heap. The first item is at index 0
   debug - debug on/off:
			if debug is 1, student code should print debugging information as well: heap and sorted result list
			if debug is 0, it does not print debugging infomation. 
			if debug is anything but 1, it does not print debugging infomation.
Returns: a sorted single linked list built by merging the k lists.

Algorithm
   Merging process: 
	- use the heap to identify and remove the node, np, with the smallest data out 
      of the k lists.
	- insert np at the end of result list.
*/
nodePT merge_k(int k, nodePT heap[], int debug){
	
	nodePT result = NULL;
	nodePT* tail = &result;
	nodePT* nextNode;
	
	int i;
	for(i = 0; i < k; ++i)
	{
		if(heap[i] == NULL)
		{
			heap[i--] = heap[--k];
		}
	}
	if(debug==1)
	{
		while(k > 1)
		{
			nextNode = &heap[0];
			
			printf("-------------------- Sorted result list:\n");
			print_list_pointer(result);
			
			printf("---- HEAP (start) --------\n");
			for(i = 1; i < k; ++i)
			{
				if((*nextNode)->data > heap[i]->data)
				{
					nextNode = &heap[i];
				}
				
				print_list_pointer(heap[i]);
				
			}
			printf("---- HEAP (end) --------\n\n");
			
			*tail = *nextNode;
			*nextNode = (*nextNode)->next;
			tail = &(*tail)->next;
			
			if(*nextNode == NULL)
			{
				*nextNode = heap[--k];
			}
			
			if(k != 0)
			{
				*tail = heap[0];
			}
		}
		printf("---- HEAP (start) --------\n");
		
		printf("---- HEAP (end) --------\n");
		printf("Empty heap. no remove performed.\n");
	}
	
	else
	{
		while(k > 1)
		{
			nextNode = &heap[0];
			
			for(i = 1; i < k; ++i)
			{
				if((*nextNode)->data > heap[i]->data)
				{
					nextNode = &heap[i];
				}
				
			}
			
			*tail = *nextNode;
			*nextNode = (*nextNode)->next;
			tail = &(*tail)->next;
			
			if(*nextNode == NULL)
			{
				*nextNode = heap[--k];
			}
			
			if(k != 0)
			{
				*tail = heap[0];
			}
		}
	}
	
	return result;
	
}
