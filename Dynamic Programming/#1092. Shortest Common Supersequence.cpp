//initial DP Approach - TLE
class Solution {
private:
    string minString(string &s1, string &s2){
        if(s1.length()>s2.length()) return s2;
        else return s1;
    }
    
public:
    vector<vector<string>>dp;
    string SCS(string &s1, string &s2, int i, int j){
        if(i<0 && j<0) return "";
        if(i<0) return s2.substr(0,j+1);
        if(j<0) return s1.substr(0,i+1);
        if(dp[i][j]!="A") return dp[i][j];
        
        if(s1[i]==s2[j]) dp[i][j] = SCS(s1,s2,i-1,j-1) + s1[i];
        string first = SCS(s1,s2,i-1,j)+s1[i];
        string second = SCS(s1,s2,i,j-1)+s2[j];
        if(s1[i]!=s2[j]) dp[i][j] = minString(first,second);
        return dp[i][j];
    }
    string shortestCommonSupersequence(string s1, string s2) {
        dp.resize(s1.length(),vector<string>(s2.length(),"A"));
        return SCS(s1,s2,s1.length()-1,s2.length()-1);
    }
};

//LCS Approach
class Solution {
public:
    string LCS(string &s1, string &s2){
        int len1 = s1.length(), len2 = s2.length();
        vector<vector<string>>dp(len1+1,vector<string>(len2+1,""));
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + s1[i-1];
                else dp[i][j] = dp[i-1][j].size() > dp[i][j-1].size() ? dp[i-1][j] : dp[i][j-1];
            }
        }
        return dp[len1][len2];
    }
    
    string shortestCommonSupersequence(string s1, string s2) {
        int p1=0, p2=0;
        string lcs = LCS(s1,s2), res=""; 
        for(auto c: lcs){
            while(s1[p1]!=c)
                res += s1[p1++];   
            while(s2[p2]!=c)
                res += s2[p2++];
            res+=c;
            p1++; p2++;
        }
        res+= s1.substr(p1) + s2.substr(p2);
        return res;
    }
};



