/*
	FIFO (First-in-First-out) queues are just a list
	Similar to stacks, except while Stacks are First-in-Last-out, Queues are FIFO
	
	get TC: O(1)
	get SC: O(1)
	put TC: O(1)
	put SC: O(1)
*/


// create a Linked-List FIFO Queue
typedef struct node * nodePT
struct queue_list {
	nodePT firstD;						// dummy
	nodePT last;
	int size;
};

// create an Array FIFO Queue
typedef int Item;
struct queue_array {
	int capacity;
	int size;
	int first_index;
	int last_index;
	Item * items;
};


// put an item into an array queue
int put(struct queue_array * Q, Item val) {
	
	if(Q->size == Q->capacity)
	{
		return 0;
	}
	
	if(Q->size == 0)
	{
		Q->first_index = 0;
		Q->last_index = 1;
		
		Q->items[Q->last_index] = val;
	}
	
	else
	{
		Q->items[last_index] = val;
		Q->last_index = (Q->last_index + 1)%Q->Capacity
	}
	
	Q->size++;
	return 1;
	
}


// get an item from an array queue
int get(struct queue_array * Q, Item* ret) {
	
	if(Q->size == 0)
	{
		return 0;
	}
	
	*ret = Q->items[Q->first_index];
	
	Q->first_index = (Q->first_index)%Q->capacity;
	Q->size--;
	
	return 1;
	
}

