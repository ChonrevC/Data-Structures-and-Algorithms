/*
	Chonrev Cal
	
	Time Complexity to compute edit distance from test word to dictionary word: O(T * MAX_LEN * D)
	Time Complexity to search for a word in the dictionary: O(D * MAX_LEN)
		- T = mispelled words in the text file
		- D = Number of words in the dictionary
		- MAX_LEN = max length of chars
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "spell.h"

/*  Suggestions
- When you work with 2D arrays, be careful. Either manage the memory yourself, or
work with local 2D arrays. Note C99 allows parameters as array sizes as long as 
they are declared before the array in the parameter list. See: 
https://www.geeksforgeeks.org/pass-2d-array-parameter-c/

Worst case time complexity to compute the edit distance from T test words
 to D dictionary words where all words have length MAX_LEN:
Student answer:  Theta(............)


Worst case to do an unsuccessful binary search in a dictionary with D words, when 
all dictionary words and the searched word have length MAX_LEN 
Student answer:  Theta(............)
*/


/* You can write helper functions here */
//////////////////////////////////////////////////////////////////////////////////
//Part 1 Helper Functions

//Function for finding the minimum of a trio of values
int min(int a, int b, int c) {
	if(a <= b && a <= c) return a;
	if(b <= a && b <= c) return b;
	if(c <= a && c <= b) return c;
}

//////////////////////////////////////////////////////////////////////////////////
// Part 2 Helper Functions

//Compare function for qsorting strings
int string_compare(const void *a, const void *b) {
	
	const char* string1 = (const char*)a;
	const char* string2 = (const char*)b;
	
	return strcmp(string1, string2);
}

int binarySearch(int size, char dictionary[][255], char *toFind, int *count, int printOn) {
	int low = 0;
	int mid;
	int high = size - 1;
	*count = 0;
	
	while(low <= high)
	{
		*count = *count + 1;
		
		mid = (low + high) / 2;
		
		if(strcmp(dictionary[mid], toFind)==0)
		{	
			if(printOn) printf("dict[%d] = %s\n\n", mid, dictionary[mid]);
				
			return mid;
		}
		
		else if(strcmp(dictionary[mid], toFind) > 0)
		{
			high = mid - 1;
			
			if(printOn) printf("dict[%d] = %s\n", high+1, dictionary[high]);
		}
		
		else if(strcmp(dictionary[mid], toFind) < 0)
		{
			low = mid + 1;
			
			if(printOn) printf("dict[%d] = %s\n", low-1, dictionary[low]);
		}
	}
	
	if(printOn) printf("Not found\n\n");
	
	return -1;
}

int minDistance(int distances[], int size) {
	int min = 999;
	
	int i;
	for(i = 0; i < size; i++)
	{
		if(distances[i] < min)
		{
			min = distances[i];
		}
	}
	
	return min;
}

//////////////////////////////////////////////////////////////////////////////////
/*
Parameters:
first_string - pointer to the first string (displayed vertical in the table)
second_string - pointer to the second string (displayed horizontal in the table)
print_table - If 1, the table with the calculations for the edit distance will be printed.
              If 0 (or any value other than 1)it will not print the table
(See sample run)
Return:  the value of the edit distance (e.g. 3)
*/
int edit_distance(char * first_string, char * second_string, int print_table){
	
	
	// create a distance 2D array
	int distance[strlen(first_string)+1][strlen(second_string)+1];
	
	// Compute edit distance for both strings
	int i, j;
	for(i = 0; i < strlen(first_string)+2; i++)
	{
		for(j = 0; j < strlen(second_string)+2; j++)
		{
			if(i==0 && j ==0) distance[0][0] = 0;
			else if(i==0) distance[0][j] = 1 + distance[0][j-1];
			else if(j==0) distance[i][0] = 1 + distance[i-1][0];
			else
			{
				if(first_string[i-1] == second_string[j-1])
				{
					distance[i][j] = min(distance[i-1][j]+1, distance[i][j-1]+1, distance[i-1][j-1]);
				}
				else
				{
					distance[i][j] = min(distance[i-1][j]+1, distance[i][j-1]+1, distance[i-1][j-1]+1);
				}
			}
		}
	}
	
	// Print the table
	if(print_table ==1)
	{
		printf("\n");
		int i, j, k;
	
		for(i = 0; i < strlen(first_string)+2; i++)
		{
			for(j = 0; j < strlen(second_string)+2; j++)
			{
				if(i==0 && j==0)
				{
					printf(" |  ");
				}
				
				else if((i==0 && j==1) || (i==1 && j==0))
				{
					printf(" |  ");
				}
				
				else if(i==0)
				{
					printf("%c|  ", second_string[j-2]);
				}
				
				else if(j==0)
				{
					printf("%c|  ", first_string[i-2]);
				}
				
				else
				{
					printf("%d|  ", distance[i-1][j-1]);
				}
				
			}
			
			printf("\n--");
			for(k = 0; k < strlen(second_string)+1; k++) printf("----");
			printf("\n");
		}
		printf("\n");
	}
	
	return distance[i-2][j-2];
}
	  

