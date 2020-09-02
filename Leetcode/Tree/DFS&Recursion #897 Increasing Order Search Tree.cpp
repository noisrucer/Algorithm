
class Solution {
public:
   TreeNode* pre=nullptr;
    void search(TreeNode* root){
        if(!root) return;
        search(root->right);
        root->right=pre;
        pre=root;
        TreeNode* tmp = root->left;
        root->left=NULL;
        search(tmp);
    }
  
    TreeNode* increasingBST(TreeNode* root) {
      search(root);
    return pre;
    }
};