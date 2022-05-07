int solve(string animals, string dinosaurs) {
    int cnt = 0;
    unordered_set<char>st;
    for(auto c: dinosaurs)
        st.insert(c);
    for(auto c: animals)
        if(st.count(c)) cnt++; 
    return cnt;
}