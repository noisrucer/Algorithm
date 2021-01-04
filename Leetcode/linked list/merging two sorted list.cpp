vector<int> solve(vector<int>& l1, vector<int>& l2) {
    int n = l1.size(), m = l2.size();
    int i=0, j=0;
    vector<int>res;
    while(i<n || j<m){
        if(i>=n){
            res.push_back(l2[j++]);
            continue;
        }
        if(j>=m){
            res.push_back(l1[i++]);
            continue;
        }
    
        if(l1[i]<=l2[j]) res.push_back(l1[i++]);
        else res.push_back(l2[j++]);
    }
    
    return res;
}