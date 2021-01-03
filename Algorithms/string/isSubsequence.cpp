//Find A is a subsequence of B
// if LCS(A,B)==A then true else false
// or length(LCS(A,B)) == length(A) then true

#include <iostream>
#include <vector>
using namespace std; 

int LCS(string s1, string s2){
    int n = s1.length(), m = s2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    if(LCS(s1,s2)==s1.length()) cout<<"yes";
    else cout<<"no";
}
