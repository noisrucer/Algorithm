int solve(vector<int>& nums, int k) {
    int cur_sum = 0;
    int max_index = -1;
    for(int i=0; i<nums.size(); i++){
        cur_sum += nums[i];
        if(cur_sum <= k) max_index = i;
    }
    return max_index;
}