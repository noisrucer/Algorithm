int solve(string s) {
    int st[26]{};
    for(int i=0; i<s.length(); i++){
        if(st[s[i]-'a']++>0) return i;
    }
    return -1;
}