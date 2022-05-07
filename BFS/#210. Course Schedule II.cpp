class Solution {
public:
    int cnt;
    vector<bool>visit;
    vector<int>res;
    
    void dfs(vector<vector<int>>&adj, int curr){
        if(visit[curr]) return;
        visit[curr]=true;
        
        for(auto child: adj[curr])
             dfs(adj,child);
        
        res[cnt--]=curr;
        return;
    }
    
    bool isCycle(int v, vector<vector<int>>&adj,vector<int>&degree){
        queue<int>Q;
        int cycle_cnt=v;
        
        for(int i=0; i<v; i++)
            if(degree[i]==0) Q.push(i);
        
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop(); cycle_cnt--;
            for(auto child: adj[cur]){
                if(!--degree[child]) Q.push(child);
            }
        }
        
        return cycle_cnt;
    }
    
    vector<int> findOrder(int v, vector<vector<int>>& pre) {
        cnt=v-1;
        vector<vector<int>>adj(v);
        visit.resize(v,false);
        res.resize(v);
        vector<int>degree(v,0);
        
        for(auto edge: pre){
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
        }
        
        if(isCycle(v,adj,degree)) return {};
        
        for(int i=0; i<v; i++){
            if(visit[i]) continue;
            visit[i]=true;
            for(auto child: adj[i])
                dfs(adj,child);
            res[cnt--]=i;
        }
        
        return res;
    }
};