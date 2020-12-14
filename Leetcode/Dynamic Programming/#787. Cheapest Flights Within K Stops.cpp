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