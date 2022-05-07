//Bellman Ford
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        const int INF = 1e6;
        vector<int>dist(n,INF);
        dist[src]=0;
        K++; if(K==n) K--;
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

//Dijkstra & Priority Queue - modified(다시)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto f: flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0,src,K+1});
        
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            int cost = cur[0];
            int node = cur[1];
            int cnt = cur[2];
          
            
            if(node==dst) return cost;
            
            if(cnt>0){
                for(auto next: adj[node]){
                    pq.push({cost+next.second,next.first,cnt-1});
                }
            }
            
        }
          return -1; 
    }
};