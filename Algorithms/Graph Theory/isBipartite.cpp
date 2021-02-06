bool isBipartite(vector<vector<int>>&graph){
    int V = graph.size();
    queue<int>Q;
    vector<int>color(V,-1);
    vector<int>visited(V,false);

    for(int i=0; i<V; i++){
        if(visited[i]) continue; 
        Q.push(i);
        color[i] = 1;
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            visited[cur] = true;
            for(auto neighbor: graph[cur]){
                if(visited[neighbor]) continue;
                if(color[neighbor]!=-1){
                    if(color[cur] == color[neighbor]) return false;
                }else{
                    color[neighbor] = 1 - color[cur];
                    Q.push(neighbor);
                }
            }
        }
    }
    return true;
}
bool solve(vector<vector<int>>& graph) {
    return isBipartite(graph);
    
}