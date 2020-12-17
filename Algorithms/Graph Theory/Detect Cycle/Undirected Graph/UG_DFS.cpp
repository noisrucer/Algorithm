//DFS

bool isCycle(vector<int>g[], int cur, int parent,vector<bool>&visit){
   visit[cur]=true;
   
  for(int child=0; child<g[cur].size(); child++){
        
        if(!visit[g[cur][child]]){
          bool FLAG = isCycle(g,g[cur][child],cur,visit);
          if(FLAG) return true;
        }
        else if(g[cur][child] != parent){
            return true;
        }
  }
   
  return false;
}


bool isCyclic(vector<int>g[], int V)
{
    vector<bool>visit(V,false);
   //visit.resize(V,false);
   for(int i=0; i<V; i++){
       if(visit[i]) continue;
       if(isCycle(g,i,-1,visit)) return true;
   }
  // visit.resize(V,false);
   
   return false;
}
