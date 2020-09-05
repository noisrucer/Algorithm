
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <tuple>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0 };
int dy[4] = {0,1,0,-1 };

int board[100][100];
bool vis[100][100];


int main()
{
	
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			board[i][j] = 1;
		}
	}

	while (k--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = min(x1, x2); j < max(x1, x2); j++) {
			for (int i = n - max(y1, y2); i < n - min(y1, y2); i++) {
				board[i][j] = 0;
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << board[i][j];
		}cout << endl;
	}cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << vis[i][j];
		}cout << endl;
	}*/
	vector<int>areaArray;
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 1 || vis[i][j])continue;
			num++; int area = 0;
			queue<pair<int, int>>Q;
			Q.push({ i,j });
			vis[i][j] = true;

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop(); area++;
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
					if (board[nx][ny] != 1 || vis[nx][ny])continue;
					Q.push({ nx,ny });
					vis[nx][ny] = true;
				}
			}areaArray.push_back(area);
		}
	}

	cout << num << "\n";
	sort(areaArray.begin(), areaArray.end());
	for (auto& i : areaArray)
		cout << i << " ";


	
}