
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;


void dfs(vector<vector<int>>adj, vector<bool>&visited, int s) {
	cout << s << " -> ";
	visited[s] = true;

	for (auto& i : adj[s]) {
		if (visited[i]) continue;
		dfs(adj, visited, i);
	}
}
int main()
{
	int v, e, s;
	cin >> v >> e >> s;
	vector<vector<int>>adj(v+1, vector<int>{});
	vector<bool>visited(v+1,0);
	
	while (e--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i < adj.size(); i++) 
		sort(adj[i].begin(), adj[i].end());

	dfs(adj, visited, s);


}



