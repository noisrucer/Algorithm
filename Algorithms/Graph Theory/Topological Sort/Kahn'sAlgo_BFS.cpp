class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>res; // Topologically Sorted Schedule
        vector<vector<int>>adj(n); // Adj. List
        vector<int>indegree(n, 0); // indegree
        queue<int>Q;
        
        // Construct Adj. List & Indegree array
        for(auto &course: pre){
            adj[course[1]].push_back(course[0]);
            indegree[course[0]]++;
        }
        
        // Push all 0-indegree nodes
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) Q.push(i);
        }
        
        int cnt = 0;
        
        // Recursively eliminate all the edges with BFS
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            res.push_back(cur); // "IF" it's a DAG, this will be the answer
            cnt++;
            
            for(auto &neighbor: adj[cur]){
                if(--indegree[neighbor] == 0) Q.push(neighbor);
            }
        }
        
        // Check if the graph is cyclic
        if(cnt != n) return {};
        
        // If not cyclic, we already found the topogical sort from above
        return res;
        
    }
};