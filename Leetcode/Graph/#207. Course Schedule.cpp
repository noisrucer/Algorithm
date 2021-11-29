//BFS - Kahn's Algorithm
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        //Kahn's Algorithm
        //Key point: A Directed Cyclic Graph has ALL NODES with > 1 indegree
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        int cnt = n;
        
        for(vector<int>& course: pre){
            adj[course[1]].push_back(course[0]);
            indegree[course[0]]++; 
        }
        
        queue<int>Q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0) Q.push(i); //push all the 0 in-degree node
        }
        
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            cnt--;
            
            for(int &neighbor: adj[cur]){
                if(--indegree[neighbor]==0) Q.push(neighbor); //each time, disconnect the - in-degree node
            }
        }   
            
            
        return cnt!=0;
    }
};


// Graph Coloring with 3 colors - TLE!!!
class Solution {
public:
    bool isCyclic(vector<vector<int>>&adj, vector<int>&visited, int cur){
        // Graph Coloring
        // 0: Unprocessed
        // 1: Processed
        // 2: Processing -> if encounter (2), then there's a cycle
        if(visited[cur] == 2) return true;
        visited[cur] = 2;
        
        for(int neighbor: adj[cur]){
            if(isCyclic(adj,visited,neighbor)) return true;
        }
        
        visited[cur] = 1;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        vector<int>visited(n, false);
        for(auto course: pre){
            adj[course[0]].push_back(course[1]);
        }
        
        for(int cur=0; cur<n; cur++){
            if(visited[cur]) continue;
            if(isCyclic(adj,visited,cur)) return false;
        }
        
        return true;
        
    }
};