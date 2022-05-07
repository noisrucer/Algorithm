class Solution {
public:
    vector<vector<int>>res;
    
    void dfs(vector<vector<int>>&adj, vector<int>&path, int cur){
        path.push_back(cur);
        
        if(cur == adj.size() - 1) res.push_back(path);
        else for(int neighbor: adj[cur])
            dfs(adj, path, neighbor);
        
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        dfs(graph, path, 0);
        return res;
    }
};
