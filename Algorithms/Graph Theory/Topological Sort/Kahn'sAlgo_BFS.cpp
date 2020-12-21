class Solution {
public:
    vector<int>res;
    void topo(vector<vector<int>>&adj, queue<int>Q, vector<int>indegree){
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            res.push_back(cur);
            for(auto &j: adj[cur]){
                if(!--indegree[j]) Q.push(j);
            }
        }
    }
    
    
    bool isCycle(vector<vector<int>>&adj, queue<int>Q, vector<int>indegree){
        int cycle_cnt = indegree.size();
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            cycle_cnt--;
            for(auto &j: adj[cur]){
                if(!--indegree[j]) Q.push(j);
            }
        }
        
        return cycle_cnt;
    }
    
    vector<int> findOrder(int v, vector<vector<int>>& pre) {
        vector<vector<int>>adj(v);
        vector<int>indegree(v,0);
        queue<int>Q;
        
        for(auto &course: pre){
            adj[course[1]].push_back(course[0]);
            indegree[course[0]]++;
        }
        
        for(int i=0; i<v; i++)
            if(indegree[i]==0) Q.push(i);
        
        if(isCycle(adj,Q,indegree)) return {};
        
        topo(adj,Q,indegree);
        return res;
        
        
    }
};