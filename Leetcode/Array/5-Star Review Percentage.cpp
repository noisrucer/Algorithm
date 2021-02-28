int solve(vector<vector<int>>& reviews, int threshold) {
    int five = 0;
    int total = 0;
    for(auto &review: reviews){
        five+=review[0];
        total+=review[1];
    }
    
    int res = 0;
    while( ((five+res)*100 / (total+res)) < threshold ){
        res++;
    }
    return res;
}