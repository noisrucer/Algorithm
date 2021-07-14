string solve(string s) {
    int n = s.length();
    int prev = 0;
    string res = "";

    for(int i=0; i<n; i++){
        if('a'<=s[i] && s[i]<='z'){
            res += string(stoi(s.substr(prev,i-prev)), s[i]);
            prev = i + 1;
        }
    }
    return res;
}