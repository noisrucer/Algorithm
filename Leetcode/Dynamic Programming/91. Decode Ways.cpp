class Solution {
public:
    vector<vector<int>>dp;
    int topdown(string &s, int i, char carry, bool flag){
        if(i<0){
            if(carry=='x') return 1;
            else return 0;
        }
        
        if(dp[i][flag] != -1) return dp[i][flag];
        if(carry != 'x'){
            int cmp = (s[i]-'0')*10 + (carry-'0'); 
           if(cmp>=10 && cmp<=26) dp[i][flag] = topdown(s,i-1,'x',false);
           else return 0;
        }else{
            if(s[i]=='0') dp[i][flag] = topdown(s,i-1,'0',true);
            else dp[i][flag] = topdown(s,i-1,s[i],true) + topdown(s,i-1,'x',false);
        }
        return dp[i][flag];
    }
    
    int numDecodings(string s) {
        int n = s.length();
        dp.clear();
        dp.resize(n,vector<int>(2,-1));
        return topdown(s,n-1,'x',true);
    }
};
