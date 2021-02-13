bool include(int num){
    int digit;
    while(num>0){
        digit = num%10;
        if(digit==3 || digit==6 || digit==9) return true;
        num/=10;
    }
    return false;
}
vector<string> solve(int n) {
    vector<string>res;
    for(int i=1; i<=n; i++){
        if(i%3==0 || include(i)) res.push_back("clap");
        else res.push_back(to_string(i));
    }
    return res;
}