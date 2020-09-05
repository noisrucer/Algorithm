
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
int board[1001][1001];
bool visited[1001][1001][2];
void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string inp;
        cin >> inp;
        for (int j = 0; j < m; j++) {
            int tmp = inp[j] - '0';
            board[i][j] = tmp;
        }
    }
}
int bfs() {
    queue<pair<pair<int, int>, pair<int, int>>>Q;
    Q.push({ {0,0} ,{0,1} });

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int x = cur.first.first;
        int y = cur.first.second; 
        int B = cur.second.first;
        int cnt = cur.second.second;

        if (x == n - 1 && y == m - 1) return cnt;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
            if (board[nx][ny] == 1 && B == 0) {
                visited[nx][ny][B + 1] = true;
                Q.push({ {nx,ny},{B + 1,cnt + 1} });
            }
            else if(board[nx][ny]==0 && visited[nx][ny][B]==false){
                visited[nx][ny][B] = true;
                Q.push({ {nx,ny},{B,cnt + 1} });
            }
        }
    }
    return -1;
}

void solve() {
    input();
    cout << bfs()<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

}