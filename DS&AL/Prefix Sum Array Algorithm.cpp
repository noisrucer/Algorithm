class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
        int total=0;
        mp[0]++;
        for(int i=1; i<nums.size(); i++)
            nums[i]=nums[i-1]+nums[i];
        
        for(auto i: nums){
            if(mp.count(i-k)){
                total+=mp[i-k];
            }
            mp[i]++;
        }
        return total;
    }
};