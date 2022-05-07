int GCD(int a, int b){
    if(b==0) return a;
    return GCD(b,a%b);
}
int solve(vector<int>& nums) {
    int gcd = nums[0];
    for(int num: nums){
        gcd = GCD(gcd,num); 
    }
    return gcd;

}