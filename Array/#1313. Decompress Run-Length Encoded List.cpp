class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int i=1;
        vector<int>res;
        for(i; i<nums.size(); i+=2){
            for(int k=0; k<nums[i-1]; k++) res.push_back(nums[i]);
        }
        
        return res;
    }
};