#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int parent;
    int rank;
};

vector<Node>dsuf;

int find(int node){
    if(dsuf[node].parent==-1) return node;
    return dsuf[node].parent = find(dsuf[node].parent);
}

void union_op(int from, int to){
    if(dsuf[from].rank>dsuf[to].rank){
        dsuf[to].parent = from;
    }
    else if(dsuf[from].rank<dsuf[to].rank){
        dsuf[from].parent = to;
    }else{
        dsuf[from].parent = to;
        dsuf[to].rank++;
    }
}

bool isCycle(vector<pair<int,int>>&edge_list){
    for(auto edge: edge_list){
        int fromNode = find(edge.first);
        int toNode = find(edge.second);

        if(fromNode==toNode) return true;

        union_op(fromNode, toNode);
    }
    return false;
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<pair<int,int>>edge_list;
    dsuf.resize(V,{-1,0});
    
    //make edge_list
    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        edge_list.push_back({u,v});
    }

    if(isCycle(edge_list)) cout<<"cycle exists";
    else cout<<"No cycle";
}
