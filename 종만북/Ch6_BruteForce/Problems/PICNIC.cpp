#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std; 

int cnt = 0;

int main(){
    int T;
    cin >> T;
    
    while(T--){
        int n, m;
        cin >> n >> m; // n students, m pairs
        vector<vector<int>>areFriends(n, vector<int>(n, false));
        vector<int>visited(n, false);

        // Frienship Check
        while(m--){
            int p1, p2;
            cin >> p1 >> p2;
            areFriends[p1][p2] = true;
            areFriends[p2][p1] = true;
        }

        // Pair-up students



    }
}