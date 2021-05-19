vector<unordered_map<int,int>>dp;
int n;

int helper(vector<int>& nums, int target, int i){
    if(i<0){
        if(target==0) return 1;
        else return 0;
    }

    if(dp[i].count(target)) return dp[i][target];

    return dp[i][target] = helper(nums,target-nums[i],i-1) + helper(nums,target+nums[i],i-1);
}

int solve(vector<int>& nums, int target) {
    n = nums.size();
    dp.clear();
    dp.resize(n);

    return helper(nums,target,n-1);
}