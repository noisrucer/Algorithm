class Solution {
public:
    
    int getMinNode(vector<int>&dist,vector<int>&visited){
        int minVal=INT_MAX;
        int minNode;
        for(int i=1; i<=dist.size()-1; i++){
            if(visited[i]) continue;
            if(dist[i]<minVal){
                minVal = dist[i];
                minNode = i;
            }
        }
        
        return minNode;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>>adj(N+1,vector<int>(N+1,-1));
        vector<int>visited(N+1,false);
        vector<int>dist(N+1,INT_MAX);
        int total_max = INT_MIN;
        
        //construct adjacency matrix
        for(auto time: times){
            adj[time[0]][time[1]]=time[2];
        }
        
        dist[K]=0;
        
        for(int i=0; i<N-1; i++){
            int minNode = getMinNode(dist,visited);
         
            visited[minNode] = true;
            for(int v=1; v <= N; v++){
                if(adj[minNode][v]!=-1 && !visited[v] && dist[minNode]+adj[minNode][v] < dist[v]){
                    dist[v]=dist[minNode]+adj[minNode][v];
                }
            }
        }
        
        total_max = *max_element(dist.begin()+1,dist.end());
        
        if(total_max==INT_MAX) return -1;
        else return total_max; 
        
        
            
    }
};