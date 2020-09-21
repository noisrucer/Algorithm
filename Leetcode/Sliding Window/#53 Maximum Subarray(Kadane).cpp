class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int max_sum=INT_MIN;
    int current_sum=0;
    for(int i=0; i<nums.size(); i++){
        current_sum+=nums[i];
        if(current_sum<nums[i]){
            current_sum=nums[i];
        }
        max_sum = max(max_sum,current_sum);
    }
        return max_sum;
    }
};