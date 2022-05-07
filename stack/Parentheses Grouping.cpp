vector<string> solve(string s) {
    vector<string>res;
    int stack = 0;
    string partials = "";
    for(char &c: s){
        partials += c;
        if(c=='(') stack++;
        else{
            if(--stack==0){
                res.push_back(partials);
                partials = "";
            }
        }
    }
    return res;
}