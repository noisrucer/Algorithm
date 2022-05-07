vector<int> solve(vector<int>& nums) {
    unordered_map<int,int>mp;
    vector<int>res;
    set<pair<int,int>,greater<pair<int,int>>>st;
    for(int i: nums) mp[i]++;
    for(auto p: mp) st.insert({p.second,p.first});
    for(auto s: st) res.insert(res.end(),s.first,s.second);
    
    return res;
    
}