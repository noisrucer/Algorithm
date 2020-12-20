//Bottom Up
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

//TopDown (2^n)
class Solution {
public:
    vector<vector<int>>dp;
  
    bool topdown(vector<int>&nums, int target, int i){
        if(target<0 || i<0) return false;
        if(target==0) return true;
        if(dp[i][target]!=-1) return dp[i][target];
        
        if(nums[i]>target) dp[i][target]=topdown(nums,target,i-1);
        else{
            dp[i][target]=topdown(nums,target-nums[i],i-1) || topdown(nums,target,i-1);
        }
     
        return dp[i][target];
        
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if(total_sum%2!=0) return false;
        total_sum/=2; //this is our target
         dp.clear();
         dp.resize(n,vector<int>(total_sum+1,-1));
        return topdown(nums,total_sum,n-1);
    }
};