static bool compare(vector<int>a, vector<int>b){
    if(a[0]<b[0]) return true;
    else if(a[0]==b[0]){
        if(a[1]>=b[1]) return true;
        else return false;
    }
    else return false;
}

bool solve(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if(n<=1) return false;
    sort(intervals.begin(), intervals.end(), compare);
    int start = intervals[0][0], end = intervals[0][1];
    vector<int>interval;

    for(int i=1; i<n; i++){
        interval = intervals[i];
        if(start<=interval[0] && interval[1]<=end) return true;
        // if(interval[0]<=start && interval[1]>=end) return true;
        start = interval[0];
        end = interval[1];
    }

    return false;
    
}