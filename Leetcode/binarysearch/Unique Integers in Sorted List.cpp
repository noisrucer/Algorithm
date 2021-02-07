int next(vector<int> &nums, int start, int target){
    int l = start, r = nums.size() - 1;
    int next;
    int m;
    while(l<=r){
        m = l + (r-l) / 2;
        if(nums[m]==target){
            next = m;
            l = m + 1;
        }
        else if(nums[m]<target){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return next;
}

int solve(vector<int>& nums) {
   int cnt=0, i=0;
   while(i<nums.size()){
       cnt++;
       i = next(nums,i,nums[i]) + 1;
   }
   return cnt;
}
