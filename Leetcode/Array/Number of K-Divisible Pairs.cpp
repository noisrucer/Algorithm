int solve(vector<int>& nums, int k) {
    unordered_map<int,int>mp;
    int res = 0;
    for(auto num: nums){
        res += mp[(k-num%k)%k];
        mp[num%k]++;
    }
    return res;
}