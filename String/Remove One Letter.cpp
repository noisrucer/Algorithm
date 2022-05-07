bool solve(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    int i=0, j=0;
    bool shot = true;
    while(i<n && j<m){
        if(s1[i]==s2[j]){
            i++; j++;
        }else{
            if(!shot) return false;
            i++; shot=false;
            return s1.substr(i) == s2.substr(j);
        }
    }
    if(i==n-1 && j>=m) return true;
    return false;
}
