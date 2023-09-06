#include <stdio.h>
#include <stdlib.h>

/*
Heaps are arrays with special "order"
They can be organized via trees and max-heaps & min-heaps and etc.
The root node (top) of the tree must be the biggest, with each child being smaller or equal to the parent node, and the left child being smaller than the right
*/


/*
In all these:
A[] = array/heap
N = total nodes in heap
*/


// increases the priority of an item A[i] (useful for when an item is added to a heap)
// O(lg(N))
void swimUp(int A[], int i) {
	while(i > 1 && A[i] > A[i/2])
	{
		int temp = A[i/2]
		A[i/2] = A[i];
		A[i] = temp;
		i = i/2;
	}
}


// inserts newKey in A, & modifies N, a pointer to the amount of nodes in the heap
void insert(int A[], int newKey, int* N) {
	
	(*N) = (*N) + 1;
	int i = (*N);
	
	A[i] = newKey;
	while(i > 1 && A[i] > A[i/2])
	{
		int temp = A[i/2];
		A[i/2] = A[i];
		A[i] = temp;
		i = i/2;
	}
	
}

//returns the index of max value from a parent's (p's) left and right child
int idxOfMaxValue(int A[], int p, int left, int right, int N) {
	int imv = p;
	if(left <= N && A[left] > A[imv]) {imv = left;}
	if(right <= N && A[right] > A[imv]) {imv = right;}
	
	return imv;
}


// pushes down data starting from root p if needed, in a heap A with N nodes
// O(N)
void sinkDown(int A[], int p, int N) {
	int left = 2*p;
	int right = (2*p)+1;
	int imv = idxOfMaxValue(A, p, left, right, N);
	
	while(imv != p && imv <= N)
	{
		int temp = A[p];
		A[p] = A[imv];
		A[imv] = temp;
		
		p = imv;
		left = 2*p;
		right = (2*p)+1;
		imv = idxOfMaxValue(A, p, left, right, N);
	}
}


// removes the maximum node from heap
int removeMax(int A[], int* N) {
	mx = A[1];
	A[1] = A[(*N)];
	(*N) = (*N)-1;
	
	sinkdown(A, 1, *N);
	
	return mx;
}


//removes a non-root node p (p doesn't necessarily have to be the root this time)
// O(lgN)
int removeAny(int A[], int p, int *N) {
	int temp = A[p];
	A[p] = A[(*N)];
	(*N) = (*N)-1;
	
	if(A[p] > A[p/2]) {swimUp(A, p);}
	else if(A[p] < temp) {sinkDown(A, p, N);};
	
	return temp;
}

// O(N)
void buildMaxHeap(int A[], int N) {
	int p;
	
	for(p = N/2; p >= 1; p--) {sinkDown(A, p, N);}
}


// Won't go over heapsort this semester
// Theta(Nlg(N))
// Not Stable
void Heapsort(int A[], int N) {
	buildMaxHeap(A, N);
	
	int p;
	for(p = N; p >= 2; p==)
	{
		temp = A[p];
		A[p] = A[1];
		A[1] = temp;
		
		N = N - 1;
		
		sinkDown(A, 1, N);
	}
}

