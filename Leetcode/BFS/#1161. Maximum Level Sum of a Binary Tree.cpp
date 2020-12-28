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


//DFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int level){
        if(!root) return;
        mp[level]+=root->val;
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    
    int maxLevelSum(TreeNode* root) {
        dfs(root,1);
        int maxLevel = 1;
        for(auto &p: mp){
            if(p.second > mp[maxLevel]){
                maxLevel = p.first;
            }
        }
        
        return maxLevel;
    }
    
private:
    map<int,int>mp; //level:sum
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