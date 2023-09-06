/*
QUICKSORT
- a divide and conquer technique (split, solve, combine)
- NOT adaptive
- DOES have a best/worst case

*/


// TC: Theta(N), N = end - start + 1
// SC: Theta(1)
int Partition(int[] A, int start, int end) {
	
	pivot = A[end];
	bigIdx = start;			// The 1st purple (> pivot)
	
	int j;
	for(j = start; j <= end-1; j++)
	{
		if(A[j] <= pivot)
		{
			int temp = A[j];
			A[j] = A[bigIdx];
			A[bigIdx] = temp;
			
			bigIdx++;
		}
	}
	
	int temp = A[bigIdx];
	A[bigIdx] = A[end];
	A[end] = temp;
	
	return bigIdx;
	
}


// BEST (Avg) TC: Theta(Nlg(N))
// WORST TC: Theta(N^2)
// BEST SC: lg(N) levels = Theta(lg(N))
// WORST SC: n levels = Theta(n)
void Quicksort(int[] A, int start, int end) {
	
	if(start >= end) return;
	
	int pIndex = Partition(A, start, end);
	
	Quicksort(A, start, pIndex-1);
	Quicksort(A, pIndex+1, end);
	
}


// Similar to Quicksort, except there's only one recursive call & it returns a value
// BEST (Avg) TC: O(N)
// WORST TC: O(N^2)
int QuickSelect(int k, int[] A, int start, int end) {
	
	int pIndex = Partition(A, start, end);
	
	if((k-1) == pIndex) return A[pIndex];
	
	else if((k-1) < pIndex) return QuickSelect(k, A, start, pIndex - 1);
	
	else return Quickselect(k, A, pIndex + 1, end);
	
}

