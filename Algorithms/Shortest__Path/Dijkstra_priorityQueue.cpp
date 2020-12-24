class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int,int>>>adj(N+1);
        vector<int>dist(N+1,INT_MAX);
        vector<int>visited(N+1,false);
        //build adj list
        for(auto time: times){
            adj[time[0]].push_back(make_pair(time[1],time[2]));
        }
                                  
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        dist[K]=0;
        pq.push({0,K}); //pq -> (weight,vertex)
        
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop(); //cur is a pair
            int minNode = cur.second;
            int minWeight = cur.first;
            visited[minNode] = true;
            
            for(auto neighbor: adj[minNode]){
                if(!visited[neighbor.first] && dist[minNode]+neighbor.second < dist[neighbor.first]){
                    dist[neighbor.first]=dist[minNode]+neighbor.second;
                    pq.push({dist[neighbor.first],neighbor.first});
                }
            }
        }
        
        int res = *max_element(dist.begin()+1,dist.end());
        return res==INT_MAX?-1:res;
        
        
        
    }
};