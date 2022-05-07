class Solution {
public:
    double slope(int x1, int y1, int x2, int y2){
        if(x2-x1==0) return INT_MAX;
        return (double)(y2-y1)/(x2-x1);
    }
    bool checkStraightLine(vector<vector<int>>& coor) {
        double s = slope(coor[0][0],coor[0][1],coor[1][0],coor[1][1]);
       for(int i=1; i<coor.size(); i++){
           if(slope(coor[i-1][0],coor[i-1][1],coor[i][0],coor[i][1])!=s) return false;
       }
      
        return true;
    }
};