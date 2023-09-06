#include <stdio.h>
#include <stdlib.h>

/* 
Selection sort is a sorting algorithm
- goes through array, swapping current unsorted lowest w/ current index checked
- TC: Theta(N^2)
- SC: Theta(1)
- Not stable
*/

/*
This file is about combining selection sort & insertion sort to make selection sort stable
*/

void selection_sort_stable(int A[], int N) {
	int i, j, temp;								// initialize the checker, the current, and the holder
	for(j = 0; j < N - 1; j++)					// loop through the current idx
	{
		int min_idx = j;						// make the minimum = the current
		for(i = j+1; i < N; i++)				// loop through & check all the indexes
		{
			if(A[i] < A[min_idx])				// if a checked index is less than the current index...
			{
				min_idx = i;					// make the minimum index = the checked index
			}
		}
		temp = A[min_idx];						// have the holder hold the value in the lowest checked index
		
		//Insertion Sort
		i = min_idx - 1;						// have the checker be the index before the lowest checked index
		while(i >= 0 && A[i] > temp)			// while the checker is greater than or equal to 0 and the checked index holds a value greater than the holder
		{
			A[i+1] = A[i];						// make the index after the checker hold the value of the checked index
			i--;								// decrement the checked index
		}
		A[i+1] = temp;							// go back up to the index that was last changed & give it the value of the holder
		
	}
	
}

int main(void) {
	int A[] = {3, 5, 2, 7, 6, 9};
	
	int N = sizeof(A)/sizeof(A[0]);
	
	selection_sort_stable(A, N);
	
	int i;
	
	for(i = 0; i < N; i++)
	{
		printf("%d \n", A[i]	);
	}
	
	return 0;
}
