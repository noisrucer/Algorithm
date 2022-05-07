class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int,int>mp;
        for(int& num: nums){
            if(mp[num] >= 1){
                res += mp[num];
            }
            mp[num]++;
        }
        
        return res;
    }
};