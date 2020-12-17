


//3 Coloring

bool isCycle(vector<int>g[],vector<int>&visit,int cur){
   if(visit[cur]==2) return true;
   visit[cur]=1;
   
   for(int child=0; child<g[cur].size(); child++){
       if(visit[g[cur][child]]==1) visit[g[cur][child]]=2;
       else{
           bool FLAG = isCycle(g,visit,g[cur][child]);
           visit[cur]--;
           if(FLAG) return true;
       }
   }
   visit[cur]=0;
   return false;
}


bool isCyclic(vector<int>g[], int V)
{
    vector<int>visit(V,0);
    
    for(int node=0; node<V; node++){
        visit[node]=1;
        for(int child=0; child<g[node].size(); child++){
            bool FLAG = isCycle(g,visit,g[node][child]);
            visit[node]--;
            if(FLAG) return true;
        }
        visit[node]=0;
    }
   
    
   return false;
}
