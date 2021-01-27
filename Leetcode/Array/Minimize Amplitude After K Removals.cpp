
int solve(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int res = min(nums[n-1]-nums[k],nums[n-1-k]-nums[0]);
    for(int i=0; i<k-1; i++){
        res = min(res,nums[n-k+i]-nums[i+1]);
    }
    return res;
}