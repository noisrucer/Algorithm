#include <iostream>
#include <queue>
#include <vector>
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
	queue<pair<int, int>>Q;
	int m, n;
	cin >> m >> n; 
	//input board
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	//case 1: 익을 토마도 없음
	bool isthereNo = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0)
				isthereNo = true;
		}
	}
	if (!isthereNo) {
		cout << 0; return 0;
	}

	//-2 initialization
	for (int i = 0; i < n; i++)
			fill(dist[i],dist[i]+m, -2);
	//set -1 for dist
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == -1)
				dist[i][j] = -1;
		}
	}
	//multiple starting points set
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) {
				Q.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}
	//BFS Operation
				while (!Q.empty()) {
					pair<int, int> cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (board[nx][ny] != 0 || dist[nx][ny] >= 0)continue;
						dist[nx][ny] = dist[cur.X][cur.Y] + 1;
						Q.push({ nx,ny });
					}
				}
 
	//When there is/are 0 on the Dist
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -2) {
				cout << -1;
				return 0;
			}
			
		}
	}
	
	int mx = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			mx = max(dist[i][j], mx);
		
	cout << mx;
}