int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool isValidCell(vector<vector<int>>&matrix, int i, int j){
    return i>=0 && i<n && j>=0 && j<m && matrix[i][j];
}
int solve(vector<vector<int>>& matrix) {
    n = matrix.size(); m = matrix[0].size();
    int blocks = 0, neighbors = 0;


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0) continue;
            blocks++;

            for(int dir=0; dir<4; dir++){
                neighbors += isValidCell(matrix,i+dx[dir],j+dy[dir]);
            }
        }
    }
    
    return 4 * blocks - neighbors;
}