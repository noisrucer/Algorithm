#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second
string board[1001];
int distF[1001][1001];
int distJ[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i]; //board input complete

	for (int i = 0; i < n; i++) {
		fill(distF[i], distF[i] + m, -1);
		fill(distJ[i], distJ[i] + m, -1);
	}
	queue<pair<int, int>>Qf;
	queue<pair<int, int>>Qj;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'F') {
				distF[i][j] = 0;
				Qf.push({ i,j });
			}
			if (board[i][j] == 'J') {
				distJ[i][j] = 0;
				Qj.push({ i,j });
			}
		}
	}
	

	while (!Qf.empty() ) { //불
			pair<int, int>cur = Qf.front(); Qf.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (board[nx][ny] == '#' || distF[nx][ny] >=0) continue;
				distF[nx][ny] = distF[cur.X][cur.Y]+1;
				Qf.push({ nx,ny });
			}
	}

	while (!Qj.empty()) {
		pair<int, int>cur = Qj.front(); Qj.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				cout << distJ[cur.X][cur.Y] + 1;
				return 0;
			}

			if (board[nx][ny] == '#' || distJ[nx][ny] >= 0) continue;
			if (distF[nx][ny] != -1 && distF[nx][ny] <= distJ[cur.X][cur.Y] + 1  ) continue;
			distJ[nx][ny] = distJ[cur.X][cur.Y] + 1;
			Qj.push({ nx,ny });
			
		}
	}
	cout << "IMPOSSIBLE";

}