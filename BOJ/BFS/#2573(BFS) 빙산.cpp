
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
#define X first
#define Y second

int bfs(vector<vector<int>>board) {
	vector<vector<bool>>visited(n, vector<bool>(m));
	int num_icebergs = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] || board[i][j] == 0) continue;
			num_icebergs++;
			queue<pair<int, int>>Q;
			Q.push({ i,j });
			visited[i][j] = true;
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
					if (visited[nx][ny] || board[nx][ny] == 0)continue;
					Q.push({ nx,ny }); visited[nx][ny] = true;
				}
			}

		}
	}
	return num_icebergs;
		
}

void melt(vector<vector<int>>&board) {
	vector<vector<bool>>isVisited(n, vector<bool>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0)continue;
			isVisited[i][j] = true;

			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
				if (board[nx][ny] == 0 && !isVisited[nx][ny]) { // Ocean OR NOT visited
					if(board[i][j]>0)board[i][j]--;
				}
			}

		}
	}
}
int main()
{
	cin >> n >> m;
	vector<vector<int>>board(n, vector<int>(m));
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> board[i][j];

	int cnt_year = 0;
	
	while (true) {
		//if every cell is 0, then there has been no year in which there are more than one ice berg
		bool isEmpty = true;
		for (int i = 0; i < n; i++) //O(n^2)
			for (int j = 0; j < m; j++)
				if (board[i][j] != 0) isEmpty = false;

		if (isEmpty) {
			cout << '0';
			return 0;
		}

		//BFS to count num_icebergs each year
		int num_icebergs = bfs(board);
		//If greater than 1, then return the year
		if (num_icebergs > 1) {
			cout << cnt_year;
			return 0;
		}

		//melt
		melt(board);

		//increase year by 1
		cnt_year++;
	}
	return 0;
}
