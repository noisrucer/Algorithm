int happy(int n){
    int sum = 0;
    while(n>0){
        sum += (n%10)*(n%10);
        n/=10;
    }
    return sum;
}
bool solve(int n) {
    unordered_set<int>st;
    while(n!=1){
        if(st.count(n)) return false;
        st.insert(n);
        n = happy(n);
    }
    return true;
}