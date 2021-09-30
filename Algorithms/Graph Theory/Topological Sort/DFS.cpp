class Solution {
public:
    int cnt;
    vector<int>res;
    void dfs(vector<vector<int>>&adj, vector<bool>&visit, int curr){
        if(visit[curr]) return;
        visit[curr] = true;
        
        for(auto &child: adj[curr]){
            dfs(adj,visit,child);
        }
        res[cnt--]=curr;
    }

    bool isCycle(vector<vector<int>>&adj,vector<int>&indegree){
         queue<int>Q;
        int cycle_cnt=indegree.size();
        
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i]==0) Q.push(i);
        }
        
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            cycle_cnt--;
            for(auto &child: adj[cur]){
                if(!--indegree[child]) Q.push(child);
            }
        }
        
        return cycle_cnt;
    }
    vector<int> findOrder(int v, vector<vector<int>>& pre) {
        vector<vector<int>>adj(v);
        vector<int>indegree(v,0);
        vector<bool>visit(v,false);
        
        
        for(auto &course: pre){
            adj[course[1]].push_back(course[0]);
            indegree[course[0]]++;
        }
        
        if(isCycle(adj,indegree)) return {};
        
        res.resize(v);
        cnt=v-1;
        
       for(int i=0; i<v; i++){
           if(visit[i]) continue;
           dfs(adj,visit,i);
       }
        
        
        return res; 
       
    }
    
};