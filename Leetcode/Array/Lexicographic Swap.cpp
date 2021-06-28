string solve(string s) {
    int n = s.length();
    string res = s;
    int pos = n-1;

    for(int i=n-2; i>=0; i--){
        if(s[i] < s[pos]) pos = i;
        else if(s[i] > s[pos]){
            res = s;
            swap(res[i],res[pos]);
        }
    }
    return res;
}


