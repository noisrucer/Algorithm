class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int start=0;
        int min_length=INT_MAX;
        int current_sum=0;
        
        for(int end=0; end<nums.size(); end++){
            current_sum+=nums[end];
            while(current_sum>=s){
                min_length=min(min_length,end-start+1);
                current_sum-=nums[start++];
            }
            
        }
        return min_length==INT_MAX ? 0 : min_length;
    }
};