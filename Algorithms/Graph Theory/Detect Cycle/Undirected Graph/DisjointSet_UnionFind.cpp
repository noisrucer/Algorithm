#include <iostream>
#include <vector>

using namespace std;
vector<int>dsuf;

int find(int v){
    if(dsuf[v]==-1) return v;
    return find(dsuf[v]);
}

void union_op(int from, int to){
    from = find(from);
    to = find(to);
    dsuf[from]=to;
}

bool isCycle(vector<pair<int,int>>&edge_list){
    for(auto i: edge_list){
        if(find(i.first)==find(i.second)) return true;
        union_op(i.first,i.second);
    }
    return false;
}
int main(){
    vector<pair<int,int>>edge_list;
    int V,E;
    cin>>V>>E;
    dsuf.resize(V,-1);
    for(int i=0; i<E; i++){
        int u,v;
        cin>>u>>v;
        edge_list.push_back({u,v});
    }

    if(isCycle(edge_list)) cout<<"cycle exists";
    else cout<<"no cycle";



}