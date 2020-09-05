#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;
#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int> ans;
map<int, int> mp;

int main()
{

	int n, m;
	cin >> n >> m; //7 10
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	
	
	int mx = 0;
	int num = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j]==1 && !vis[i][j]) {
				num++;
				queue<pair<int, int>>Q;
				int area = 0;
				vis[i][j] = 1; area++;
				
				
				Q.push({ i,j });

				while (!Q.empty()) {
					pair<int, int>cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (vis[nx][ny] == 1 || board[nx][ny] != 1) continue;
						vis[nx][ny] = 1;  area++;
					
						Q.push({ nx,ny });
					}

				}
				mx = max(mx, area);
				
			}
		}
	}
	cout << num << "\n" << mx;
	
}