int solve(string s) {
    int cnt = 0;
    for(auto c: s)
        if(c=='a') cnt++;
    return pow(2,cnt);
}