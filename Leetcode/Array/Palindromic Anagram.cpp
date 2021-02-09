bool solve(string s) {
    unordered_map<char,int>mp;
    int odd_num = 0;

    for(char c: s){
        if(++mp[c] & 1) odd_num++;
        else odd_num--;
    }
    
    return odd_num <= 1;
}
