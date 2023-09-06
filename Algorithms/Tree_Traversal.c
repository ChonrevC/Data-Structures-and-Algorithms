/*
Trees are nodes that are organized in a tree formation
There is a parent node, a left child node, and a right child node
The 1st node is the root node & the biggest node

Tree Traversal complexities with N nodes:
Time complexity: Theta(N)
Space complexity: Theta(tree_height)
*/

typedef struct node * nodePT
struct node {
	int data;
	nodePT left;
	nodePT right;
};

void preorder_traversal(nodePT h) {
	
	if(h==NULL) {return;}
	
	printf("%d, ", h->data);
	preorder_traversal(h->left);
	preorder_traversal(h->right);
	
}


void inorder_traversal(nodePT h) {
	
	if(h==NULL) {return;}
	
	inorder_traversal(h->left);
	printf("%d, ", h->data);
	inorder_traversal(h->right);
	
}


void postorder_traversal(nodePT h) {
	
	if(h==NULL) {return;}
	
	postorder_traversal(h->left);
	postorder_traversal(h->right);
	printf("%d, ", h->data);
	
}


// Count the number of nodes in a tree
int count(nodePT h) {
	
	if(h==NULL) {return 0;}
	
	int c1 = count(h->left);
	int c2 = count(h->right);
	
	return c1 + c2 + 1;
	
}


// compute the height of a tree
int height(nodePT h) {
	
	if(h==NULL) {return -1;}
	
	int u = height(h->left);
	int v = height(h->right);
	
	if(u>v) {return u+1;}
	else {return v+1;}
	
}

/*
for these next 2 methods, struct node is this:

struct node {
	char item;
	nodePT left;
	nodePT right;
};
*/
// print the content of each node
void print_node(char c, int depth) {
	
	int i;
	for(i = 0; i < depth; i++)
	{
		printf(" ");
	}
	printf("%c\n", c);
	
}


void show(nodePT x, int depth) {
	
	if(x==NULL)
	{
		printnode('*', depth);
		return;
	}
	
	printnode(x->item, depth);
	show(x->left, depth+1);
	show(x->right, depth+1);
	
}


// level-order traversal (traverses the tree via each level from left to right
// Time complexity: O(N)
// Space complexity: Theta(N)
void traverse(nodePT h) {
	
	Queue Q = new Queue();
	
	put(Q, h);
	
	while(!(empty(Q)))
	{
		h = get(Q);
		printItem(h->item);
		
		if(h->left != NULL) {put(Q, h->left);}
		if(h->right != NULL) {put(Q, h->right);}
	}
	
	return;
	
}


