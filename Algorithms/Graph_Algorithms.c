// Graphs are vertices connected via edges

//recall:
typedef strut struct_graph * graphPT;
struct struct_graph {
	int undirected;						// boolean for if a graph is directed
	int N;								// number of vertices in a graph
	int ** E;							// adjacency matrix
};

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
// Minimum Spanning Tree (Prim's Algorithm)
// a spanning tree (all vertices are connected in some way) & has the smallest total weight of edges in a group
// For Prim's algorithm, the graph is connected, undirected, & can have negative edge weights
// SC: O(V + E)
// TC Adj Matrix: O(ElgV)
// TC Adj List: O(ElgV)

MST_Prim(graph G, int[][] w, int s) {						// w is the 2D array that holds the weights between vertices
	
	int distance[N], predecessor[N]; 	// Let |V| = N
	
	for(v = 0; v < N; v++)
	{
		distance[v] = infinite
		predecessor[v] = -1
	}
	
	distance[s] = 0
	Q = priorityQueue(G.V, distance)
	
	while(Q != empty)
	{
		u = removeMin(Q, distance)
		
		for each v adjacent to u
		{
			if(v in Q && w(u, v) < distance[v])
			{
				predecessor[v] = u
				distance[v] = w(u, v)
				decreasedKeyFix(Q, v, d)
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Shortest Path Spanning Tree (Dijkstra's Algorithm)
// tree that contains s and all vertices reachable from s such that s is the root & each tree path from s to v is the shortest path in G from s to v
// 	all weights are non-negative
// SC: Theta(V)
// TC: O(ElgV)

Dijkstra(graph G, int[][] w, int s) {
	
	int distance[N], predecessor[N]
	
	for(v = 0; i < N; v++)
	{
		distance[v] = infinite
		predecessor[v] = -1
	}
	
	distance[s] = 0
	Q = PriorityQueue(distance)
	
	while(Q != empty)
	{
		u = removeMin(Q, distance)
		
		for each v adjacent to u
		{
			if(v in Q && (distance[u] + w[u][v]) < distance[v])
			{
				predecessor[v] = u
				distance[v] = distance[u] + w[u][v]
				decreasedKeyFix(Q, v, distance)
			}
		}
	}
	
}

