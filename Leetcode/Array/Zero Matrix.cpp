vector<vector<int>> solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if(n==0) return matrix;
    int m = matrix[0].size();

    vector<int>row(n,false), col(m,false);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]==0){
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(row[i] || col[j]) matrix[i][j] = 0;
        
    return matrix;
}