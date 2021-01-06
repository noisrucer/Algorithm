
vector <int> max_of_subarrays(int *arr, int n, int k){
    deque<int>dq(k);
    vector<int>res;
    int i;
    
    for(int i=0; i<k; ++i){
        while(!dq.empty() && arr[dq.back()]<=arr[i]) dq.pop_back();
        dq.push_back(i);
    }
    
    for(; i<n; i++){
        res.push_back(arr[dq.front()]);
        while(!dq.empty() && dq.front()<=i-k) dq.pop_front();
        while(!dq.empty() && arr[dq.back()]<=arr[i]) dq.pop_back();
        dq.push_back(i);
    }
    
    res.push_back(arr[dq.front()]);
    return res;
    
}