#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std; 

int cnt = 0;
int N;

void dfs(vector<vector<int>>&adj, vector<int>&visited){
    // 매칭 안된 학생들중 가장 빠른 번호인 학생 - 중복을 피한다(permutation 중복 피함)
    int firstFree = -1;
    
    for(int i=0; i<N; i++){
        if(!visited[i]){
            firstFree = i;
            break;
        }
    }

    // 존재하지 않으면 매칭 다 했으므로 cnt++
    if(firstFree == -1){
        cnt++;
        return;
    }

    // 중복을 피하기 위하여 순서를 강제한다 -> Si < Sj -> (Si,Sj), (Sj,Si) 중복 피함
    for(int pairWith = firstFree+1; pairWith<N; pairWith++){
        if(!visited[pairWith] && adj[firstFree][pairWith]){
            visited[firstFree] = visited[pairWith] = true;
            dfs(adj, visited);
            visited[firstFree] = visited[pairWith] = false;
        }
    }


    
}

int main(){
    int T;
    cin >> T;
    vector<int>res;
    
    while(T--){
        int n, m;
        cin >> n >> m; // n students, m pairs
        N = n;
        vector<vector<int>>adj(n, vector<int>(n, false));
        vector<int>visited(n, false);

        // Frienship Check
        while(m--){
            int p1, p2;
            cin >> p1 >> p2;
            adj[p1][p2] = true;
            adj[p2][p1] = true;
        }

        // Pair-up students
        dfs(adj, visited);
        res.push_back(cnt);
        cnt = 0;
    }

    for(auto i: res) cout<<i<<"\n";
}