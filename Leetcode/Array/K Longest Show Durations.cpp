int solve(vector<string>& shows, vector<int>& durations, int k) {
    unordered_map<string,int>mp;
    int n = shows.size();
    for(int i=0; i<n; i++){
        mp[shows[i]]+=durations[i];
    }
    vector<int>temp;
    for(auto &i: mp){
        temp.push_back(i.second);
    }
    sort(temp.begin(), temp.end(), greater<>());
    int res = 0;
    for(int i=0; i<k; i++){
        res+=temp[i];
    }
    return res;
}