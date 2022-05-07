class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res=0;
        int dist;
        for(int i=1; i<points.size(); i++){
            int xdiff = abs(points[i][0]-points[i-1][0]);
            int ydiff = abs(points[i][1]-points[i-1][1]);
            res += max(xdiff,ydiff);
        }
        return res;
    }
};