vector<int> solve(vector<int>& nums) {
    unordered_map<int, int> mp, cnt;
    vector<int> res;
    for (auto num : nums) mp[num]++;
    for (auto num : nums) {
        if (cnt[num] != 0 && cnt[num] + 1 >= mp[num]) continue;
        res.push_back(num);
        cnt[num]++;
    }
    return res;
}