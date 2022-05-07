bool solve(string s) {
    int n = s.length();
    unordered_map<int,int>mp;

    for(auto &c: s){
        mp[c]++;
    }

    bool detect_two = false;
    for(auto &p: mp){
        if(!detect_two && p.second%3==2){
            detect_two = true;
            continue;
        }
        if(!detect_two && p.second == 2){
            detect_two = true;
            p.second = 0;
            continue;
        }
        if(p.second%3 != 0) return false;
    }

    return detect_two==false ? false: true;
}