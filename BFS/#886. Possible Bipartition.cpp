class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& graph) {
        vector<int>color(N+1,-1);
        vector<bool>visit(N+1,false);
        vector<vector<int>>adj(N+1);
        for(auto &i: graph){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        queue<int>Q;
        for(int i=1; i<=N; i++){
            if(visit[i]) continue;
            visit[i]=true;
            color[i]=0;
            Q.push(i);
            
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(auto &child: adj[cur]){
                    if(color[child]==-1){
                        color[child]=1-color[cur];
                        Q.push(child);
                        visit[child]=true;
                    }else{
                        if(color[cur]==color[child]) return false;
                    }
                }
            }
        }
        
        return true;
    }
};