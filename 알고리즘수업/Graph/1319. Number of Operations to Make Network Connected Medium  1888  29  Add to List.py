class Solution:
    def __init__(self):
        # Initialize Data Structures
        self.adj = defaultdict(list)
        self.visited = None
        self.connected_components = 0
        
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        num_edges = len(connections)
        
        # Check if there're enough edges to form a connected undirected graph -> at least n-1
        # Graph Theory - A tree(same as connected undirected graph) has exactly "n-1" edges. Why?
        # Each node has only ONE parent, EXCEPT the root node. Therefore, n-1
        # If we have n nodes, then n-1 edges will make a "tree" or a connected graph.
        # n-1 is the "minimum" number of edges required to form a connected undirected graph
        is_enough_edges = True if num_edges >= n - 1 else False
        if not is_enough_edges:
            return -1
        
        # Construct visited array
        self.visited = [False] * n
    
        # Construct Adjacency List 
        for c in connections:
            self.adj[c[0]].append(c[1])
            self.adj[c[1]].append(c[0])
        
        # Perform BFS to find # of connected components
        for node in range(n):
            if not self.visited[node] and len(self.adj[node]): # not visited yet & has edges
                self.DFS(node)
                self.connected_components += 1
        
        # Find the number of 
        num_unconnected_nodes = n - sum(self.visited) # using True(1), False(0)
        
        # Think about why this formula?
        # [1] First, we need to connect the unconnected nodes using MINIMUM edge moves -> again, n-1 to make a tree
        # [2] Then, we need to connect the sub-graph we just connected to ALL THE OTHER CONNECTED COMPONENTS -> how many edges need? Ans) # of connected components
        return (num_unconnected_nodes - 1) + self.connected_components
    
    # BFS Solution
    def BFS(self, cur_node):
        Q = []
        Q.append(cur_node)
        self.visited[cur_node] = True
        
        while(len(Q)):
            cur = Q.pop(0)
            
            for v in self.adj[cur]:
                if self.visited[v]:
                    continue
                    
                Q.append(v)
                self.visited[v] = True
          
    # DFS Solution
    def DFS(self, cur_node):
        if self.visited[cur_node]:
            return None
        
        self.visited[cur_node] = True
        
        for v in self.adj[cur_node]:
            self.DFS(v)