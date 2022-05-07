int solve(vector<vector<int>>& matrix) {
    int sum = 0;
    int n = matrix.size();
    for(int i=0; i<n; i++){
        sum += matrix[0][i] + matrix[n-1][i] + matrix[n-1-i][i];
    }
    return sum - matrix[0][n-1] - matrix[n-1][0];
}