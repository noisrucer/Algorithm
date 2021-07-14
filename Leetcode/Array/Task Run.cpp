int solve(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int,int>timestamp;
    int offset = 0;
    k++;

    // i + offset refer to "actual index" after inserting "waits"
    for(int i=0; i<n; i++){
        if(timestamp.count(nums[i]) && i + offset - timestamp[nums[i]] < k){
            offset += (k - (i + offset - timestamp[nums[i]]));
        }
        timestamp[nums[i]] = i + offset;
    }

    return n + offset;
}