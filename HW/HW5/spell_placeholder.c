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
	const char& string2 = (const char*)b;
	
	return strcmp(string1, string2);
}

int find_edit_distance(char * first_string, char * second_string) {
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
	
	// return the edit distance
	return distance[i-2][j-2];
	
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
	
	return distance[i-2][j-2];  // replace this line with your code
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
	if(outname == NULL)
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
	
	int k = 0;
	int i = 0;
	for(i = 0; i < size; i++)
	{
		k = 0;
		
		char r = fgetc(inDict);
		while((r != ',' || r != ' ') && !feof(inDict))
		{
			dictionary[i][k] = r;
			k++;
			r = fgetc(inDict);
		}

		//printf("%s\n", dictionary[i]); 				// test to see array
		if(feof(inDict)) break;
		
	}
	
	// qsort the dictionary 2D array
	qsort(dictionary, size, 255, string_compare);
	
	
	// Put the words from the text file into an array
	char sentence[255][255];
	
	i = 0;
	k = 0;
	while(!feof(inFile))
	{
		fscanf(inFile, "%c", &sentence[i][k]);
		// printf("%s", sentence[i]);  					// test to see array
		i++;
		if(feof(inFile)) break;
	}
	
	// begin loop to check each word in the sentence with dictionary
	int sizeOfSentence = sizeof(sentence) / sizeof(sentence[0]);
	printf("%d\n", sizeOfSentence);
	for(i = 0; i < sizeOfSentence; i++)
	{
		
		// binary search
		int binaryIdx = -1;
		int searchCount = 1;
		int low = 0;
		int high = size;
		while(low < high)
		{
			searchCount++;
			int mid = (low + high) / 2;
			
			if(strcasecmp(sentence[i], dictionary[mid]) == 0) binaryIdx = mid;
			
			else if(strcasecmp(sentence[i], dictionary[mid]) > 0)
			{
				high = high;
				low = mid + 1;
			}
			
			else
			{
				low = low;
				high = mid - 1;
			}
		}
		
		
		printf("---> | %s | (words compared when searching: %d\n", sentence[i], searchCount);
		
		printf("binary index = %d\n", binaryIdx);
		
		/*
		// begin outputting options
		if(binaryIdx != -1) printf("     -OK\n\n\n");
		else
		{
			printf("-1 - type correction\n 0 - leave word as is (do not fix spelling)\n");
			
			int minDistance = 999;
			char minWords[255][255];
			// compute edit distances
			for(k = 0; k < size; k++)
			{
				if(minDistance > find_edit_distance(sentence[i], dictionary[k]))
				{
					
				}
			}
		}
		*/
	} //i = each word in the sentence
	
	
	// Close all files
	fclose(inDict);
	fclose(inFile);
	fclose(outname);
	
}

