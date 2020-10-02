class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //O(n) Solution
        int n=triangle.size();
        vector<int>cpy = triangle.back();
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                cpy[j]=triangle[i][j]+min(cpy[j],cpy[j+1]);
            }
        }
        return cpy[0];
        /* O(n^2) Solution

        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        dp[0][0]=triangle[0][0];
        for(int i=1; i<triangle.size(); i++){
            for(int j=0; j<triangle[i].size(); j++){
                if(j==0) dp[i][j]=triangle[i][j]+dp[i-1][j];
                else if(j==triangle[i].size()) dp[i][j]=triangle[i][j]+dp[i-1][j-1];
                else dp[i][j]=triangle[i][j]+min(dp[i-1][j-1],dp[i-1][j]);
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
        */
    }
};