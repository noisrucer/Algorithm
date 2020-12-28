//BFS

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        pair<int,int>res; // (sum,level)
        res.first = INT_MIN;
        queue<TreeNode*>Q;
        Q.push(root);
        int level = 1;
        while(!Q.empty()){
            int size = Q.size();
            int levelSum = 0;
            for(int i=0; i<size; i++){
            auto cur = Q.front(); Q.pop();
                levelSum += cur->val;
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }
           if(levelSum > res.first){
               res.first = levelSum;
               res.second = level;
           }
            level++;
        }
        
        return res.second;
        
    }
};


//BFS + Priority Queue -> no need. just to practice priority queue
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        priority_queue<pair<int,int>, vector<pair<int,int>>>pq;
        queue<TreeNode*>Q;
        Q.push(root);
        int level = 1;
        while(!Q.empty()){
            int size = Q.size();
            int levelSum = 0;
            for(int i=0; i<size; i++){
            auto cur = Q.front(); Q.pop();
                levelSum += cur->val;
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }
            pq.push({levelSum,level++});
        }
        
        auto prev = pq.top();
        while( !pq.empty() && prev.first == pq.top().first){
            prev = pq.top();
            pq.pop();
        }
        
        return prev.second;
        
    }
};