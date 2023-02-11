#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <climits>
#include <cstring>
using namespace std;
#define X first
#define Y second
int board[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board_copy[i][j] << " ";
		}cout << endl;
	}*/
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	int mx = INT_MIN;
	for (int i = 0; i < n; i++) {
		int local_max = *max_element(board[i], board[i] + n);
		if (local_max > mx) mx = local_max;
	}
	int num_max = INT_MIN;
	for (int r = 0; r <= mx; r++) {
		int board_copy[101][101];
		memcpy(board_copy, board, 50 * 50 * sizeof(int));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board_copy[i][j] <= r) board_copy[i][j] = 0;
				else board_copy[i][j] = 1;
			}
		}

		bool vis[101][101];
		for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);
		
		int num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board_copy[i][j] != 1 || vis[i][j]) continue;
				num++;
				queue<pair<int, int>>Q;
				Q.push({ i,j });
				vis[i][j] = true;

				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
						if (board_copy[nx][ny] != 1 || vis[nx][ny])continue;
						Q.push({ nx,ny });
						vis[nx][ny] = true;
					}
				}
			}
		}
		
		(num > num_max) ? num_max = num : num_max = num_max;
		
	}
	cout << num_max;
	
	return 0;
}