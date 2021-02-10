vector<int> solve(vector<int>& nums) {
   int p = 0;
   for(int i=0; i<nums.size(); i++){
       if(nums[i]!=0){
           swap(nums[i],nums[p++]);
       }
   }
   return nums;
}


