class RangeSum {
    public:
    vector<int>prefix;

    RangeSum(vector<int>& nums) {
        int prev = 0;
        for(int i=0; i<nums.size(); i++){
            prev+=nums[i];
            prefix.push_back(prev);
        }
    }

    int total(int i, int j) {
        return prefix[j-1]-(i==0?0:prefix[i-1]);
    }
};