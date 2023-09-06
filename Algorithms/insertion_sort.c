#include <stdio.h>
#include <stdlib.h>

/*
Insertion sort is a sorting algorithm that sorts by moving the current idx down the arrays till it gets to an index it's higher than
- TC: O(N^2)
- SC: Theta(1)
- Stable
*/


void insertion_sort(int A[], int N) {
	int i, j, key;
	
	for(j = 1; j < N; j++)
	{
		key = A[j];
		i = j-1;
		while(i >= 0 && A[i] > key)
		{
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
	}
}

int main(void) {
	
	int A[] = {2, 7, 9, 3, 5, 1};
	
	int N = sizeof(A) / sizeof(A[0]);
	
	insertion_sort(A, N);
	
	int i;
	for(i = 0; i < N; i++)
	{
		printf("%d\n", A[i]);
	}
	
}
