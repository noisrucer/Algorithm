int solve(vector<int>& nums, vector<int>& mult) {
    int n = nums.size(), m = mult.size();
    int n1 = 0, n2 = n - 1;
    int m1 = 0, m2 = m - 1;
    int sum = 0;
    sort(nums.begin(), nums.end());
    sort(mult.begin(), mult.end());

    while(n1 <= n2 && m1 <= m2){
        if(nums[n1]*mult[m1] >= nums[n2]*mult[m2]){
            sum += nums[n1++]*mult[m1++];
        }else{
            sum += nums[n2--]*mult[m2--];
        }
    }
    
    return sum;
}
