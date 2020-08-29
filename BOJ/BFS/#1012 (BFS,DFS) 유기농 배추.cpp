
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[51][51];
bool vis[51][51];
vector<int>numArray;
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int m, n, k;
		cin >> m >> n >> k;
		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + m, 0);
			fill(vis[i], vis[i] + m, 0);
		}
		while (k--) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}

		int num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] != 1 || vis[i][j])continue;
				num++;
				stack<pair<int, int>>S;
				S.push({ i,j });
				vis[i][j] = true;

				while (!S.empty()) {
					pair<int, int>cur = S.top(); S.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || ny < 0 || nx >= n | ny >= m)continue;
						if (board[nx][ny] != 1 || vis[nx][ny])continue;
						S.push({ nx,ny });
						vis[nx][ny] = true; 
					}
				}
			}
		}numArray.push_back(num);
	}
	for (auto& i : numArray)
		cout << i << "\n";
}



