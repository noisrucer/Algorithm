int topdown(vector<int>& nums, int l, int r, int left_bound, int right_bound){
    if(l>r) return 0;
    int m = (l+r)/2;
    return (nums[m]>=left_bound && nums[m]<=right_bound) + topdown(nums,l,m-1,left_bound,min(right_bound,nums[m])) + topdown(nums,m+1,r,max(left_bound,nums[m]),right_bound);
}

int solve(vector<int>& nums) {
    int n = nums.size();
    return topdown(nums,0,n-1,INT_MIN,INT_MAX);
}