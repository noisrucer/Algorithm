class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        vector<bool>visit(n,false);
        queue<int>Q;
       
        for(int i=0; i<n; i++){
            if(visit[i]) continue;
             Q.push(i); color[i]=1;
       
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            visit[cur]=true;
            
            for(auto child: graph[cur]){
                if(color[child]==-1){
                    color[child]=1-color[cur];
                    Q.push(child);
                }
                else{
                    if(color[cur]==color[child]) return false;
                }
              }
           }
        }
        
        return true;
        }
};