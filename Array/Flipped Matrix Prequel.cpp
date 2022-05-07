int solve(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int>row(n), col(m);
    int totalOnes = 0;
    int res = INT_MIN;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            totalOnes += (matrix[i][j]==1);
            row[i] += (matrix[i][j]==0);
            col[j] += (matrix[i][j]==0);
        }
    }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            res = max(res, 2*row[i] + 2*col[j] + (matrix[i][j] == 1 ? 2 : -2));
        
    
    
    return res + totalOnes - n - m;
}