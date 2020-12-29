//Kadane's Algorithm
class Solution {
public:
   
    int minOperations(vector<int>& nums, int x) {
        //longeset subarray with sum total-x
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total<x) return -1;
        int target = total-x, n = nums.size();
        int start=0, current_sum=0, max_len=INT_MIN;
        for(int end=0; end<n; end++){
            current_sum+=nums[end];
            
            while(current_sum>target)
                current_sum-=nums[start++];
            
            if(current_sum==target) 
                max_len = max(max_len, end-start+1);
        }
        
        return max_len==INT_MIN?-1:n-max_len;
    }
};

//Hash map - also find the longest subarray with sum total-x
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(),0) - x;
        if(target==0) return n;
        
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0, min_len=INT_MIN;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(mp.count(sum-target)){
                min_len = max(min_len, i-mp[sum-target]);
            }
            mp[sum]=i;
        }
        return min_len==INT_MIN ? -1 : n-min_len;
    }
};