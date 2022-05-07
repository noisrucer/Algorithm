vector<int> solve(vector<vector<int>>& relations) {
    set<int>temp;
    vector<int>res;
    int n = relations.size();
    unordered_map<int,unordered_set<int>>mp;
    for(auto &r: relations){
        if(mp[r[1]].count(r[0])){
            temp.insert(r[0]);
            temp.insert(r[1]);
        }
        mp[r[0]].insert(r[1]);
    }
    for(auto &i: temp){
        res.push_back(i);
    }
    return res;
}