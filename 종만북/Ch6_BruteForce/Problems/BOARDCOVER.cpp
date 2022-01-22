#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

const int coverType[4][3][2] = {
    {{0,0}, {1,0}, {0,1}},
    {{0,0}, {0,1}, {1,1}},
    {{0,0}, {1,0}, {1,1}},
    {{0,0}, {1,0}, {1,-1}}
};

bool setBoard(vector<vector<int>>& board, int x, int y, int type, int delta){
    bool possible = true;

    for(int i = 0; i < 3; i++){
        int nx = x + coverType[type][i][0];
        int ny = y + coverType[type][i][1];
        if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size()) possible = false;
        else if((board[nx][ny] += delta) > 1) possible = false; // nice trick: think through what it does
    }

    return possible;
}

int cover(vector<vector<int>>& board){
    int x = -1, y = -1;

    // 아직 채우지 못한 칸중 제일 top-left 에 있는 cell을 찾음
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(!board[i][j]){ // if we found an empty cello
                x = i;
                y = j;
                break;
            }
        }

        // early break
        if(x != -1) break;
    }

    // 다 채웠으면 1을 반환
    if(x == -1) return 1;
    int res = 0;

    for(int type = 0; type < 4; type++){
        // 먄약 board[x][y]를 덮을 수 있으면 재귀호출
        if(setBoard(board, x, y, type, 1)) res += cover(board);
        // 덮었던 블록 치운다
        setBoard(board, x, y, type, -1);
    }

    return res;
}

int main(){
    int test_cases;
    cin >> test_cases;
    vector<int>res;

    while(test_cases--){
        int m, n;
        cin >> m >> n;

        vector<vector<int>>board(m, vector<int>(n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                char c;
                cin >> c;
                // cout<<c;
                board[i][j] = (c == '#' ? true : false);
            }
        }

        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<board[i][j];
        //     }cout<<"\n";
        // }

        res.push_back(cover(board));
    }

    for(auto i: res) cout<<i<<"\n";
}