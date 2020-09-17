
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
class Solution {
public:

    void BFS(vector<vector<int>>&dist_ans, vector<vector<int>>&dist, vector<vector<int>>& matrix, int i, int j) {
        int n = matrix.size();
        int m = matrix[0].size();
        queue<pair<int, int>>Q;
        Q.push({ i,j });
        dist[i][j] = 0;
        

        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 4; dir++) {
                 int nx = cur.X + dx[dir];
                 int ny = cur.Y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({ nx,ny });

                if (!matrix[nx][ny]) {
                    dist_ans[i][j] = dist[nx][ny];
                    return;
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
         int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>dist(n, vector<int>(m,-1));
       
        queue<pair<int, int>>Q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!matrix[i][j]) {
                    dist[i][j] = 0;
                    Q.push({ i,j });
                }
            }
        }

        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
                if (matrix[nx][ny] != 1 || dist[nx][ny] != -1)continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({ nx,ny });
            }
        }

                
                
              
         
        

        return dist;
    }
};