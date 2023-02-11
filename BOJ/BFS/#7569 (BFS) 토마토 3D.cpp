
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <tuple>
using namespace std;
#define X first;
#define Y second;
#define Z third;
int dx[6] = {0,0,1,0,-1,0 };
int dy[6] = {0,0,0,1,0,-1 };
int dz[6] = {1,-1,0,0,0,0 };
int board[100][100][100];
int dist[100][100][100];

vector<int>numArray;
int main()
{
	int n, m, h;
	cin >> m >> n >> h;
	queue<tuple<int, int, int>>Q;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				
					cin >> board[i][j][k];
				}
			}
		}
		bool isthereNo = false;
		for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				
					if (board[i][j][k] == 0) isthereNo = true;
				}
			}
		}
		if (!isthereNo) {
			cout << 0;
			return 0;
		}
		for (int k = 0; k < h; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {

					if (board[i][j][k] == -1) {
						dist[i][j][k] = -1;
					}
					else if (board[i][j][k] == 1) {
						
						dist[i][j][k] = 0;
						Q.push({ i,j,k });
					}
					else
						dist[i][j][k] = -2;


				}
			}
		}

		while (!Q.empty()) {
			tuple<int, int, int>cur = Q.front(); Q.pop();
			for (int dir = 0; dir < 6; dir++) {
				int nx = get<0>(cur) + dx[dir];
				int ny = get<1>(cur) + dy[dir];
				int nz = get<2>(cur) + dz[dir];

				if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h)continue;
				if (board[nx][ny][nz] != 0 || dist[nx][ny][nz] >= 0)continue;
				dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				Q.push({ nx,ny,nz });
			}

		}
		for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				
					if (dist[i][j][k] == -2) {
						cout << -1;
						return 0;
					}
				}
			}
		}
		
		int mx = 0;
		for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				
					mx = max(mx, dist[i][j][k]);
				}
			}
		}
		cout << mx;

	
}