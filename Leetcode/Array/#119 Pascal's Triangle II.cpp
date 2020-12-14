class Solution {
public:
//inplace solution
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>res(rowIndex+1,0);
        res[0]=1;
        for(int i=1; i<=rowIndex; i++){
            for(int j=i-1; j>=1; j--)
                res[j]=res[j]+res[j-1];
            res[i]=1;
        }
        return res;
    }
};

//DP Solution
    vector<vector<int>>dp;
    vector<int>helper(int n){
        if(n==0) return {1};
        if(dp[n].size()!=0) return dp[n];
       vector<int>sub;
        sub.push_back(1);
        for(int i=1; i<n; i++)
            sub.push_back(helper(n-1)[i]+helper(n-1)[i-1]);
        sub.push_back(1);
        dp[n]=sub;
        return dp[n];
    }
    vector<int> getRow(int rowIndex) {
        dp = vector<vector<int>>(rowIndex+1,vector<int>{});
        return helper(rowIndex);
    }
};