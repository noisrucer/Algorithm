class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n==0) return {};
        int max_length=INT_MIN;
        vector<int>max_set; max_set.push_back(nums[0]);
        vector<int>dp_size(n,1);
        vector<vector<int>>dp_set(n);
        
        for(int i=0; i<nums.size(); i++)
            dp_set[i].push_back(nums[i]);
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0){
                    if(dp_size[j]+1>dp_size[i]){
                        dp_size[i]=dp_size[j]+1;
                        dp_set[i]=dp_set[j];
                        dp_set[i].push_back(nums[i]);
                        if(dp_size[i]>max_length){
                            max_length=dp_size[i];
                            max_set = dp_set[i];
                        }
                    }
                }
            }
        }
        
        return max_set;
    }
};