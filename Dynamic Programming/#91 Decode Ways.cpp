class Solution {
public:
    vector<int>dp;
    int topdown(string s, int n){
        if(dp[n]!=-1) return dp[n];
        if(s[n]=='0') return dp[n]=0;
        dp[n]=topdown(s,n+1);
        if(n<s.size()-1 && (s[n]=='1' || (s[n]=='2' && ('0'<=s[n+1] && s[n+1]<='6')))) dp[n]+=topdown(s,n+2);
        return dp[n];
    }
    int numDecodings(string s) {
        if(s=="0") return 0;
        dp=vector<int>(s.size()+1,-1);
        dp[s.size()]=1;
        return topdown(s,0);
    
    }
};