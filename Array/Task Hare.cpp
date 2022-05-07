bool comp(int i, int j){
    return i > j;
}
int solve(vector<int>& tasks, vector<int>& people) {
    int n = tasks.size(), m = people.size();
    if(n==0 || m==0) return 0;
    sort(tasks.begin(), tasks.end(), comp);
    sort(people.begin(), people.end(), comp);

    int p = 0, cnt = 0;
    for(int i=0; i<m; i++){
        while(people[i] < tasks[p] && p < n) p++;
        if(p > n-1) return cnt;
        cnt++;
        p++;
    }

    return cnt;

    // tasks:  13 9 3 2
    // people: 10 5 2 1

    
}