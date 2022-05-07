//Iterative Solution 
int solve(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int>visited(n,false);
    int cnt = 0;
    while(k>=0 && k<n){
        if(visited[k]) return -1;
        cnt++;
        visited[k] = true;
        k = nums[k];
    }
    return cnt;

}


//recursive Solution
unordered_set<int>st;

int helper(vector<int>&nums, int index){
    if(index<0 || index>=nums.size()) return st.size();
    if(st.count(index)) return -1;
    
    st.insert(index);
    return helper(nums,nums[index]);
}
int solve(vector<int>& nums, int k) {
    st.clear();
    return helper(nums,k);
}