vector<int> solve(vector<int>& nums) {
    int n = nums.size();
    int rep = nums[0];
    nums[0] = 0;
    int temp;

    for(int i=1; i<n; i++){
        temp = nums[i];
        nums[i] = rep;
        rep = min(rep,temp);
    }

    return nums;
}