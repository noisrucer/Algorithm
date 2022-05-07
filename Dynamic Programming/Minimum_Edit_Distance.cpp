#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>dp;
int findMinEditDist(string &s1, string &s2, int i, int j){
    //base case
    if(i==-1) return j+1;
    if(j==-1) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i]==s2[j]) 
        dp[i][j] = findMinEditDist(s1,s2,i-1,j-1);
    else
        dp[i][j] = 1 + min({findMinEditDist(s1,s2,i,j-1),findMinEditDist(s1,s2,i-1,j),findMinEditDist(s1,s2,i-1,j-1)});

    return dp[i][j];
}

int minEditDist(string s1, string s2){
    int n = s1.length(), m = s2.length();
    dp.resize(n,vector<int>(m,-1));
    return findMinEditDist(s1,s2,s1.length()-1,s2.length()-1);
}

int main(){
    cout<<"Enter two strings s1 and s2 to find the minimum edit distance\n";
    string s1, s2;
    cin>>s1>>s2;
    cout<<minEditDist(s1,s2);
}