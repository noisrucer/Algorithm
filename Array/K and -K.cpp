int solve(vector<int>& nums) {
    int n = nums.size();
    int res = INT_MIN;
    unordered_set<int>st;

    for(auto &el: nums){
        if(st.count(-1*el)) res = max(res,abs(el));
        st.insert(el);
    }
    
    if(st.count(0)) res = max(res,0);
    return res==INT_MIN?-1:res;

}




