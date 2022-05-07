bool solve(vector<int>& rect1, vector<int>& rect2) {
    if(rect1[0]>=rect2[2] || rect2[0]>=rect1[2] || rect1[1]>=rect2[3] || rect2[1]>=rect1[3]) return false;
    return true;
}