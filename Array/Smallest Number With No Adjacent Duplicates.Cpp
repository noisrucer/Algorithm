string solve(string s) {
    s = 'x' + s + 'x';
    int n = s.length();
    for(int i=1; i<n-1; i++){
        if(s[i]!='?') continue;
        if(s[i-1]!='1' && s[i+1]!='1'){
            s[i]='1'; continue;
        }
        if(s[i-1]!='2' && s[i+1]!='2'){
            s[i]='2'; continue;
        }
        if(s[i-1]!='3' && s[i+1]!='3'){
            s[i]='3'; continue;
        }
    }
    return s.substr(1,n-2);

}