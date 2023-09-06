#include <stdio.h>
#include <stdlib.h>

/*
Linked Lists are data structures that are a list of structs called "nodes" that contain a data value & a pointer to the next node
Single linked lists are lists that connect to the main code via a pointer that points to the first node
SC: O(1)
*/

// format for creating a node struct
struct node {
	int data;
	struct node * next;
};
// calling the pointer that points to the linked list, as well as the part of the node that connects to the next node, a nodePT
typedef struct node * nodePT;


//========================================================================
//========================================================================


// create & return a linked list with data from array A
nodePT list_from_array(int N, int A[]) {
	
	if(N==0)
	{
		return NULL;
	}
	
	nodept head, lastP, newP;									// create node pointers for the head, the last pointer created, and a new pointer created
	
	head = (struct node *)malloc(sizeof(struct node));			// initialize the first node with malloc
	head->data = A[0];											// have the first node's data be A[0]
	head->next = NULL;											// have the first node's pointer point to nothing at first
	
	lastP = head;												// have the last pointer created be the head
	
	int i;
	for(i = 1; i < N; i++)										// go through the array
	{
		newP = (struct node *)malloc(sizeof(struct node));		// initialize the next node with newP 
		newp->data = A[i];										// have the new node's data be A[i]
		newP->next = NULL;										// have the new node's pointer point to nothing at first
		
		lastP->next = newP;										// have the last pointer created point to the new node
		lastP = newP;											// the last pointer created was the new pointers
																/*===========================================================================
																|	Note that since lastP & newP are just pointers, the actual values of 	|
																|	the nodes won't change, since we're changing the pointers,				|
																|	not the actual nodes													|
																============================================================================*/
	}
	
	return head;												// return the pointer that points to the linked list (head)
	
}


//========================================================================
//========================================================================


// create and return a new linked list that holds a copy of the data from the linked list L
nodePT list_from_list(nodePT L) {
	
	nodePT copy_head, lastP, newP, nextP;
	
	copy_head = (struct node *)malloc(sizeof(struct node));
	copy_head->data = L->data;
	copy_head->next = NULL;
	
	lastP = copy_head;
	
	nextP = L->next;
	
	while(nextP->next != NULL)
	{
		newP = (struct node *)malloc(sizeof(struct node));
		newP->data = nextP->data;
		newP->next = nextP->next;
		
		nextP = nextP->next;
		
		lastP->next = newP;
		lastP = newP;
	}
	
	return copy_head;
	
}


//========================================================================
//========================================================================


// delete a list & free all nodes from it
void destroy_list(nodePT L) {
	
	nodePT next;							// create a pointer that points to the next node in the list
	nodePT currentP = L;					// create a pointer that points to the head
	
	while(currentP != NULL)					// while there are still nodes in the list
	{
		next = currentP->next;				// have the next pointer point to the next node in the list
		free(currentP);						// delete the pointer that points to the head
		currentP = next;					// move the pointer for deletion to the next node
	}
	
}


//========================================================================
//========================================================================


// reverses a list
nodePT reverse(nodePT L) {
	
	nodePT prevP = NULL, currP = L, nextP = NULL; 	// a previous pointer, a current pointer that points to what the head is pointing to, & a next pointer
	
	while(currP != NULL)							// while there are still nodes in the linked list
	{
		nextP = currP->next;						// have the next pointer point to what comes next in the list
		currP->next = prevP;						// have the pointer of the node currP is pointing to switch from the head to the previous pointer
		prevP = currP;								// have the previous pointer point equal the structure in currentP (initial data & the pointer to the previous pointer
		currP = nextP;								// have the currP pointer equal the nextP pointer (the data & pointer in the next node in the list)
	}
	
	L = prevP;										// have the head L equal the previous pointer's structure
	
	return L;
	
}


//========================================================================
//========================================================================


// remove duplicated from the linked list (assume linked list is in increasing order)
nodePT deleteDuplicates(nodePT L) {
	
	if(L==NULL)
	{
		return NULL;
	}
	
	nodePT currP, nextP, temp;
	
	currP = L;
	nextP = L->next;
	
	while(nextP != NULL)
	{
		if(currP->val == nextP->val)
		{
			temp = nextP;
			currP->next = nextP->next;
			nextP = nextP->next;
			free(temp);
		}
		else
		{
			currP = nextP;
			nextP = nextP->next;
		}
	}
	
	return L;
	
}


//========================================================================
//========================================================================


// remove from the list the first node that has value val in it
nodePT deleteByValue(nodePT L, int val) {
	
	if(L = NULL)
	{
		return NULL;
	}
	
	nodePT currP = L;
	nodePT nextP = L->next;
	
	if(L->data == val)
	{
		free(L);
		L = nextP;
		return L;
	}
	
	nodePT temp;
	
	while(nextP != NULL)
	{
		if(nextP->data == val)
		{
			temp = nextP;
			currP = nextP;
			nextP = nextP->next;
			free(temp);	
		}
		else
		{
			currP = nextP;
			nextP = nextP->next;
		}
	}
	
	return L;
	
}

