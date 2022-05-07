string solve(string s) {
    string res="";
    s.push_back('5');
    int n = s.length();
    int cnt = 1;
    for(int i=1; i<n; i++){
        if(s[i]!=s[i-1]){
            res += to_string(cnt);
            res += s[i-1];
            cnt=1;
        }else{
            cnt++;
        }
    }
    return res;
}