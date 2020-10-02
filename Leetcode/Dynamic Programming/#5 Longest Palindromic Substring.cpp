class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==0) return "";
        vector<vector<bool>>dp(n,vector<bool>(n,0));
        int max_len = 1;
        string str="";
        str = s[0];
        for(int i=0; i<n; i++){
            dp[i][i]=true;
            if(i!=n-1){
                if(s[i]==s[i+1]){
                    max_len = 2;
                    str= s.substr(i,2);
                    dp[i][i+1]=true;
                }
            }
        }
        
        for(int i=2; i<n; i++){
            for(int j=0; j<n-i; j++){
                if(s[j]==s[i+j] && dp[j+1][i+j-1]){
                    dp[j][i+j] = true;
                    if(i+1 > max_len){ //save quite amount of time!!!!!
                      max_len = i+1;
                        str = s.substr(j,i+1);
                    }
                }
            }
        }
        return str;
        
        
        
    }
};