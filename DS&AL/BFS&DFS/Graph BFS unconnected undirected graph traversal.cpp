#include <unordered_map>
#include <iostream>
#include <queue>
using namespace std;
//틈메이러
#define X first
#define Y second
int board[1000][1000];
int dist[1000][1000];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	int const v = 7;
	int e;
	cout << "Enter number of Edges: ";
	cin >> e;

	//Adjacency List -> using v
	vector<int> adj[v];

	//undirected graph implementation -> round trip
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//Visited Check Array
	bool visited[v] = {};
	queue<int>Q;
	for (int i = 0; i < v; i++) {
		if (visited[i]) continue;
		Q.push(i); visited[i] = 1;
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			cout << cur << " ";
			for (auto itr : adj[cur]) {
				if (visited[itr] == 1) continue;
				Q.push(itr);
				visited[itr] = true;
			}
		}
	}

}