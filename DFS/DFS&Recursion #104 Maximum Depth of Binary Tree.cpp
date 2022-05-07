class Solution {
public:
    int depth(TreeNode* root){
        if(root==NULL) return 0;
        return max(depth(root->left),depth(root->right))+1;
            }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
      return depth(root);
        
    }
};