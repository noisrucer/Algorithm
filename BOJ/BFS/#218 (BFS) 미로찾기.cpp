#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
string board[102]; 
int dist[102][102];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	
	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);
	queue<pair<int, int>>Q;
	Q.push({ 0,0 });
	dist[0][0] = 0;
	while (!Q.empty()) {
		pair<int, int>cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] != '1' || dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1; //distance method
			Q.push({ nx,ny });
		}

	}
	cout << dist[n - 1][m - 1] + 1;
	
	
}