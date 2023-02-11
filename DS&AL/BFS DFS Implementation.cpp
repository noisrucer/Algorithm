#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
//BFS DFS Implementation

void bfs(vector<vector<int>>adj, vector<bool>visited, int s) {
	queue<int>Q;
	Q.push(s);
	visited[s] = true;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		cout << cur << " -> ";
		for (auto itr : adj[cur]) {
			if (visited[itr])continue;
			Q.push(itr);
			visited[itr] = true;
		}
	}
}

void dfs(vector<vector<int>>adj, vector<bool>visited, int s) {
	for (int i = 1; i < adj.size(); i++) {
		reverse(adj[i].begin(), adj[i].end());
	} //decreasing order -> 스택에 쌓였을때 작은 순서대로 빠져나가기 위해서
	stack<int> S;
	S.push(s);
	visited[s] = true;
	while (!S.empty()) {
		int cur = S.top(); S.pop();
		cout << cur << " -> ";
		for (auto itr : adj[cur]) {
			if (visited[itr]) continue;
			S.push(itr);
			visited[itr] = true;
		}
	}
}

void dfs1(vector<vector<int>>adj, vector<bool>visited, int s) {
	stack<int> S;
	S.push(s);
	visited[s] = true;
	cout << s << " -> ";

	while (!S.empty()) {
		int cur = S.top(); S.pop();
		for (auto i : adj[cur]) {
			if (visited[i] == true) continue;
			cout << i << " -> ";
			visited[i] = true;
			S.push(cur);
			S.push(i);
			break; //this is important cuz otherwise, it'll proceed BFS
		}
	}
	
}
int main() {
	int v, e,s;
	cin >> v >> e>>s;
	vector<vector<int>>adj(v+1, vector<int>{});
	vector<bool>visited(v+1, 0);
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i < adj.size(); i++)
		sort(adj[i].begin(), adj[i].end());
	bfs(adj, visited, s);
	cout << "\n\n";
	dfs(adj, visited, s);
	cout << "\n\n";
	dfs1(adj, visited, s);
}