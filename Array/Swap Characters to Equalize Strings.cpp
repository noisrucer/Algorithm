bool solve(string s, string t) {
    int n = s.length();
    int alpha[26]{0};
    
    for(int i=0; i<n; i++){
        alpha[s[i]-'a']++;
        alpha[t[i]-'a']++;
    }
    
    for(int i=0; i<26; i++){
        if(alpha[i]%2!=0) return false;
    }
    return true;
}
