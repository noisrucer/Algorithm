class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Dijkstra's Algorithm with Priority Queue
        
        // Data Structures - Adj List / priority queue
        vector<vector<pair<int,int>>>adj(n+1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        
        // DS Initialization
        for(auto &t: times){
            adj[t[0]].push_back({t[1],t[2]});
        }
        
        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k}); // (cost, node)
        
        // Dijkstra's Algorithm
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            int minNode = cur.second;
            int minNodeCost = cur.first; // we don't use it cuz it's same as dist[minNode] but anyways
            
            for(auto &edge: adj[minNode]){
                int v = edge.first;
                int edgeCost = edge.second;
                // minNode -> (edgeCost) -> v
                // dist[minNode] + edgeCost < v ? update : leave it
                
                if(dist[minNode] + edgeCost < dist[v]){
                    dist[v] = dist[minNode] + edgeCost;
                    pq.push({dist[v], v});
                }
            }
        }
        
        int totalTime = *max_element(dist.begin()+1, dist.end());
        return totalTime == INT_MAX ? -1 : totalTime;
        
        
    }
};