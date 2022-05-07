int solve(string s, int k) {
    unordered_set<int>st;
    for(auto &c: s) st.insert(c);
    int n = st.size();
    k = (k+1)/2;
    return pow(n,k);
}
