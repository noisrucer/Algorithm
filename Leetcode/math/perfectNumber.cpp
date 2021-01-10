bool solve(int n) {
    if(n<=1) return true;
    int l=0,r=n/2;
    while(l<=r){
        long long m = l + (r-l)/2;
        if(m*m==n) return true;
        else if(m*m>n){
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    return false;
}