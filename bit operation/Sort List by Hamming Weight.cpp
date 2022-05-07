int countBits(int x){
    int sum = 0;
    while(x>0){
        sum += (x & 1);
        x >>= 1;
    }
    return sum;
}
static bool compare(int a, int b){
    int bitA = countBits(a), bitB = countBits(b);
    if(bitA < bitB) return true;
    else if(bitA > bitB) return false;
    else return a<b;

}
vector<int> solve(vector<int>& nums) {
    sort(nums.begin(), nums.end(), compare);
    return nums;
    
}