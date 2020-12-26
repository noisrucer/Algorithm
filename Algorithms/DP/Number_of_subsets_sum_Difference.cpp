#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int numOfSubsetDiff(vector<int>&nums, int K){
    int n = nums.size(), target;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if((sum-K)%2!=0) return 0;
    else target = (sum-K)/2;
    cout << target << endl;
    

    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    for(int i=0; i<=n; i++) dp[i][0]=1; //There's always one way to make 0 by not including any element

    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){
            if(nums[i-1]>j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
        }
    }

    return dp[n][target];
}

int main(){
    vector<int>nums = {3,1,2,3,3,31,5,2,3,3,3};
    int K = 3;
    cout << numOfSubsetDiff(nums,K);
   
}