bool solve(string s, int k) {
    int n = s.length();
    vector<int>pos;
    for(int i=0; i<n; i++) if(s[i]=='x') pos.push_back(i);
    int m = pos.size();

    int flag = -1;
    for(int i=0; i<n; i++){
        if(s[i]=='x'){
            flag++;
            continue;
        }
        if(min(flag>=0 ? abs(pos[flag]-i) : INT_MAX, flag+1<m ? abs(pos[flag+1]-i) : INT_MAX) >= k) return true;
    }

    return false;
}
