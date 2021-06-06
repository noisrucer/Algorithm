int solve(vector<int>& nums) {
    int res = 0;
    unordered_map<int,int>mp;

    for(auto &el: nums){
        if(mp.count(el+1)) res++;
        if(mp.count(el-1)){
            res+=mp[el-1];
            mp[el-1]=0;
        }
        mp[el]++;
    }

    return res;
}