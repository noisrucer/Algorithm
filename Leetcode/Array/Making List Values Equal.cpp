int solve(vector<int>& nums) {
    set<int,greater<int>>st;
    int cnt=0, target;
    for(auto i: nums) st.insert(i);
    target = *st.begin();
    for(auto num: st){
        cnt += (target-num);
        target -= (target-num);
    }
    return cnt;

}
