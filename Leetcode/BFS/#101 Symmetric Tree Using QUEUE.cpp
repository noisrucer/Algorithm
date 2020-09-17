
class Solution {
public:

    bool isSymmetric(TreeNode* root) {
            
        if(!root) return true;
    queue<pair<TreeNode*,TreeNode*>>Q;
        Q.push({root->left,root->right});
        while(!Q.empty()){
            pair<TreeNode*,TreeNode*>cur = Q.front(); Q.pop();
            if(cur.first==NULL && cur.second==NULL) continue;
            if(cur.first==NULL || cur.second==NULL) return false;
            if(cur.first->val != cur.second->val) return false;
            Q.push({cur.first->left,cur.second->right});
            Q.push({cur.first->right,cur.second->left});
        }
        return true; 
    }
};