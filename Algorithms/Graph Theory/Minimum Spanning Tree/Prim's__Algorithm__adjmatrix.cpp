
int minKey(vector<bool>&setMST, vector<int>&key, int &V){
    int min_val = INT_MAX;
    int min_index;
    for(int i=0; i<V; i++){
        if(!setMST[i] && key[i]<min_val){
            min_val=key[i];
            min_index=i;
        }
    }
    
    return min_index;
}
int MST(int V, int E, vector<vector<int>> &graph) {
    vector<int>key(V,INT_MAX);
    vector<bool>setMST(V,false);
    vector<int>parent(V);
    
    key[0]=0;
    parent[0]=-1;
    
    for(int i=0; i<V-1; i++){
        int u = minKey(setMST,key,V);
        setMST[u]=true;
        
        for(int v=0; v<V; v++){
            if(graph[u][v] && !setMST[v] && graph[u][v]<key[v]){
                key[v]=graph[u][v];
                parent[v]=u;
            }
        }
    }
    
    int weight_sum = 0;
    for(int i=1; i<V; i++){
        weight_sum+=graph[i][parent[i]];
    }
    
    return weight_sum;
}