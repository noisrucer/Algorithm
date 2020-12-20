class Solution {
public:
    
    int minCost = INT_MAX;
    void dfs(vector<vector<pair<int,int>>>&adj, int curr, int k, int cost, int &dst){
        if(curr==dst){
            minCost = min(minCost, cost);
            return;
        }

        if(k<1) return;
        for(auto &i: adj[curr]){
            if(cost+i.second>=minCost) continue;
            dfs(adj,i.first,k-1,cost+i.second,dst);
        }
   
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &flight: flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        dfs(adj,src,K+1,0,dst);
        return minCost==INT_MAX?-1:minCost;
    }
};