/*
Parameters:
testname - string containing the name of the file with the paragraph to spell check, includes .txt e.g. "text1.txt" 
dictname - name of file with dictionary words. Includes .txt, e.g. "dsmall.txt"
printOn - If 1 it will print EXTRA debugging/tracing information (in addition to what it prints when 0):
			 dictionary as read from the file	
			 dictionary AFTER sorting in lexicographical order
			 for every word searched in the dictionary using BINARY SEARCH shows all the "probe" words and their indices indices
			 See sample run.
	      If 0 (or anything other than 1) does not print the above information, but still prints the number of probes.
		     See sample run.
*/
void spell_check(char * testname, char * dictname, int printOn){
	
	// Check if files are proper file names
	FILE *inFile = fopen(testname, "r");
	if(inFile == NULL) 
	{
		printf("Cannot find \"%s\"\n", testname);
		return;
	}
	
	FILE *inDict = fopen(dictname, "r");
	if(inDict == NULL)
	{		
		printf("Cannot find \"%s\"\n", dictname);
		fclose(inFile);
		return;
	}
	
	
	// Ask for output file
	char outname[101];
	char c;
	
	printf("Corrected output filename: ");
	scanf("%s%c", outname, &c);
	
	FILE *outFile = fopen(outname, "w");
	if(outFile == NULL)
	{
		printf("Cannot find \"%s\"\n", outname);
		fclose(inFile);
		fclose(inDict);
		return;
	}
	
	
	// Get the size of the dictionary
	printf("\nLoading the dictionary file: %s\n\n", dictname);

	int size = 0;
	fscanf(inDict, "%d", &size);
	printf("Dictionary has size: %d\n", size);
	
	
	// Put the words from the dictionary into a 2D array
	char dictionary[size][255];
	
	int i, k;
	char line[255];
	for(i = 0; i < size; i++)
	{
		fscanf(inDict, "%s", line);
		if(printOn==1)
		{
			printf("\n%s\n", line);
		}
		strcpy(dictionary[i], line);
	}
	
	// show unsorted array
	if(printOn)
	{
		printf(" Original dictionary:\n");
		for(i = 0; i < size; i++)
		{
			printf("%d. %s\n", i, dictionary[i]);
		}
		printf("\n");
	}
	
	// qsort the dictionary 2D array
	qsort(dictionary, size, 255, string_compare);
	
	// show sorted array
	if(printOn)
	{
		printf(" Sorted dictionary (alphabetical order):\n");
		for(i = 0; i < size; i++)
		{
			printf("%d. %s\n", i, dictionary[i]);
		}
		printf("\n");
	}
	
	// Put the words from the text file into the output file
	while((fgets(line, 255, inFile)!=NULL)) {};
	
	char *token;					// token to separate strings in text file
	char separators[] = " ,.?!"; 	// separators for token
	
	int distances[size];			// array to keep edit distances
	
	int count = 0;					// words we look at during binary search
	char lineCopy[255];
	
	strcpy(lineCopy, line);
	
	token = strtok(line, separators);
	
	while(token != NULL)
	{
		int wordLength = strlen(token);
		
		char *lowerCase = (char*)malloc(sizeof(token));
		
		strcpy(lowerCase, token);
		
		for(i = 0; i < wordLength; i++)
		{
			lowerCase[i] = tolower(token[i]);
		}
		
		int index = binarySearch(size, dictionary, lowerCase, &count, printOn);
		
		if(index != -1)
		{
			printf("---> |%s| (words compared when searching: %d)\n", token, count);
			printf("     - OK\n\n");
			
			fprintf(outFile, "%s", token);
		}
		
		else
		{
			printf("---> |%s| (words compared when searching: %d)\n", token, count);
			printf("-1 - type correction\n");
			printf(" 0 - leave word as is (do not fix spelling)\n");
			
			for(i = 0; i < size; i++)
			{
				distances[i] = edit_distance(lowerCase, dictionary[i], 0);
			}
			
			// Find the minimum edit distance
			int min = minDistance(distances, size);
			
			printf("     Minimum distance: %d (computed edit distances: %d)\n", min, size);
			printf("     Words that give minimum distance:\n");
			
			// Print the words with the minimum distance
			k = 1;
			for(i = 0; i < size; i++)
			{
				if(distances[i] == min)
				{
					printf(" %d - %s\n", k, dictionary[i]);
					k++;
				}
			}
			
			// Create an array of the words with the minimum distance
			char minDistWords[k][255];
			int numOfOptions = k;
			
			k = 0;
			for(i = 0; i < size; i++)
			{
				if(distances[i] == min)
				{
					strcpy(minDistWords[k], dictionary[i]);
					k++;
				}
			}
			
			int input;
			char correction[255];
			
			printf("Enter your choice (from the above options: ");
			scanf("%d", &input);
			
			if(input == -1)
			{
				printf("Enter correct word: ");
				scanf("%s", correction);
				
				fprintf(outFile, "%s", correction);
			}
			
			else if(input == 0)
			{
				fprintf(outFile, "%s", token);
			}
			
			else
			{
				if(input > 0 && input < numOfOptions)
				{
					fprintf(outFile, "%s", minDistWords[input - 1]);
				}
				
				else
				{
					printf("Choice out of range\n");
					return;
				}
			}
		}
		
		char *symbol = strstr(lineCopy, token);
		symbol += strlen(token);
		
		if(strcmp(symbol, "\0") != 0)
		{
			fprintf(outFile, "%c", symbol[0]);
		}
		
		if(strcmp(symbol, "\0") != 0 && *(symbol + 1) == ' ')
		{
			fprintf(outFile, "%c", symbol[1]);
		}
		
		printf("\n");
		
		token = strtok(NULL, separators);
		free(lowerCase);
		
	} // while(token != NULL)
	
	
	// close all files
	fclose(inDict);
	fclose(inFile);
	fclose(outFile);
	
}

