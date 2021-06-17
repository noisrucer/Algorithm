int solve(int n) {
    int res = 0;
    while(n>=3){
        res += (n/3)*3;
        n = n/3 + n%3;
    }
    return res+n; 
    
}


