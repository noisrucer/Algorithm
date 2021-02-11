vector<int> solve(vector<int>& nums) {
    reverse(nums.begin(), nums.end());
    int carry = 0;
    int sum = 1;
    for(int i=0; i<nums.size(); i++){
        sum += (carry + nums[i]);
        nums[i] = sum % 10;
        carry = sum / 10;
        sum=0;
    }
    
    if(carry!=0) nums.push_back(1);
    reverse(nums.begin(), nums.end());
    return nums;
}

