int solve(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int,int>mp;
    int offset = 0;
    k++;

    // i + offset refer to "actual index" after inserting "waits"
    for(int i=0; i<n; i++){
        if(mp.count(nums[i]) && i + offset - mp[nums[i]] < k){
            offset += (k - (i + offset - mp[nums[i]]));
        }
        mp[nums[i]] = i + offset;
    }

    return n + offset;
}