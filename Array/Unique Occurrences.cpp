bool solve(vector<int>& nums) {
    unordered_map<int,int>mp;
    for(int num: nums) mp[num]++;

    unordered_set<int>st;
    for(auto i: mp){
        if(st.count(i.second)) return false;
        st.insert(i.second);
    }
    return true;
}
