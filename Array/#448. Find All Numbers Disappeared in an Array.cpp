class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++){
        while(nums[nums[i]-1]!=nums[i]) swap(nums[nums[i]-1],nums[i]);
    }
    vector<int>res;
        for(int i=0; i<nums.size(); i++){
            if(i+1!=nums[i]) res.push_back(i+1);
        }
        return res;
    }
};

//1 2 2 3 3 4 7 8 8