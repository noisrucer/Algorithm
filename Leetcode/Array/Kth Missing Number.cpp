int solve(vector<int>& nums, int k) {
    int n=nums.size(), p=0, cnt=0;
    int num=nums[0];
    while(p<n){
        if(num!=nums[p]){
            if(cnt++ == k) return num;
        }else{
            p++;
        }
        num++; 
    }
    
    return num+k-cnt;
}