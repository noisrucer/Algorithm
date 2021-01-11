class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n),right(n);
        stack<int>limit;
        
        for(int i=0; i<n; i++){
            while(!limit.empty() && heights[limit.top()]>=heights[i]) limit.pop();
            left[i] = limit.empty() ? 0 : limit.top()+1;
            limit.push(i);
        }
        
        while(!limit.empty()) limit.pop();
        
        for(int i=n-1; i>=0; i--){
            while(!limit.empty() && heights[limit.top()]>=heights[i]) limit.pop();
            right[i] = limit.empty() ? n-1 : limit.top()-1;
            limit.push(i);
        }
        
        int max_area=INT_MIN;
        
        for(int i=0; i<n; i++){
            max_area = max(max_area,(right[i]-left[i]+1)*heights[i]);
        }
        
        return max_area;
        
    }
};