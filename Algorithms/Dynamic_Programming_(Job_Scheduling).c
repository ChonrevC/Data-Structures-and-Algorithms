#include <stdio.h>
#include <stdlib.h>

/* This is for solving leetcode problem 1235: Maximum Profit in Job Scheduling
Steps:
	1. Make a struct that has the job qualities
	2. initialize the jobs array filled with struct jobs
	3. put the information in all the arrays in the parameter of the initial method into the jobs array
	4. create a method that prints out the jobs array
	5. Create a method that compares the end times of 2 jobs
	6. quicksort (qsort) the jobs in the jobs array
*/

struct job {
	int start;
	int end;
	int value;
	int previous; 							// p(i) in the slides [The index of last job that doesn't overlap in array of sorted time]
};

// Create a method that prints the qualities of each job in the jobs array
void printJob(struct job* jobs, int N) {
	printf("idx, start, end, value, previous\n");
	for(int k = 0; k < N; k++)
	{
		printf("%3d, %5d, %5d, %5d, %5d\n", k, jobs[k].start, jobs[k].end, jobs[k].value, jobs[k].previous);
	}
}

// create a method that returns a comparison of the end times of 2 jobs
int compare(const struct job* a, const struct job* b) {
	return a->end - b->end;
}

// create a method that assigns the previous value in jobs[k]
void set_prev(struct job* jobs, int k) {
	int t = k-1;
	while(k > 0 && jobs[k].start < jobs[t].end)
	{
		t--;
	}
	jobs[k].previous = t;
}

// The initial method
// 	> startTime, endTime, and profit are all arrays
int jobScheduling(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int* profit, int profitSize) {
	
	int N = endTimeSize;
	struct job jobs[N+1];					// create an array for the jobs sorted by end time
	
	// create a special/extra job 0 with (0, 0, 0, -1)
	jobs[0].start = 0;
	jobs[0].end = 0;
	jobs[0].value = 0;
	jobs[0].previous = -1;
	
	// copy job data in jobs
	int k;
	for(k = 0; k < N; k++)
	{
		jobs[k+1].start = startTime[k];
		jobs[k+1].end = endTime[k];
		jobs[k+1].value = profit[k];
		jobs[k+1].previous = 0;				// we can't deal with previous just yet, so just make it 0
	}
	
	// print out the jobs in the jobs array
	printJob(jobs, N+1);
	
	// quicksort the jobs in the jobs array (qsort is built in)
	// 	compare here has no parameters, due to qsort requiring a pointer to the method rather than the method itself
	qsort(jobs, N+1, sizeof(struct job), compare);
	
	printJob(jobs, N+1);
	
	// Assign the previous value for each job in the jobs array
	for(k = 1; k <=N; k++)
	{
		set_prev(jobs, k);
	}
	
	printJob(jobs, N+1);
	
	// dynamic programming solution
	int solution[N+1];
	solution[0] = 0;
	
	for(k = 1; k <= N; k++)
	{
		int withK = jobs[k].value + solution[jobs[k].previous];		// the money we make with job k
		int withoutK = solution[k-1];								// the money we make without job k
		
		solution[k] = fmax(withK, withoutK);						// add to the solutions array the max of the money we make
	}
	
	return solution[N];
	
}

