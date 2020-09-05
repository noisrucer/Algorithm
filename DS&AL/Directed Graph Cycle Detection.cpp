
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
vector<int>cycle_num;
unordered_set<int>cycle_list;

bool isCyclic_util(vector<vector<int>>adj, vector<bool>visited, int curr) {
	if (visited[curr]) return true;
	visited[curr] = true;
	bool flag = false;
	for (int i = 0; i < adj[curr].size(); i++) {
		flag = isCyclic_util(adj, visited, adj[curr][i]);
		if (flag) return true;
	}
	return false;
}
bool isCyclic(int v, vector<vector<int>>adj) {
	vector<bool> visited(v, false);
	bool flag = false;
	for (int i = 1; i < v; i++) {
		visited[i] = true;
		for (int j = 0; j < adj[i].size(); j++) {
			flag = isCyclic_util(adj, visited, adj[i][j]);
			if (flag) return true;
		}
		visited[i] = false;
	}
	return false;
}
int main() {
	int v, e;
	cin >> v >> e;
	vector<vector<int>>adj(v+1, vector<int>{});
	for (int i = 1; i < e; i++) {
		int u;
		cin >> u;
		adj[i].push_back(u);
	}//adjacency list COMPLETE

	if(isCyclic(v,adj)) cout<<"true";
	else cout<<"false";


}