int solve(vector<int>& nums) {
    int n = nums.size();
    int l=0, r = n-1, m;
    int min_index = INT_MAX;
    while(l<=r){
        m = l + (r-l)/2;
        if(nums[m]==m) min_index = min(min_index,m); 
        if(nums[m]<m) l = m + 1;
        else r = m - 1;
    }
    return min_index==INT_MAX ? -1 : min_index;
}
