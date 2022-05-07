int solve(string s, int k) {
    unordered_map<char,int>mp;
    priority_queue<int,vector<int>,greater<int>>pq;
    int cnt = 0, res = 0;

    for(char &c: s) mp[c]++;

    for(auto itr: mp){
        cnt++;
        pq.push(itr.second);
    }

    while(cnt>k){
        res+=pq.top();
        pq.pop();
        cnt--;
    }

    return res;
}