int solve(vector<vector<string>>& matrix, vector<string>& blocks) {
    int n = matrix.size();
    int m = matrix[0].size();
     pair<int,int>cur={0,0};
     unordered_map<string,pair<int,int>>mp;
     for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
             mp[matrix[i][j]]={i,j};
         }
     }

    int res = 0;
     for(auto &block: blocks){
         res += (abs(mp[block].first-cur.first)+abs(mp[block].second-cur.second));
         cur = {mp[block].first,mp[block].second};
     }

     return res;
}