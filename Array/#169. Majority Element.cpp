// Moore's voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int majority = nums.size()/2;
        unordered_map<int,int>mp;
        for(auto i: nums){
            mp[i]++;
            if(mp[i]>majority) return i;
        }
        return 0;
    }
};
