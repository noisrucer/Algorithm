int solve(vector<int>& nums) {
    int slope = 0;
    int change;
    int cnt = 0;
    for(int i=1; i<nums.size(); i++){
        change = nums[i]-nums[i-1];
        if(change == 0){
            slope = 0;
            continue;
        }

        if(slope==0){
            if(change>0) slope = 1;
            else slope = -1;
        }
        
        else{
            change = change > 0 ? 1 : -1;
            if(change!=slope){
                cnt++;
                slope = change;
            }
        }
    }
    return cnt;
}