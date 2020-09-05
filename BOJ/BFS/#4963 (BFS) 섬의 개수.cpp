#include <unordered_map>
#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

int dx[8] = { 1,0,-1,0,1,-1,-1,1 };
int dy[8] = { 0,1,0,-1,1,1,-1,-1 };
int main()
{
	while (true) {
		int board[51][51];
		int vis[51][51]={};
		int islandCount = 0;
		int n, m;
		cin >> m >> n;
		if (n == 0 && m == 0) return 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> board[i][j];

		
		queue<pair<int, int>>Q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j]==1 || board[i][j]==0) continue;
				
				islandCount++; 
				Q.push({ i,j });
				vis[i][j] = 1; //visited
				while (!Q.empty()) {
					pair<int, int>cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 8; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (vis[nx][ny] == 1 || board[nx][ny] != 1) continue;
						Q.push({ nx,ny });
						vis[nx][ny] = 1;
					}
				}

			}
		}
		cout << islandCount << "\n";
	}
}