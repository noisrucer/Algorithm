vector<vector<int>> solve(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return {};
    nums.push_back(nums[n++-1]+1);
    vector<vector<int>>res;
    vector<int>temp;
    temp.push_back(nums[0]);

    for(int i=1; i<n; i++){
        if(nums[i]==nums[i-1]){
            temp.push_back(nums[i]);
        }else{
            res.push_back(temp);
            temp.clear();
            temp.push_back(nums[i]);
        }
    }
    return res;
}