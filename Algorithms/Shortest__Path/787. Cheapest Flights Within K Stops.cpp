//TODO: #1 DFS 
class Solution {
public:
    int res = INT_MAX;
    int dest;
    vector<int>visited;
    void dfs(vector<vector<pair<int,int>>>&adj, int k, int cost, int cur){
        if(visited[cur]) return;
        visited[cur] = true;
        
        if(cur == dest){ // We reach destination
            res = min(res, cost);
            visited[cur] = false;
            return;
        }
        
        if(k <= 0){ // Must be after "if(cur == dest)" line, think why
            visited[cur] = false;
            return;
        }      
        
        for(auto &p: adj[cur]){
            if(cost+p.second >= res) continue; //pruning
            dfs(adj,k-1,cost+p.second,p.first);
        }
        
        visited[cur] = false;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // DFS
        // BFS
        // Dijkstra
        // DP
        // Bellman Ford
        dest = dst;
        vector<vector<pair<int,int>>>adj(n);
        visited.resize(n, false);
        for(auto &flight: flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        
        dfs(adj,k+1,0,src);
        
        return res == INT_MAX ? -1 : res;  
    }
};
