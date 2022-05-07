bool solve(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return true;
    bool increase = nums[1] > nums[0];
    for(int i=1; i<nums.size(); i++){
        if(nums[i]==nums[i-1]) return false;
        if(increase && nums[i]<=nums[i-1]) return false;
        if(!increase && nums[i]>=nums[i-1]) return false;
    }
    return true;
}
