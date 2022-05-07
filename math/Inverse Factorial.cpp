int solve(int a) {
    int fact = 1, cnt = 1;
    while(fact<=a){
        if(fact == a) return cnt;
        fact *= ++cnt;
    }
    return -1;
}