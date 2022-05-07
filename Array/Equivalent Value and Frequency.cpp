bool solve(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int>freq;
    for(int &num: nums){
        freq[num]++;
    }
    for(auto p: freq){
        if(p.first == p.second) return true;
    }
    return false;
}