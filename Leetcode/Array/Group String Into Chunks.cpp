vector<string> solve(string s, int n) {
    int i = 0;
    vector<string>res;
    while(true){
        if(i+n>=s.length()){
            res.push_back(s.substr(i));
            return res;
        }
        res.push_back(s.substr(i,n));
        i+=n;
    }
    return {};
}