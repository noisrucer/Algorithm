class Solution {
public:
    int n;
    vector<vector<int>>ans;
    vector<int>res;
    void subset(vector<int> nums, int k){
        if(k==n){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[k]);
        subset(nums,k+1);
        res.pop_back();
        subset(nums,k+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        subset(nums,0);
        return ans;
        
    }
};