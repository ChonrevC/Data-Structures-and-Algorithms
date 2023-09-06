/*
Stacks & Queues are data ty[es that store a set of objects
They can be implemented via linked lists or arrays

push TC = O(1)
push SP = O(1)
pop TC = O(1)
pop SP = O(1)
*/


// Defining a stack
typedef int Item;
struct stack_array {
	
	Item * items;
	int top;			// index of last item
	int capacity;		// how many items there are

};


// Creating a new stack
struct stack_array newStack(int size) {
	
	struct stack_array new;								// initialize new stack_array struct
	
	new.items = (Item*)malloc(size*sizeof(Item));		// Makes space for ints to be contained in the stack
	
	res.capacity = size;								// makes the capacity of the stack the max amount of items being held in the stack
	res.top = -1; 										// index starts at -1 to show empty array
	return res;
	
}


// push an object into a stack (add it)
void push(struct stack_array * myStack, Item newItem) {
	
	if(myStack->top == myStack->capacity-1)
	{
		printf("Stack full\n");
	}
	
	else
	{
		myStack->top++;									// increases the index of the last item
		myStack->item[myStack->top] = newItem;			// adds the new item into the stack via the items pointer
	}
	
}


// pop an object from a stack (remove it)
Item pop(struct stack_aray myStack) {
	
	if(myStack->top == -1)
	{
		printf("Stack empty\n");
	}
	
	else
	{
		Item temp = myStack->items[myStack->top];		// create an Item variable that holds the value of the item about to be popped
		myStack->top--;									// decrement the index of the last item
		
		return temp;									// return the new Item variable & pop that
	}
	
}





