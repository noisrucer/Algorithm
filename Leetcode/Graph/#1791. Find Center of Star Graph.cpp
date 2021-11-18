class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>adj(n+2,0);
        
        for(vector<int>edge: edges){
            if(++adj[edge[0]] > 1) return edge[0];
            if(++adj[edge[1]] > 1) return edge[1]; 
        }
        
        return 0;
    }
};