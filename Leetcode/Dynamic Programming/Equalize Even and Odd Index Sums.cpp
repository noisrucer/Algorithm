int solve(vector<int>& nums) {
    int n = nums.size();
    int left_even=0, left_odd=0, right_even=0, right_odd=0;
    int res = 0;

    for(int i=n-1; i>=0; i--){
        if(!(i&1)) right_even += nums[i];
        else right_odd += nums[i];
    }

    for(int i=0; i<n; i++){
        if(!(i&1)) right_even -= nums[i];
        else right_odd -= nums[i];

        res += (left_even + right_odd == left_odd + right_even);

        if(!(i&1)) left_even += nums[i];
        else left_odd += nums[i];
    }

    return res;
}