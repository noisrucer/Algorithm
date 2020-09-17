#include <algorithm>

class Solution {
public:

  
    
    void postorder(TreeNode* root,vector<int>&v){
        if(!root) return;
        if(!root->left && !root->right){
            v.push_back(root->val);
        }
        postorder(root->left,v);
        postorder(root->right,v);
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2;
        postorder(root1,v1);
        postorder(root2,v2);
       if(v1==v2)return true;
        else return false;
    }
};