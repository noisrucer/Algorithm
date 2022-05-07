int solve(vector<int>& nums) {
    int cnt=0;
    int i=0, n = nums.size();
    bool status = 1;
    while(i<n){
        if(status==1){
            if(nums[i++]==1){
                cnt++;
                status = 0;
            }
        }else{
            if(nums[i++]==0){
                cnt++;
                status=1;
            }
        }
    }
    return cnt;
}