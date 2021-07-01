bool solve(string s) {
    int n = s.length();
    string temp;
    bool flag;
    for(int len=1; len<=n/2; len++){
        if(n % len != 0) continue;
        flag = true;
        temp = s.substr(0,len);
        for(int i=0; i<=n-len; i+=len){
            if(s.substr(i,len) != temp){
                flag = false;
                break;
            }
        }
        if(flag) return true;
    }
    return false;
}
