

//DFS
vector<bool>visit;

bool isCycle(vector<int>g[], int cur, int parent){
    if(visit[cur]) return true;
   visit[cur]=true;
   
   for(int child=0; child<g[cur].size(); child++){
        if(g[cur][child]==parent) continue;
           bool FLAG = isCycle(g,g[cur][child],cur);
           if(FLAG) return true;
   }
   visit[cur]=false;
   return false;
}


bool isCyclic(vector<int>g[], int V)
{
    visit.resize(V,false);
    //vector<int>parent(V);
    
    for(int node=0; node<V; node++){
        visit[node]=true;
        for(int child=0; child<g[node].size(); child++){
            bool FLAG = isCycle(g,g[node][child],node);
            if(FLAG) return true;
        }
        visit[node]=false;
    }
   
   return false;
}
