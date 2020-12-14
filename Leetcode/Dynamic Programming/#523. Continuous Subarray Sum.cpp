class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        bool zero=false;
            for(int i=0; i<nums.size()-1; i++){
                int j = i+1;
                if(nums[i]+nums[j]==0){
                    zero=true;
                    return true;
                }
            }
        if(k==0){
            if(zero) return true;
            else return false;
        }
            
        
        if(nums.size()==1) return false;
        unordered_set<int>st;
        int pre;
        int sum=0;
        int mod;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) continue;
            sum+=nums[i];
            if(i!=0 && sum%k==0) return true;
            mod=sum%k;
            if(st.count(mod) && mod!=pre) return true;
            st.insert(mod);
            pre = mod;
            
        }
        return false;
    }
};