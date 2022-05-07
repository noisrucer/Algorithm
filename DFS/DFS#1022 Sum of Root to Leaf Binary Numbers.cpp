
class Solution {
public:
    int tot=0;
    void func(TreeNode* root, int sum){
    if(!root)return;
    sum += root->val;
    if(!root->left && !root->right){
            tot+=sum;
            return;
        }
    
    func(root->left, sum*2);
    func(root->right,sum*2);
        
    }
    int sumRootToLeaf(TreeNode* root) {
        
        func(root,0);
        return tot;
    }
};
    