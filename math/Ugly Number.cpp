//recursion
bool solve(int n) {
    if(n<1) return false;
    if(n==1) return true;
    if(n%2==0) return solve(n/2);
    if(n%3==0) return solve(n/3);
    if(n%5==0) return solve(n/5);
    return false;
}

//iteration
bool solve(int n) {
    
    while(n > 1){
        if(n%2==0) n/=2;
        if(n%3==0) n/=3;
        if(n%5==0) n/=5;
        if(n!=1 && n%2 && n%3 && n%5) return false;
    }

    return n==1;
}