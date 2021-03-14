int solve(vector<int>& nums) {
    int cnt = 0;
    if(nums.size()==0) return cnt;
    for(int i=1; i<nums.size()-1; i++){
        if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) cnt++;
        if(nums[i]<nums[i-1] && nums[i]<nums[i+1]) cnt++;
    }
    return cnt;
}