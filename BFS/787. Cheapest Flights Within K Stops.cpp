//DFS + Pruning - O(V+(V~V^2))
class Solution {
public:
    
    int minCost = INT_MAX;
    void dfs(vector<vector<pair<int,int>>>&adj, int curr, int k, int cost, int &dst, vector<bool>&visit){
        visit[curr]=true;
        if(curr==dst){
            minCost = min(minCost, cost);
            return;
        }

        if(k<1) return;
        for(auto &i: adj[curr]){
            if(cost+i.second>=minCost) continue;
            dfs(adj,i.first,k-1,cost+i.second,dst,visit);
        }
        visit[curr]=false;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>>adj(n);
        vector<bool>visit(n,false);
        for(auto &flight: flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        dfs(adj,src,K+1,0,dst,visit);
        return minCost==INT_MAX?-1:minCost;
    }
};

//Bellman Ford - O(v^3)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        const int INF = 1e6;
        vector<int>dist(n,INF);
        dist[src]=0;
       K++;if(K==n) K--;
        for(int k=1; k<=K; k++){
            vector<int>temp(dist);
            for(auto flight: flights){
                if(dist[flight[0]]!=INF){
                    temp[flight[1]]=min(temp[flight[1]],dist[flight[0]]+flight[2]);
                }
            }
            dist=temp;
        }
        return dist[dst]==INF?-1:dist[dst];
    }
};