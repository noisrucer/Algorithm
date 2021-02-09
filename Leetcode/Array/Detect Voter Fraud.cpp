bool solve(vector<vector<int>>& votes) {
    unordered_set<int>st;
    for(auto vote: votes){
        if(st.count(vote[1])) return true;
        st.insert(vote[1]);
    }
    return false;
}