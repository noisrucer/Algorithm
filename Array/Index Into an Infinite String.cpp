string solve(string s, int i, int j) {
    int n = s.length();
    string res="";
    while(i<j){
        res += s[i++ % n];
    }

    return res;
}
