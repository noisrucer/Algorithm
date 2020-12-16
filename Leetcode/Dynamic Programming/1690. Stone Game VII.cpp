//Top-Down DP - O(n^2) - Prefix sum
class Solution {
public:
    int dp[1001][1001]={};
    int topdown(vector<int>&stones,vector<int>&prefix, int i, int j){
        if(i==j) return 0;
        if(dp[i][j]) return dp[i][j];
        return dp[i][j]=max(prefix[j]-prefix[i]-topdown(stones,prefix,i+1,j),
                    prefix[j-1]-(i>0?prefix[i-1]:0)-topdown(stones,prefix,i,j-1));
    }
    
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        vector<int>prefix(n,0);
        prefix[0]=stones[0];
        for(int i=1; i<n; i++)
            prefix[i]=prefix[i-1]+stones[i];
        
        return topdown(stones,prefix,0,n-1);
    }
};