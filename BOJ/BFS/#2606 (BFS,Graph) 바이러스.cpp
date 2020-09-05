#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int v, e;
	cin >> v >> e;
	vector<vector<int>>adj(v+1, vector<int>{});
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int>Q;
	vector<bool>visited(v+1,0);
	int count = 0;
	Q.push(1);
	visited[1] = 1;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop(); count++;
		for (auto i : adj[cur]) {
			if (visited[i] == 0) {
				visited[i] = 1;
				Q.push(i);
			}
		}
	}
	cout << count-1;

}