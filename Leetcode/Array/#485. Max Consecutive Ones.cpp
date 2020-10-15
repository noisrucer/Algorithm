class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=INT_MIN;
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1) res = max(++cnt,res);
            else cnt=0;
        }
        return res==INT_MIN ? 0 : res; 
    }
};