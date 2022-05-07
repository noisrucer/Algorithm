int solve(string s) {
    s += (char)(s[s.length()-1]-1);
    int res = 0;
    int n = s.length();
    int cnt = 1;
    
    for(int i=1; i<n; i++){
        if(s[i]!=s[i-1]){
            res += cnt*(cnt+1)/2;
            cnt = 1;
        }else{
            cnt++;
        }
    }
    return res;
}

