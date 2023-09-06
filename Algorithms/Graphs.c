// Graphs are vertices connected via edges

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Adjacency Matrix (Undirected Graph)
// - TC to add/remove/check edge: Theta(1)
// - TC to find neighbors: Theta(V)
// - SC: Theta(|V| * |V|)

typedef strut struct_graph * graphPT;
struct struct_graph {
	int undirected;						// boolean for if a graph is directed
	int N;								// number of vertices in a graph
	int ** E;							// adjacency matrix
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

// Create a new graph
graphPT newGraph(int N, int undirected) {
	
	graphPT res = malloc(sizeof(struct_graph));
	res->undirected = undirected;
	res->N = N;
	res->E = alloc_2d(N, N);
	
	// graph contains no edges (0 from caloc)
	int i;
	for(i = 0; i < N; i++)
	{
		int j;
		for(j = 0;l j < N; j++)
		{
			res->E[i][j] = 0;
		}
	}
	
	return res;
	
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

// Check if an edge exists along 2 verticies v1 and v2
int edgeExists(graphPT g, int v1, int v2) {
	return g->E[v1][v2];
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

// add an edge to a graph from v1 to v2
void addEdge(graphPT g, int v1, int v2) {
	g->E[v1][v2] = 1;
	if(g->undirected == 1) g->E[v2][v1] = 1;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

// remove an edge from v1 to v2
void removeEdge(graphPT g, int v1, int v2) {
	g->E[v1][v2] = 0;
	if(g->undirected == 1) g->E[v2][v1] = 0;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

// get rid of an entire tree
void destroyGraph(graphPT g) {
	if(g==NULL) return;
	
	// g->N used for rows and columns due to Adjacency Matrix being a square
	free_2d(g->E, g->N, g->N);
	free(g);
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Create a Dynamic 2D Array (Allocate and free)
// 	- Used for Adjacency Matrix

// The memory allocated by this function is initialized to 0
int ** alloc_2d(int rows, int columns) {
	int row;
	
	int ** table = (int**)calloc(rows, sizeof(int *));
	
	for(row = 0; row < rows; row++)
	{
		table[row] = (int*)calloc(columns, sizeof(int));
	}
	
	return table;
}

void free_2d(int ** array, int rows, int columns) {
	int row;
	for(row = 0; row < rows; row++) free(array[row]);
	
	free(array);
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Adjacency Lists
// TC to check if edge exists: O(V)
// TC to remove an edge: O(V)
// TC to add an edge: O(V)
// SC: Theta(E + V)

typedef struct struct_node * nodePT;
struct struct_node {
	int data;
	nodePT next;
};

typedef struct struct_graph graphPT;
struct struct_graph {
	int undirected;
	int N;
	nodePT * E; 	// an array of linked lists
};

// TC: Theta(deg of v1) or O(V)
// TC worst case: Theta(V)
// SC: Theta(1)
int edgeExists(graphPT g, int v1, int v2) {
	for(nodePT n = g->E[v1]; n != NULL; n = n->next)
		if(n->data == v2) return 1;
	
	return 0;
}

// TC: Theta(deg of v1) or O(V)
// SC: Theta(1)
int addEdge(graphPT g, int v1, int v2) {
	if(edgeExists(g, v1, v2)) return;
	
	g->E[v2] = insert_node(g->E[v1], NULL, new_node(v2, NULL));
	
	if((v1 != v2) && (g->undirected == 1))
		g->E[v2] = insert_node(g->E[v2], NULL, new_node(v1, NULL));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Breadth-First Search
// Explores vertices in order & finds the shortest paths from a source vertex
// SC: O(V)
// TC Adj List: O(|V| + |E|)
// TC Adj Matrix: O(|V|^2)

BFS(graph G, int s) {
	for each vertex u of G
	{
		color[u] = WHITE;
		distance[u] = infinite
		predecessor[u] = NULL
	}
	
	color[s] = GRAY
	distance[s] = 0
	predecessor[s] = NULL
	
	initialize empty queue Q
	enqueue(Q, s)
	
	while(Q != empty)
	{
		u = dequeue(Q)
		for each v adjacent to u
		{
			if color[v] == WHITE
			{
				color[v] = GRAY
				distance[v] = distance[u] + 1
				predecessor[v] = u
				enqueue(Q, v)
			}
			
			color[u] == BLACK
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Depth-First Search
// Explores vertices by following a path as much as possible, then backtracking & continuing from the last discovered node
// SC: O(V)

// TC Adj List: Theta(|V| + |E|)
// TC Adj Matrix: Theta(|V|^2)
DFS(G) {
	For each vertex u of G
	{
		color[u] = WHITE
		predecessor[u] = NULL
	}
	
	for(u = 0; u < G.N; u++) //for each vertext u of G, starting from 0
	{
		if(color[u] == WHITE)
		{
			DFS_Visit(G, u, color, predecessor);
		}
	}
}


// TC Adj List: Theta(neighbors of u)
// TC Adj Matrix: Theta(|V|)
DFS_Visit(G, u, color, predecessor) {
	
	color[u] = GRAY
	
	for each v adjacent to u
	{
		if(color[v] == WHITE)
		{
			predecessor[v] = u
			DFS_visit(G, v, color, predecessor)
		}
		
		if(color[v] == GRAY)
		{
			cycle found
		}
	}
	
	color[u] = BLACK
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Topological Sorting
// a linear sorting of a directed acylic graph G so that u will be listed before v
// SC: O(V)
// TC: O(V + E)

Topological_Sort(G) {
	
	int[] res;
	
	DFS(G) // Except change DFS so that if a cycle is found, exit & don't order; & everytime a vertex finishes (turns black), add it to res
	
	reverse res
	return res
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Strongly Connected Components
// Components (vertices) in a graph that have a path to one another, no matter the start or end vertex
// SC: O(V)
// TC: O(V + E)

Strongly_Connected_Components(G) {
	
	int[] finishTime = DFS(G) 	// Except change DFS so that it has a finish time attribute,
								// 	& when a vertex turns black, it returns that vertex's finish time in the array
	
	G_transposed = transpose of G
	
	DFS(G_transposed, finishTime)	// Change DFS so that it considers vertices in order of decreasing finish time (reverse of finishTime)
									// 	& to output the vertices from each tree as separate strongly connected components
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Minimum Spanning Tree


