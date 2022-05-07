vector<int> solve(vector<int>& nums) {
    int n = nums.size();
    int i=0, j = nums.size()-1;
    vector<int>res(n);
    int cnt = n-1;
    while(i<=j){
        if(abs(nums[i])>abs(nums[j])){
            res[cnt--] = nums[i]*nums[i];
            i++;
        }
        else{
            res[cnt--] = nums[j]*nums[j];
            j--;
        }
    }
    return res;
}