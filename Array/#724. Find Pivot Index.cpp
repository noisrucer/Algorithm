class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return -1;
        vector<int>prefix;
        int sum=0;
        for(auto i: nums){
            sum+=i;
            prefix.push_back(sum);
        }
        
        for(int i=0; i<n; i++){
            if(i==0 && prefix[n-1]-prefix[i]==0) return i;
            if(i==n-1 && prefix[n-2]==0) return i;
            if(i>0 && i<n-1 && prefix[i-1]==prefix[n-1]-prefix[i]) return i;
        }
        
        return -1;
        
    }
};