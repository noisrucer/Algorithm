class Solution {
public:
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n, 0);
        queue<int>Q;
        
        // Construct Adj. list & indegree
        for(auto course: prerequisites){
            adj[course[1]].push_back(course[0]);
            indegree[course[0]]++;
        }
        
        // Push all the 0-indegree nodes which could be the "start" of the topo sort
        // 0-indegree nodes 에서부터 하나하나 제거해서 모든 "edge들을 제거" 하는게 목표!
        
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) Q.push(i);
        }
        
        int cnt = 0;
        
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            cnt++;
            
            for(int neighbor: adj[cur]){
                // edge를 끊었는데 상대방 노드의 indegree = 0이 되면 새로운 0-indegree node 추가
                if(--indegree[neighbor] == 0) Q.push(neighbor);
            }
        }
        
        return cnt == n;
        
        
    }
};