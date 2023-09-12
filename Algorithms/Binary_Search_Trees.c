/*
Binary search trees are special sorts of heaps where all nodes on the left are always less than or equal to the parent nodes
	and the nodes on the right are always greater than or equal to the parent nodes
*/


typedef struct node * nodePT
struct node {
	
	int data;
	nodePT left;
	nodePT right;
	
};


// Searches for a specific node via value in a tree
// N = number of nodes in the tree (or tree height)
// TC best case: Theta(1)
// TC worst case: O(N)
nodePT search(nodePT tree, int s_data) {
	
	if(tree == NULL) return null;
	
	else if(s_data == tree->data) return tree;
	
	else if(s_data < tree->data) return search(tree->left, s_data);
	
	else return search(tree->right, s_data);
	
}


// inserts an item by traveling down the tree until finding a leaf position appropriate for insertion

nodePT insert(nodePT h, int n_data) {
	
	if(h == NULL) return new_tree(n_data);
	
	else if(n_data < h->data) h->left = insert(h->left, n_data);
	
	else if(n_data > h->data) h->right = insert(h->right, n_data);
	
	return h;
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Leetcode problem 102: Convert Sorted Array to Binary Search Tree														//
// Turn a sorted array into a Binary Search Tree																		//
																														//
nodePT helper(int* nums, int left, int right) {																			//
	// base case (return if start is bigger than end)																	//
	if(left > right) return NULL;																						//
																														//
																														//
	int middle = (left + right) / 2;								// find the middle of the subset of the array		//
	nodePT nodeReturn = malloc(sizeof(struct node));				// initialize a nodePT to return					//
																														//
	nodeReturn->data = nums[m];										// make the data of the node to return the middle	//
	nodeReturn->left = helper(num, left, m-1);						// return the nodePT of the subset to the left		//
	nodeReturn->right = helper(num, m+1, right);					// return the nodePT of the subset to the right		//
																														//
	return nodeReturn;												// return the root of the new tree					//
}																														//
																														//
nodePT sortedArrayToBST(int* nums, int numSize) {																		//
																														//
	return helper(nums, 0, numSize-1);								// return the root of the new tree					//
																														//
}																														//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Leetcode Problem 102 Medium: Binary Tree Level Order Traversal														//
// Given the root of a binary tree, return the level order traversal of its nodes' values.								//
																														//
//	THIS CODE IS DONE IN JAVA!!!																						//
																														//
public List<List<Integer>> levelOrder(TreeNode root) {																	//
        LinkedList<TreeNode> nodes = new LinkedList<>();																//	
        List<List<Integer>> res = new LinkedList<List<Integer>>();														//
																														//
        if(root==null) return null;																						//
																														//	
        nodes.add(root);																								//
        while(nodes.size() != 0)																						//
        {																												//
																														//
            LinkedList<Integer> L = new LinkedList<>();																	//
																														//
            for(int k = nodes.size(); k > 0; k--)																		//
            {																											//
                TreeNode curr = nodes.poll();																			//
																														//
                // System.out.printf("%d, ", curr.val);																	//
                L.add(curr.val);																						//
																														//
                if(curr.left != null) nodes.add(curr.left);																//
                if(curr.right != null) nodes.add(curr.right);															//
            }																											//
																														//	
            res.add(L);																									//
																														//
        }																												//
																														//
        System.out.print(res);																							//
        return res;																										//
}																														//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Used for below:
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Leetcode Problem 1008: Construct Binary Search Tree from Preorder Traversal
// Given an array of integers preorder, construct the binary tree and return its root.

struct TreeNode* helper(int* arr, int left, int right) {
    
    if(left > right) return NULL;
    
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    root->val = arr[left];
    
    int k = left + 1;
    while((k <= right) && arr[k] < arr[left])
    {
        k++;
    }
    
    // k is 1+last index of element from left subtree
    root->left = helper(arr, left + 1, k-1);
    root->right = helper(arr, k, right);
    
    return root;
    
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    return helper(preorder, 0, preorderSize-1);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Leetcode Problem 226: Invert Binary Tree
// Given the root of a binary tree, invert the tree & return its root

void invert(struct TreeNode* root) {
	
	if(root == NULL) return;
	
	struct TreeNode* temp = root->left;
	
	root->left = root->right;
	root->right = temp;

	invert(root->left);
	invert(root->right);
	
	return;
	
}

struct TreeNode* invertTree(struct TreeNode* root) {
	
	invert(root);
	
	return root;
	
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Leetcode Problem 100: Same Tree
// Given the roots of 2 binary trees p & q, check if they are the same or not

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	
	if(p==NULL && q==NULL)
	{
		return true;
	}
	
	if(p==NULL || q==NULL)
	{
		return false;
	}
	
	if(p->val != q->val)
	{
		return false;
	}
	
	return isSameTree(p->left, q->left) && isSameTree(p->right && q->right);
	
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Leetcode Problem 112: Path Sum
// Given the root of a binary tree & an integer, targetSum, return true if the tree has a root-to-leaf path
// 		such that adding up all the values along the path equals targetSum

bool hasPathSum(struct TreeNode* root, int targetSum) {
	
	if(root == NULL)
	{
		return false;
	}
	
	if(targetSum == root->val)
	{
		if(root->left == NULL && root->right == NULL)
		{
			return true;
		}
	}
	
	if((hasPathSum(root->left, targetSum - root-> val)) || (hasPathSum(root->right, targetSum - root->val)))
	{
		return true;
	}
	
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Leetcode Problem 548: Convert BST to Greater Tree
// Given the root of a BST, convert it to a Greater Tree such that every key of the original BST is changed to the
// 		original key plus the sum of all keys greater than the original key in BST

struct TreeNode* solve(struct TreeNode* root, int sum) {
	
	if(root) {
		solve(root->right);
		
		sum = root->val += sum;
		
		solve(root->left);
	}
	
	return root;
	
}

struct TreeNode* convertBST(struct TreeNode* root) {
	
	int sum = 0;
	
	return solve(root, sum);
	
}

