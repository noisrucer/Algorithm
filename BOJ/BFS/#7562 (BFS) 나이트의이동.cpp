
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second
int dx[8] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
vector<int>res;

void bfs(vector<vector<int>> dist, int x1, int y1, int x2, int y2, int n) {
	queue<pair<int, int>>Q;
	Q.push({ x1,y1 });
	dist[x1][y1] = 0;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || ny >= n || nx >= n) continue;
			if (dist[nx][ny] >= 0)continue;
			Q.push({ nx,ny });
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			if (nx == x2 && ny == y2) {
				res.push_back(dist[nx][ny]);
				return;
			}
		}
	}
}
int main()
{
	int k;
	cin >> k;

	while (k--) {
		int n;
		cin >> n; // chess table width/height
		vector<vector<int>>dist(n, vector<int> (n,-1));
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2 && y1 == y2) {
			res.push_back(0);
			continue;
		}
		bfs(dist, x1, y1, x2, y2, n);
	}

	for (auto& i : res)
		cout << i << "\n";
}