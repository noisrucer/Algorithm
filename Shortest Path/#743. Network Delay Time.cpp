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


// Dijkstra's without priority queue
class Solution {
public:
    int getMinNode(vector<int>&dist, vector<int>&visited){
        int minNode = -1;
        int minVal = INT_MAX;
        
        for(int i=1; i<=dist.size()-1; i++){
            if(visited[i]) continue;
            if(dist[i] < minVal){
                minVal = dist[i];
                minNode = i;
            }
        }
        
        return minNode;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1, INT_MAX);
        vector<int>visited(n+1, false);
        vector<vector<int>>adj(n+1, vector<int>(n+1, -1));
        
        for(auto &edge: times)
            adj[edge[0]][edge[1]] = edge[2];
        
        
        dist[k] = 0;
        
        for(int i=0; i<n-1; i++){
            int minNode = getMinNode(dist, visited);
            if(minNode == -1) continue;
            visited[minNode] = true;
            
            for(int v=1; v<=n; v++){
                if(!visited[v] && adj[minNode][v] != -1 && dist[minNode] + adj[minNode][v] < dist[v]){
                    dist[v] = dist[minNode] + adj[minNode][v];
                }
            }
        }
        
        int maxTime = *max_element(dist.begin()+1, dist.end());
        
        return maxTime == INT_MAX ? -1 : maxTime;
    }
};