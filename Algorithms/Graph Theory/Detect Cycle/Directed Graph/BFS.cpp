class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& pre) {
        vector<vector<int>>adj(v);
        vector<int>indegree(v,0);
        int cnt = v;
        for(auto &course: pre){
            adj[course[1]].push_back(course[0]);
            indegree[course[0]]++;
        }
        
        queue<int>Q;
        
        for(int i=0; i<v; i++){
            if(indegree[i]==0) Q.push(i);
        }
        
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            cnt--;
            for(auto &i: adj[cur]){
                if(--indegree[i]==0) Q.push(i);
            }
        }
        
        return cnt==0;
        
    }
};