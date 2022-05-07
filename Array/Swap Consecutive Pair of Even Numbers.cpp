vector<int> solve(vector<int>& nums) {
    int match = -1;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] & 1) continue;
        if(match!=-1){
            swap(nums[match],nums[i]);
            match = -1;
        }
        else{
            match = i;
        }
    }
    return nums;
}