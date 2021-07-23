int solve(vector<int>& nums) {
    int n = nums.size();
    int curMin = nums[0];
    int res = INT_MAX;
    
    for(int i=2; i<n; i++){
        res = min(res,nums[i]+curMin);
        curMin = min(curMin,nums[i-1]);
    }

    return res;
}