vector<int>bitNum(int n){
    vector<int>res;
    while(n>0){
        res.push_back(n%2);
        n/=2;
    }
    reverse(res.begin(), res.end());
    return res;
}
int solve(int n) {
    int max_len = 0, cnt=0;
    vector<int>bits = bitNum(n);
    for(int i=0; i<bits.size(); i++){
        if(bits[i]==0){
            max_len = max(max_len, cnt);
            cnt = 0;
        }else{
            cnt++;
        }
    }
    max_len = max(max_len, cnt);
    return max_len;
}
