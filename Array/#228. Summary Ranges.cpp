class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int cnt=0, n = nums.size();
        if(nums.size()==0) return {};
        nums.push_back(nums[nums.size()-1]-2);
        vector<string> res; n++;
      
        for(int i=0; i<n-1; i++){
            if(nums[i]!=nums[i+1]-1){
                if(nums[i]==nums[i-cnt]) res.push_back(to_string(nums[i]));
                else res.push_back(to_string(nums[i-cnt])+"->"+to_string(nums[i]));
                cnt=0; continue;
            }
            cnt++;
        }
        
        return res;
    }
};