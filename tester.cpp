#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;
int n,m;
pair<int,int>start;
vector<vector<char>>Board;
// vector<int>board_state(26,0);
vector<int>cur_state(26,0);
vector<vector<int>>visited;

int res = INT_MAX;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
#define X first
#define Y second


void DFS(vector<vector<char>>board, int i, int j, int pathSum, bool flag,vector<int>board_state){
    if(i<0 || j<0 || i >= n || j >= m) return;
    if(board[i][j]=='#') return;
    if(board[i][j] == '1'){
        res = min(res, pathSum);
        cout<<"res: "<<res<<endl;
        return;
    }
    if(board_state == cur_state && visited[i][j] && !flag) return;

    cout<<"(i,j) "<<i<<" "<<j<<endl;
    cout<<"-------------------CURRENT-------------------"<<endl;
    for(auto x: cur_state) cout<< x<<" ";
    cout<<endl;
    for(auto x: board_state) cout<<x<<" ";
    cout<<endl;

    visited[i][j] = true;
    vector<int>temp = cur_state;

    
    char beforeChange=board[i][j];
    
    // Encounter A-Z
    if(65 <= board[i][j] && board[i][j] <= 90){
        if(cur_state[board[i][j]-65] == 0) return;
        cur_state[board[i][j]-65]--;

        beforeChange = board[i][j];
        board[i][j] = '.';
    }
    
    // Encounter a-z
    else if(97 <= board[i][j] && board[i][j] <= 122){
        cur_state[board[i][j]-97]++;

        beforeChange = board[i][j];
        board[i][j] = '.';
    }

    if(board_state != cur_state) board_state = cur_state;
    
    cout<<"-------------------AFTER-------------------"<<endl;
    for(auto x: cur_state) cout<< x<<" ";
    cout<<endl;
    for(auto x: board_state) cout<<x<<" ";
    cout<<endl;
    

    DFS(board,i+dx[0],j+dy[0],pathSum+1,false);

    cur_state = temp; board_state = cur_state; board[i][j] = beforeChange; 
    DFS(board,i+dx[1],j+dy[1],pathSum+1,false);

    cur_state = temp; board_state = cur_state; board[i][j] = beforeChange; 
    DFS(board,i+dx[2],j+dy[2],pathSum+1,false);

    cur_state = temp; board_state = cur_state; board[i][j] = beforeChange; 
    DFS(board,i+dx[3],j+dy[3],pathSum+1,false);

    visited[i][j] = false;
}

int main(){
    cin >> n >> m;
    Board.resize(n,vector<char>(m));
    visited.resize(n,vector<int>(m,false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>Board[i][j];
            if(Board[i][j]=='0') start={i,j};
        }
    }

    DFS(Board,start.first,start.second,0,true);
     res = res==INT_MAX ? -1 : res;
     cout<<res;
    

}