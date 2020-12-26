#include <iostream>
#include <vector>

using namespace std;

int subsetCount(vector<int>&nums, int k){
  int n = nums.size(), cnt=0;
  vector<vector<int>>dp(n+1,vector<int>(k+1,0));

  for(int i=0; i<=n; i++)
    dp[i][0]=1;
  
  for(int i=1; i<=n; i++){
    for(int j=1; j<=k; j++){
      if(nums[i-1]>j) dp[i][j]=dp[i-1][j];
      else{
         dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
      }
      
    }
  }
  return dp[n][k];
}

int main(){
  vector<int>nums = {1,1,1,1,1};
  int k = 1;

  cout<< subsetCount(nums,k);
}