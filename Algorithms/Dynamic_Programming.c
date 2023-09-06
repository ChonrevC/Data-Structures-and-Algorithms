#include <stdio.h>
#include <stdlib.h>

// These are approaches for solving Dynamic Programming Problems


// Bottom Up (iterative)
// 	Creates and populate an array solution, corresponding to the sol function from the math definition
// 			Math Definition:
// 					sol(0) = 0
// 					sol(i) = max[sol(i-1), v(i) + sol(p(i))]
// 	TC: Theta(N)
// 	SC: Theta(N)
int js_iter(int* v, int* p, int n) {
	int j, with_j, without_j;
	int solution[n+1];
	
	solution[0] = 0; //-1 also works here for safety
	
	for(j = 1; j <= n; j++)
	{
		with_j = v[j] + solution[p[j]];
		without_j = solution[j-1];
		
		if(with_j >= without_j) solution[j] = with_j;
		else solution[j] = without_j;
	}
	return solution[n];
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Iterative, bottom up, linear version of Fibonacci Numbers

int Fib_iter(int i) {
	int F[i+1];
	F[0] = 0; F[1] = 1;
	
	int k;
	for(k = 2; k <= i; k++)
	{
		F[k] = F[k-1] + F[k-2];
	}
	return F[i];
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Exponential version of Fibonacci Numbers

int Fib(int i) {
	if(i < 1) return 0;
	if(i == 1) return 1;
	
	return Fib(i-1) + Fib(i - 2);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Recursive (Inefficient)
// 		for later


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Memoization (Top down) (Recursion combined with saving)
// 		for later


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



