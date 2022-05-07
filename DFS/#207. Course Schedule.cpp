class Solution {
public:
    vector<bool>visit;
    
    bool isCyclic(int &v, vector<vector<int>>&adj, int &curr){
        if(visit[curr]) return true;
        visit[curr]=true;
        
        for(auto i: adj[curr]){
            if(isCyclic(v,adj,i)) return true;
        }
        
        visit[curr]=false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        visit.resize(numCourses,false);
        
        for(auto edge: prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }
        
        int v=numCourses;
        
        for(int i=0; i<v; i++){
            visit[i]=true;
            for(auto e: adj[i]){
                if(isCyclic(v,adj,e)) return false;
            }
            visit[i]=false;
        }
        
        return true;
        
        
    }
};