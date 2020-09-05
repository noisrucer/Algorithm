#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
//BFS DFS Implementation

void bfs(vector<vector<int>>adj, vector<bool>visited,int s) {
	for (int i = 1; i < adj.size(); i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	queue<int>Q;
	Q.push(s);
	visited[s] = true;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		cout << cur << " ";
		for (auto itr : adj[cur]) {
			if (visited[itr])continue;
			Q.push(itr);
			visited[itr] = true;
		}
	}
}

void dfs(vector<vector<int>>adj, vector<bool>visited, int s) {
	for (int i = 1; i < adj.size(); i++) 
		sort(adj[i].begin(), adj[i].end());

		stack<int>S;
		S.push(s);
		cout << s << " ";
		visited[s] = true;

		while (!S.empty()) {
			int cur = S.top(); S.pop();
			for (auto next : adj[cur]) {
				if (visited[next])continue;
				cout << next << " ";
				visited[next] = true;
				S.push(cur); S.push(next);
				break;

			}
		}
	
}

int main() {
	int v, e,s;
	cin >> v >> e>>s;
	vector<vector<int>>adj(v+1, vector<int>{});
	vector<bool>visited (v+1, 0);
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(adj, visited, s);
	cout << "\n";
	bfs(adj, visited, s);
	

}