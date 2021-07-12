bool solve(int n) {
    if(n%10==0) return true;
    while(n>=3){
        if(n%3==0||n%7==0) return true;
        n -= 10;
    }
    return false;
}