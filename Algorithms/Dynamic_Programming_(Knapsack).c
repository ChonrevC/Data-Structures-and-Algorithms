
#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Unbounded Knapsack
// TC: Theta(nW)
// SC: Theta(W)

/* W = max capacity(weight), n = the amount of items we can pick, v = values, w = weights of all items */
int knapsack(int W, int n, int * v, int * w) {
	
	int solution[W+1]; int picked[W+1];
	solution[0] = 0;
	
	int k;
	for(k = 1; k <= W; k++)
	{
		int mx = 0; int choice = -1;
		
		int i;
		for(i = 0; i < n; i++)
		{
			if(k >= w[i])
			{
				int with_i = v[i] + sol[k-w[i]];
				
				if(mx < with_i)
				{
					mx = with_i;
					choice = i;
				}
			}
		}
		solution[k] = mx; picked[k] = choice;
	}
	
	return solution[W];
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 0/1 Knapsack
// TC: Theta(nW)
// SC: Theta(nW)

int knapsack01(int W, int n, int * v, int * w) {
	
	int solution[n+1][W+1];
	
	int i, k;
	for(k = 0; k <= W; k++)
	{
		solution[0][k] = 0;
	}
	
	for(i = 1; i <= n; i++)
	{
		for(k = 0; k <= W; k++)
		{
			solution[i][k] = solution[i-1][k];
			if(k > w[i])
			{
				int with_i = v[i] + solution[i-1][k-w[i]];
				
				if(solution[i][k] < with_i)
				{
					solution[i][k] = with_i;
				}
			}
		}
	}
	
	return solution[n][W];
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

