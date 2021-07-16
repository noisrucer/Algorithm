bool solve(vector<int>& nums) {
    int n = nums.size();
    vector<int>L(n), R(n);
    L[0] = nums[0]; R[n-1] = nums[n-1];

    for(int i=1; i<n; i++){
        L[i] = max(nums[i],L[i-1]);
        R[n-1-i] = min(nums[n-1-i],R[n-i]);
    }

    for(int i=0; i<n-1; i++){
        if(L[i] < R[i+1]) return true;
    }

    return false;
}