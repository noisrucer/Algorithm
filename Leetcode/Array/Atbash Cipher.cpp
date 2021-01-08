string solve(string text) {
    for(auto &c: text){
        c = 'z'+'a'-c;
    }
    return text;
}