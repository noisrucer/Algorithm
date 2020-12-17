class Solution {
public:
    vector<bool>visit;
    
    bool isCycle(vector<vector<int>>&adj, int v, int cur){
        if(visit[cur]) return true;
        visit[cur]=true;
        for(auto &child: adj[cur]){
            bool FLAG = isCycle(adj, v, child);
            if(FLAG) return true;
        }
        visit[cur]=false;
        
        return false;
    }
    
    bool helper(vector<vector<int>>&adj, int v){
        for(int i=0; i<v; i++){
            visit[i]=true;
            for(auto &child: adj[i]){
            bool FLAG = isCycle(adj,v,child);
            if(FLAG) return true;
            }
            visit[i]=false;
        }
        
        return false;
    }
    
    bool canFinish(int v, vector<vector<int>>& pre) {
        vector<vector<int>>adj(v);
        visit.resize(v,false);
        
        for(auto &course: pre){
            adj[course[1]].push_back(course[0]);
        }
        
        return !helper(adj,v);
        
        
        
    }
};