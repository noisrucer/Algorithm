class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0];
        int max_sum=0;
       for(int i=0; i<k; i++)
        max_sum+=nums[i];
        int i=0; int j = k-1;
        int current_sum=max_sum;
        while(j<nums.size()){
            max_sum=max(max_sum,current_sum);
            current_sum-=nums[i++];
            current_sum+=nums[++j];
        }
        return (double)max_sum/k;
        
        /* Prefix sum
        int n = nums.size();
        vector<int>prefix(n+1,0);
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            prefix[i+1]=sum;
        }
        int max_average=INT_MIN;
        for(int i=k; i<prefix.size(); i++){
            max_average=max(max_average,prefix[i]-prefix[i-k]);
        }
        
        return (double)max_average/k;
        */
        
    }
};