class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<=2) return true;
        int cnt=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<nums[i-1]){
                if(i<2 || nums[i]>=nums[i-2]) nums[i-1]=nums[i];
                else nums[i]=nums[i-1];
                cnt++;
            }
        }
        return cnt<=1;
    }
}; 
 // i j
//5 7 1 8