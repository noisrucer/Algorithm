// DFS Solution
class Solution {
public:
    vector<int>visited;
    bool dfs(vector<vector<int>>&adj, int &n, int cur, int &target){
        if(visited[cur]) return false;
        if(cur == target) return true;
        visited[cur] = true;
        bool res = false;
            
        for(auto neighbor: adj[cur]){
            if(dfs(adj,n,neighbor,target)) return true;
        }
        
        // visited[cur] = false; 
        // We don't need this because if there's no path from a node, then it's game-over for that node. 
        // There's no way that you can revisit this node and make a path later out of nowhere!
        return false;
        
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        visited.resize(n, false);
        vector<vector<int>>adj(n);
        
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        
        return dfs(adj,n,start,end);
    }
};

// BFS Solution
class Solution {
public:
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>>adj(n);
        
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int>visited(n, false);
        queue<int>Q;
        Q.push(start);
        
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            visited[cur] = true;
            if(cur == end) return true;
            
            for(auto neighbor: adj[cur]){
                if(visited[neighbor] == true) continue;
                Q.push(neighbor);
            }
        }
        
        return false;
    }
};
