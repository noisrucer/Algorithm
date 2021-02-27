vector<vector<int>> solve(vector<int>& fighters, vector<vector<int>>& bosses) {
    int f = accumulate(fighters.begin(),fighters.end(),0);
    vector<vector<int>>res;
    for(vector<int>&boss: bosses){
        if(f <= accumulate(boss.begin(), boss.end(), 0)) res.push_back(boss);
    }
    return res;
}