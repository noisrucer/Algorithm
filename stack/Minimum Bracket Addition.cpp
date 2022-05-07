int solve(string s) {
    int n = s.length();
    int left = 0, cnt = 0;
    for(char &c: s){
        if(c=='(') left++;
        else{
            if(left>0){
                left--;
                cnt+=2;
            }
        }
    }
    return n - cnt;
}