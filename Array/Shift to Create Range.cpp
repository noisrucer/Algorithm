bool solve(vector<int>& nums) {
    int n = nums.size();
    int temp1, temp2;
    int res1 = true, res2 = true;

    for(int i=1; i<n; i++){
        if(nums[i] != nums[i-1]%n + 1) res1 = false;
        if(nums[i] != (nums[i-1] - 2 + n)%n + 1) res2 = false;
        if(!res1 && !res2) return false;
    }

    return res1 || res2;
}