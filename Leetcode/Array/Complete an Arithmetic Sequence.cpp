int solve(vector<int>& nums) {
    int n = nums.size();
    int a = (nums[n-1] - nums[0]) / n;
    for(int i=0; i<n; i++) if(nums[i] != nums[0] + i*a) return nums[0] + i*a;
    return nums[0];
}