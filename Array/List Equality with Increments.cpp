int solve(vector<int>& nums) {
    int minVal = INT_MAX;
    for (int a : nums)
    {
        minVal = min(a, minVal);
    }
    int count = 0;
    int diff = 0;
    for (int i : nums)
    {
        diff = i - minVal;
        count += diff;
    }
    return count;
}