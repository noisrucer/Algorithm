int solve(vector<int>& prices) {
    int cur_min = INT_MAX, res = 0;
    for(auto price: prices){
        if(price>cur_min){
            res = max(res, price-cur_min);
        }else{
            cur_min = min(cur_min,price);
        }
    }
    return res;
}