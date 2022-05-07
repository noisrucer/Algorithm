int solve(string s, string t) {
    int n = s.length(), m = t.length();
    if(!n || !m || n<m) return 0;
    int res = INT_MAX;
    int temp = 0;

    for(int i=0; i<n-m+1 ; i++){
        for(int j=i; j<i+m; j++) temp += (s[j]==t[j-i]);
        res = min(res, m-temp);
        temp = 0;
    }

    return res;
}


