int solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if(n==1) return 100000;
    int start = 1;
    int res = INT_MIN;
    

    for(int i=0; i<n; i++){
        if(i==n-1) res = max(res,100000-(nums[i-1]+1)+1);
        res = max(res,nums[i]-(i==0?1:nums[i-1]));
        if(i>0){
            res = max(res,nums[i]-1-(start==1?0:start));
            start = nums[i-1];
        }
    }

    return res;
}