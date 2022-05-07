unordered_map<int,int>mp;
bool lrsAfterK(vector<int>&nums, int k, int windowSize){
    mp.clear();
    for(int i=0; i<nums.size(); i++){
        if(++mp[nums[i]]+k>=windowSize) return true;
        if(i+1 >= windowSize){
            mp[nums[i-windowSize+1]]--;
        }
    }
    return false;
}

int solve(vector<int>& nums, int k) {
    int l=0, r=nums.size(), window;
    int res = 0;
    while(l<=r){
        window = l + (r-l)/2;
        if(lrsAfterK(nums,k,window)){
            res = max(res,window);
            l = window + 1;
        }else{
            r = window - 1;
        }
    }

    return res;
}