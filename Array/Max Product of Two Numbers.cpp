int solve(vector<int>& nums) {
    int n = nums.size();
    int cur_max = nums[0], cur_min = nums[0];
    int res = INT_MIN;
    for(int i=1; i<n; i++){
        res = max({res,nums[i]*cur_max, nums[i]*cur_min});
        cur_max = max(cur_max,nums[i]);
        cur_min = min(cur_min,nums[i]);
    }

    return res;
}
