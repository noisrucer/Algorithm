bool solve(vector<int>& nums) {
    int first = INT_MIN, second = INT_MIN;
    for(auto num: nums){
        if(num>first){
            second = first;
            first = num; 
        }
        else if(num>second){
            second = num;
        }
        
    }
    return first > 2*second;
}