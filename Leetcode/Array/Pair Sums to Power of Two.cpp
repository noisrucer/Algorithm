int solve(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int>mp;
    int res = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<32; j++){
            res += mp[(1<<j) - nums[i]];
        }
        mp[nums[i]]++;
    }
    return res;
}
