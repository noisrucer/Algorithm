class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        //1st version - adj with set
        vector<unordered_set<int>>adj(n);
        vector<int>res;
        queue<int>Q;
        for(auto &edge: edges){
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        
        for(int i=0; i<n; i++){
            if(adj[i].size()==1) Q.push(i);
        }
        
        while(n>2){
            int size = Q.size();
            n-=size;
            for(int i=0; i<size; i++){
                auto cur = Q.front(); Q.pop();
                for(auto &child: adj[cur]){
                    adj[child].erase(cur);
                    if(adj[child].size()==1) Q.push(child);
                }
            }
        }
        
        while(!Q.empty()){
            res.push_back(Q.front());
            Q.pop();
        }
        
        return res;
    }
};