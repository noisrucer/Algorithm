//Topological sort - BFS
class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(v);
        queue<int>Q;
        vector<int>degree(v,0);
        int cnt=v;
        
        for(auto &edge: prerequisites){
            adj[edge[1]].push_back(edge[0]);
           degree[edge[0]]++;
        }
        
        for(int i=0; i<v; i++)
            if(!degree[i]) Q.push(i); 
       
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop(); cnt--;
            for(auto child: adj[cur]){
                if(!--degree[child]) Q.push(child);
            }
        }
       
        return cnt==0;
        
        
    }
};