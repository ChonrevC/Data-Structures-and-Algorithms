#include <stdio.h>
#include <stdlib.h>

/* 
Selection sort is a sorting algorithm
- goes through array, swapping current unsorted lowest w/ current index checked
- TC: Theta(N^2)
- SC: Theta(1)
- Not stable
*/

void selection_sort(int A[], int N) {
	int i, j, temp;
	for(j = 0; j < N-1; j++)
	{
		int min_idx = j;
		for(i = j+1; i < N; i++)
		{
			if(A[i] < A[min_idx])
			{
				min_idx = i;
			}
		}
		temp = A[min_idx];
		A[min_idx] = A[j];
		A[j] = temp;
	}
}

int main(void) {
	int A[] = {3, 5, 2, 7, 6, 9};
	
	int N = sizeof(A)/sizeof(A[0]);
	
	selection_sort(A, N);
	
	int i;
	
	for(i = 0; i < N; i++)
	{
		printf("%d \n", A[i]	);
	}
	
	return 0;
}
