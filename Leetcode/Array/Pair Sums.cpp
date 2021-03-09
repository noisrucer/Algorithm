int solve(vector<int>& nums) {
    int even = 0, odd = 0;
    int res = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] & 1){
            res += even;
            odd++;
        }
        else{
            res += odd;
            even++;
        }

    }
    return res;
}

