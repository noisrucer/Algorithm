class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int fir=INT_MIN;
        int sec=INT_MIN;
        int res;
        for(int i=0; i<nums.size(); i++){
           if(nums[i]>fir){
               sec=fir;
               fir=nums[i];
               res=i;
               continue;
           }
            if(nums[i]>sec) sec=nums[i];
        }
        return fir>=2*sec ? res : -1;
       
    }
};