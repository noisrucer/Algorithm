
class Solution {
public:
    
    int depth(TreeNode* root){
        if(!root) return -1;
        return max(depth(root->left),depth(root->right))+1;
    }
   
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        if(abs(depth(root->left) - depth(root->right))>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};