class Solution {
public:
    
    int BS(vector<int>&nums, int l, int h){
       int m = (l + h) / 2;
        if(l == h) return nums[l];
        if(nums[l] < nums[h]) return nums[l];
        
        if(nums[m] >= nums[l]) return BS(nums, l+1, h);
        else return BS(nums,l,m);
    }
    
    int findMin(vector<int>& nums) {
        return BS(nums,0,nums.size()-1);
    }
};