class Solution {
public:
    int target;
    int size;
  
    bool canPartition(vector<int>& nums) {
        size = nums.size();
        int sum=0;
        for(auto i: nums) sum+=i;
        if(sum%2==1) return false;
        target = sum/2;
       vector<vector<bool>>dp(nums.size()+1,vector<bool>(target+1,0));
        
        for(int i=0; i<=nums.size(); i++)
            dp[i][0]=true;
        
       for(int i=1; i<=nums.size(); i++){
           for(int j=1; j<=target; j++){
               if(j-nums[i-1]<0) continue;
               dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
           }
       }
        return dp[nums.size()][target];
        
        
       
    }
};